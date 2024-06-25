#pragma once

#include <iostream>

template <typename T, typename I, typename Func>
void iter(T *tab, I len, Func ft)
{
    for (I i = 0; i < len; i++)
        ft(tab[i]);
}