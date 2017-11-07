#ifndef TABLE_H
#define TABLE_H

#include <string>

struct Table0 {
    Table0()
        : m_str("Hello, world!")
        , m_int(0)
        , m_bool(false)
    {}

    Table0(Table0 &&) = delete;
    Table0(Table0 &) = delete;

    std::string m_str;
    int m_int;
    bool m_bool;
};

struct Table1 {
    Table1() : nested()
    {}

    Table1(Table1 &&) = delete;
    Table1(Table1 &) = delete;

    Table0 nested;

    const Table0 &get() const
    { return nested;
    }

    Table0 &get()
    { return nested;
    }
};

#endif//TABLE_H
