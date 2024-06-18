#pragma once

template<class TypeArr, class TypeLen>
void iter(TypeArr *arr, TypeLen len, void function(TypeArr))
{
    for (TypeLen iteration = 0; iteration < len; iteration++)
        function(arr[iteration]);
}
