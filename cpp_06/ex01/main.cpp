#include <iostream>
#include <cstdlib>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    t_data data;

    data.str_example = "test";

    uintptr_t serialized = Serializer::serialize(&data);

    std::cout << "Original Data Address: " << &data << std::endl;
    std::cout << "Original Data str_example: " << data.str_example << std::endl;
    std::cout << "Serialized Data: " << serialized << std::endl;

    t_data* deserialized = Serializer::deserialize(serialized);

    std::cout << "Deserialized Data Address: " << deserialized << std::endl;
    std::cout << "Deserialized Data str_example: " << deserialized->str_example << std::endl;

    return 0;
}
