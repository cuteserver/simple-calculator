//
// Copyright (c) 2022 Glauco Pacheco <glauco@cuteserver.io>
// All rights reserved
//

#include "Calculator.h"

REGISTER_REMOTE_OBJECT("/calculator", Cute::Tests::Calculator);


namespace Cute::Tests
{

qint32 Calculator::addIntegers(qint32 a, qint32 b)
{
    qWarning("Requester info: IP:%s, Port:%d.",
             m_connectionInformation->peerIp().toUtf8().constData(),
             m_connectionInformation->peerPort());
    emit addedIntegers(Integer(a), Integer(b), Integer(a+b));
    return a+b;
}

}
