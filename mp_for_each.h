#pragma once

#include "mp_adv.h"

//primary way
template<class Func, class... T>
constexpr Func mp_for_each_1(Func&& lambda, std::tuple<T...>& vectors) noexcept
{
    using A = int[sizeof...(T)];
    return (void)A{((void)lambda(std::get<T>(vectors)), 0)...}, std::forward<Func>(lambda);
}

//secondary way
template<class Func, class... T>
constexpr void mp_for_each_2(Func&& lambda, std::tuple<T...>& vectors) noexcept
{
    (void)std::initializer_list<int>(((void)lambda(std::get<T>(vectors)), 0)...);
}


