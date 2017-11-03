#ifndef LIBS_COMMON_H
#define LIBS_COMMON_H

template<typename T>
struct property {
    typedef T type;

    template<typename TG, TG type::*TM>
    static TG get(type const *R)
    { return R->*TM;
    }

    template<typename TS, TS T::*TM>
    static void set(type *R, TS V)
    { R->*TM = V;
    }
};

#endif // LIBS_COMMON_H
