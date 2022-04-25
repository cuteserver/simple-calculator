//
// Copyright (c) 2022 Glauco Pacheco <glauco@cuteserver.io>
// All rights reserved
//

#ifndef CUTE_TESTS_INTEGER_H
#define CUTE_TESTS_INTEGER_H

#if defined(SERVER_SIDE)
#include <CuteServer.h>
#elif defined(CLIENT_SIDE)
#include <CuteClient.h>
#endif

#include <QMetaType>


namespace Cute::Tests
{

class Integer
{
public:
    Integer();
    explicit Integer(const qint32 &value);
    Integer(const Integer &other);
    ~Integer() = default;
    Integer &operator=(const Integer &other);
    void setValue(const qint32 &value) {m_value = value;}
    [[nodiscard]] qint32 value() const {return m_value;}

private:
    qint32 m_value = 0;
    static int m_metaTypeId;
};

DataStream &operator<<(DataStream &stream, const Integer &i);
DataStream &operator>>(DataStream &stream, Integer &i);

}

Q_DECLARE_METATYPE(Cute::Tests::Integer)

#endif // CUTE_TESTS_INTEGER_H
