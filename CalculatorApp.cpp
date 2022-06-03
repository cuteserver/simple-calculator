//
// Copyright (c) 2022 Glauco Pacheco <glauco@cuteserver.io>
// All rights reserved
//

#include "CalculatorClient.h"
#include <QCoreApplication>

void fetchArgs(qint32 &a, qint32 &b);

int main(int argc, char ** argv)
{
    QCoreApplication app(argc, argv);
    qint32 a = 0, b = 0;
    fetchArgs(a,b);
    CalculatorClient calculatorClient(a,b);
    return QCoreApplication::exec();
}

void fetchArgs(qint32 &a, qint32 &b)
{
    const auto args = QCoreApplication::arguments();
    bool foundA = false, foundB = false;
    for (const auto &arg : args)
    {
        if (arg.startsWith("a="))
        {
            bool convertedSuccessfully = false;
            a = arg.mid(2).toInt(&convertedSuccessfully);
            if (!convertedSuccessfully)
                qFatal("Integer a is invalid.");
            foundA = true;
        }
        else if (arg.startsWith("b="))
        {
            bool convertedSuccessfully = false;
            b = arg.mid(2).toInt(&convertedSuccessfully);
            if (!convertedSuccessfully)
                qFatal("Integer b is invalid.");
            foundB = true;
        }
    }
    if (!foundA || !foundB)
        qFatal("Integers a and/or b were not specified on the command-line.");
}
