#pragma once

////////////////////////////////////////
// type list
template<class...>
struct mp_list{};

///////////////////////////////////////
// bool
template<bool B>
struct mp_bool
{
    static const bool value = std::integral_constant<bool, B>::value;
};

///////////////////////////////////////
// not
template<bool B>
struct mp_not
{
    static const bool value = !B;
};

///////////////////////////////////////
// convert a size_t to a bool
template<size_t T>
struct mp_to_bool
{
    static const bool value = static_cast<bool>(T);
};

///////////////////////////////////////
// is same
template<class A, class B>
struct mp_is_same
{
    static const bool value = false;
};

template<class A>
struct mp_is_same<A, A>
{
    static const bool value = true;
};

///////////////////////////////////////
//add values...
constexpr size_t mp_get_sum()
{
    return 0;
}

template<class V1, class... V>
constexpr size_t mp_get_sum(V1 v1, V... v)
{
    return v1 + mp_get_sum(v...);
}

//////////////////////////////////////
// get count of type in type list
template<class V, class L>
struct mp_count;

template<class V, template<class...> class L, class... T>
struct mp_count<V, L<T...>>
{
    static const size_t value = mp_get_sum(mp_is_same<V, T>::value...);
};

//////////////////////////////////////
// whether or not the type list contains the type
template<class V, class L>
struct mp_contains;

template<class V, template<class...> class L, class... T>
struct mp_contains<V, L<T...>>
{
    static const bool value = mp_to_bool<(mp_count<V, L<T...> >::value)>::value;
};

////////////////////////////////////////
// size of type-list
template<class L>
struct mp_size;

template<template<class...> class L, class... T>
struct mp_size<L<T...>>
{
    static const size_t value = sizeof...(T);
};

////////////////////////////////////////
// index_of helper
template<size_t N, class V, class L>
struct mp_index_of_impl;

template<size_t N, class V, template<class...> class L>
struct mp_index_of_impl<N, V, L<>>
{
    static const size_t value = N;
};

template<size_t N, class V, template<class...> class L, class T1, class... T>
struct mp_index_of_impl<N, V, L<T1, T...>>
{
    static const size_t value = (mp_is_same<V, T1>::value) ? N : mp_index_of_impl<N+1, V, L<T...>>::value;
};

////////////////////////////////////////
// index_of
template<class V, class L>
struct mp_index_of;

template<class V, template<class...> class L, class T1, class... T>
struct mp_index_of<V, L<T1, T...>>
{
    //static_assert(mp_count<V, L<T1, T...>>::value == 1, "There must be exactly one of the type in the type list");

    static const size_t value = (mp_is_same<V, T1>::value) ? 0 : mp_index_of_impl<1, V, L<T...>>::value;
};










