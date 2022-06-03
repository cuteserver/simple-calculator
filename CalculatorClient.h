//
// Copyright (c) 2022 Glauco Pacheco <glauco@cuteserver.io>
// All rights reserved
//

#ifndef CALCULATOR_CLIENT_H
#define CALCULATOR_CLIENT_H

#include "Integer.h"
#include <CuteClient.h>
#include <QCoreApplication>

using namespace Cute::Client;

class CalculatorClient : public QObject
{
Q_OBJECT
public:
    CalculatorClient(qint32 a, qint32 b)
            : m_calculator("Calculator",
                           QUrl("cute://127.0.100.125:1234/calculator"))
    {
        // Establish remote signal-slot connection
        RemoteObject::connect(&m_calculator,
                              SIGNAL(overflow(Integer,Integer)),
                              this,
                              SLOT(onOverflow(Integer,Integer)));
        // Call the remote slot directly
        m_slotResponse = m_calculator.callRemoteSlot("addIntegers", a, b);
        QObject::connect(m_slotResponse.data(),
                         &IRemoteSlotResponse::responded,
                         [](const QVariant &response) {
                             qWarning("Sum is %d.", response.value<qint32>());
                             QCoreApplication::quit();});
    }

public slots:
    // Remote signal-slot connections require public slots.
    void onOverflow(const Integer &a, const Integer &b)
    {
        qWarning("Adding %d to %d overflows.", a.value(), b.value());
    }

private:
    RemoteObject m_calculator;
    QSharedPointer<IRemoteSlotResponse> m_slotResponse;
};


#endif // CALCULATOR_CLIENT_H
