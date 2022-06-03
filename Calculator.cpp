//
// Copyright (c) 2022 Glauco Pacheco <glauco@cuteserver.io>
// All rights reserved
//

#include "Calculator.h"

REGISTER_REMOTE_OBJECT("/calculator", Calculator);


qint32 Calculator::addIntegers(qint32 a, qint32 b)
{
    if ((a > 0 && b > 0 && (a+b) < 0)
        || (a < 0 && b < 0 && (a+b) > 0))
    {
        emit overflow(Integer(a), Integer(b));
        return -1;
    }
    else
        return a+b;
}
