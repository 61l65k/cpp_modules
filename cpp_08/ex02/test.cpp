#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

int main()
{
    std::deque<int> myVector;
    
    // Add some elements to the vector
    for (int i = 0; i < 35; ++i) {
        myVector.push_back(i);
        std::cout << "Size: " << myVector.size() << ", Capacity: " << myVector.size() << std::endl;
    }

    return 0;
}
