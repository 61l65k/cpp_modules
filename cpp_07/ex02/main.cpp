#include "Array.hpp"

int main()
{
    try {
        // Test default constructor
        Array<int> array1;
        std::cout << "array1 size: " << array1.size() << std::endl;

        // Test constructor with size
        Array<int> array2(5);
        std::cout << "array2 size: " << array2.size() << std::endl;

        for (unsigned int i = 0; i < array2.size(); ++i) {
            array2[i] = i * 2;
        }

        // Test copy constructor
        Array<int> array3(array2);
        std::cout << "array3 size: " << array3.size() << std::endl;

        // Modify array3 and show it doesn't affect array2
        for (unsigned int i = 0; i < array3.size(); ++i)
            array3[i] = i * 3;

        std::cout << "array2 elements: ";
        for (unsigned int i = 0; i < array2.size(); ++i)
            std::cout << array2[i] << " ";
        std::cout << std::endl;

        std::cout << "array3 elements: ";
        for (unsigned int i = 0; i < array3.size(); ++i)
            std::cout << array3[i] << " ";
        std::cout << std::endl;

        // Test assignment operator
        Array<int> array4;
        array4 = array2;
        std::cout << "array4 size: " << array4.size() << std::endl;

        std::cout << "array4 elements: ";
        for (unsigned int i = 0; i < array4.size(); ++i)
            std::cout << array4[i] << " ";
        std::cout << std::endl;

        // Test out-of-bounds access
        try
        {
            array2[10] = 100;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
