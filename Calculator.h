//
// Copyright (c) 2022 Glauco Pacheco <glauco@cuteserver.io>
// All rights reserved
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Integer.h"
#include <CuteServer.h>
#include <QSharedPointer>

class Calculator : public QObject
{
Q_OBJECT
public:
    explicit Calculator(QSharedPointer<Cute::IConnectionInformation> ci)
    {Q_UNUSED(ci)}
    ~Calculator() override = default;

public slots:
    REMOTE_SLOT qint32 addIntegers(qint32 a, qint32 b);

signals:
    REMOTE_SIGNAL void overflow(Integer a, Integer b);
};

#endif // CALCULATOR_H
