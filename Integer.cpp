//
// Copyright (c) 2022 Glauco Pacheco <glauco@cuteserver.io>
// All rights reserved
//

#include "Integer.h"

int Cute::Tests::Integer::m_metaTypeId = Cute::registerType<Cute::Tests::Integer>();

namespace Cute::Tests
{

Integer::Integer()
{
    if (m_metaTypeId <= 0)
        qFatal("Failed to register custom Qt type.");
}

Integer::Integer(const qint32 &value)
        : m_value(value)
{
    if (m_metaTypeId <= 0)
        qFatal("Failed to register custom Qt type.");
}

Integer::Integer(const Integer &other)
{
    *this = other;
}

Integer &Integer::operator=(const Integer &other)
{
    if (this == &other)
        return *this;
    m_value = other.m_value;
    return *this;
}

DataStream &operator<<(DataStream &stream, const Integer &i)
{
    stream << i.value();
    return stream;
}

DataStream &operator>>(DataStream &stream, Integer &i)
{
    qint32 readValue;
    stream >> readValue;
    i = Integer(readValue);
    return stream;
}

}
