//
// Copyright (c) 2022 Glauco Pacheco <glauco@cuteserver.io>
// All rights reserved
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Integer.h"
#include <CuteServer.h>
#include <QSharedPointer>

namespace Cute::Tests
{

class Calculator : public QObject
{
Q_OBJECT
public:
    explicit Calculator(QSharedPointer<Cute::IConnectionInformation> connectionInformation)
        : m_connectionInformation(connectionInformation) {}
    ~Calculator() override = default;

public slots:
    REMOTE_SLOT qint32 addIntegers(qint32 a, qint32 b);

signals:
    REMOTE_SIGNAL void addedIntegers(Cute::Tests::Integer a, Cute::Tests::Integer b, Cute::Tests::Integer sum);
    
private:
    QSharedPointer<Cute::IConnectionInformation> m_connectionInformation;
};

}

#endif // CALCULATOR_H
