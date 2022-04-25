//
// Copyright (c) 2022 Glauco Pacheco <glauco@cuteserver.io>
// All rights reserved
//

#ifndef CALCULATOR_CLIENT_H
#define CALCULATOR_CLIENT_H

#include "Integer.h"
#include <CuteClient.h>

namespace Cute::Tests
{

class CalculatorClient : public QObject
{
Q_OBJECT
public:
    CalculatorClient() = default;
    ~CalculatorClient() override = default;
    
public slots:
    void onAddedIntegers(Cute::Tests::Integer a, Cute::Tests::Integer b, Cute::Tests::Integer sum)
    {
        qWarning("CalculatorClient::onAddedIntegers called with (%d,%d,%d).", a.value(), b.value(), sum.value());
    }
};

}

#endif // CALCULATOR_CLIENT_H
