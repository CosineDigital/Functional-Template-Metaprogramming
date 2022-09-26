#pragma once

#include "mp_basics.h"

////////////////////////////////////////
// append types to the front
template<class L, class... V>
struct mp_push_front;

template<template<class...> class L, class... T, class... V>
struct mp_push_front<L<T...>, V...>
{
    using type = L<V..., T...>;
};

///////////////////////////////////////
// remove type from front of type-list
template<class L>
struct mp_pop_front;

template<template<class...> class L, class T1, class... T>
struct mp_pop_front<L<T1, T...>>
{
    using type = L<T...>;
};

///////////////////////////////////////
// access type from front of type-list
template<class L>
struct mp_front;

template<template<class...> class L, class T1, class... T>
struct mp_front<L<T1, T...>>
{
    using type = T1;
};

////////////////////////////////////////
// append types to the back
template<class L, class... V>
struct mp_push_back;

template<template<class...> class L, class... T, class... V>
struct mp_push_back<L<T...>, V...>
{
    using value = L<T..., V...>;
};

///////////////////////////////////////
// access type at back
template<class...>
struct mp_back_impl;

template<class T1>
struct mp_back_impl<T1>
{
    using type = T1;
};

template<class T1, class T2>
struct mp_back_impl<T1, T2>
{
    using type = T2;
};

template<class T1, class T2, class T3>
struct mp_back_impl<T1, T2, T3>
{
    using type = T3;
};

template<class T1, class T2, class T3, class T4>
struct mp_back_impl<T1, T2, T3, T4>
{
    using type = T4;
};

template<class T1, class T2, class T3, class T4, class T5>
struct mp_back_impl<T1, T2, T3, T4, T5>
{
    using type = T5;
};

template<class T1, class T2, class T3, class T4, class T5, class T6>
struct mp_back_impl<T1, T2, T3, T4, T5, T6>
{
    using type = T6;
};

template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
struct mp_back_impl<T1, T2, T3, T4, T5, T6, T7>
{
    using type = T7;
};

template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
struct mp_back_impl<T1, T2, T3, T4, T5, T6, T7, T8>
{
    using type = T8;
};

template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
struct mp_back_impl<T1, T2, T3, T4, T5, T6, T7, T8, T9>
{
    using type = T9;
};

template<class T1, class T2, class T3, class T4, class T5, class T6,  class T7, class T8, class T9, class T10>
struct mp_back_impl<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>
{
    using type = T10;
};

template<class T1, class T2, class T3, class T4, class T5, class T6,  class T7, class T8, class T9, class T10, class... T>
struct mp_back_impl<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T...>
{
    using type = typename mp_back_impl<T...>::type;
};

template<class L>
struct mp_back;

template<template<class...> class L, class... T>
struct mp_back<L<T...>>
{
    using type = typename mp_back_impl<T...>::type;
};

////////////////////////////////////////
// repeat, create a list of a type [N] number of times
template<class V, size_t N, template<class...> class L>
struct mp_repeat
{
    using type = typename mp_push_back<typename mp_repeat<V, N-1, L>::type, V>::type;
};

template<class V, template<class...> class L>
struct mp_repeat<V, 0, L>
{
    using type = L<>;
};
