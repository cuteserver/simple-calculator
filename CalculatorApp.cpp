//
// Copyright (c) 2022 Glauco Pacheco <glauco@cuteserver.io>
// All rights reserved
//

#include <CuteClient.h>
#include "Integer.h"
#include "CalculatorClient.h"
#include <QCoreApplication>

using namespace Cute::Client;
using namespace Cute::Tests;

int main(int argc, char ** argv)
{
    QCoreApplication app(argc, argv);
    RemoteObject calculator("Cute::Tests::Calculator", QUrl("cute://127.100.200.125:2208/calculator"));
    QObject::connect(&calculator, &RemoteObject::connected, [](){qWarning("RemoteObject connected.");});
    QObject::connect(&calculator, &RemoteObject::error, [](){qFatal("RemoteObject connection failed.");});
    CalculatorClient calculatorClient;
    auto connection = RemoteObject::connect(&calculator,
                                            SIGNAL(addedIntegers(Cute::Tests::Integer,Cute::Tests::Integer,Cute::Tests::Integer)),
                                            &calculatorClient,
                                            SLOT(onAddedIntegers(Cute::Tests::Integer,Cute::Tests::Integer,Cute::Tests::Integer)));
    // Note that we call the remote slot after the connection to the remote signal has been established
    // to ensure that our local slot will be called when the remote signal get emitted due to the remote slot call.
    QSharedPointer<IRemoteSlotResponse> slotResponse;
    QObject::connect(connection.data(), &IRemoteObjectConnection::connected, [&slotResponse, &calculator]()
    {
        slotResponse = calculator.callRemoteSlot("addIntegers", 3, 5);
        QObject::connect(slotResponse.data(), &IRemoteSlotResponse::responded, [](const QVariant &response)
        {
            qWarning("Received remote slot response. Sum is: %d", response.value<qint32>());
            QCoreApplication::quit();
        });
        QObject::connect(slotResponse.data(), &IRemoteSlotResponse::failed, [](){qFatal("Remote slot call failed.");});
    });
    QObject::connect(connection.data(), &IRemoteObjectConnection::failed, [](){qFatal("Remote object connection failed.");});
    return QCoreApplication::exec();
}
