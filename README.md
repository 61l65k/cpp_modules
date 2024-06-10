# Introduction to C++

##
## Overview
This course is designed to introduce you to the C++ programming language. Throughout this course, you'll learn about C++ syntax, new keywords, classes, and their relationship with structs, as well as the implementation of methods.

## Course Objectives
- Grasp the basic syntax of C++.
- Comprehend the use of new keywords.
- Understand the structure and usage of classes.
- Learn how classes are related to and differ from structs.
- Explore how methods are defined and used within classes.

## Key Concepts

### Basic Syntax and Keywords
C++ syntax is the set of rules that defines the combinations of symbols that are considered to be correctly structured programs in the language. Keywords are reserved words that have special meanings and uses.

### Classes and Objects
Classes are user-defined types that contain variables and functions. Objects are instances of classes.

Class example:
```cpp
class Car {
    std::string brand;
    int year;

public:
    Car(std::string x, int y) : brand(x), year(y) {}

    void displayInfo() const {
        std::cout << "Car brand: " << brand << " - Year: " << year << std::endl;
    }
};
```

### Structs vs Classes
Structs and classes are fundamentally similar in C++, but they differ primarily in their default access control. Struct members are public by default, making them a good choice for passive data structures. In contrast, class members are private by default, enforcing encapsulation.

Struct example:
```cpp
struct Point {
    int x;
    int y;
};
```
### Methods
Methods are member functions of a class or struct that operate on its data members. In classes, they can be defined to perform tasks like calculations or modify the object's state.

Method example:
```cpp
Copy code
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
};
```

### Exercises
As part of this course, you'll engage in hands-on exercises designed to reinforce the concepts you've learned. You'll create classes, define methods, and learn to manage memory and resources effectively.

### Conclusion
Upon completion of this course, you will have a strong foundation in the basics of C++. You'll be prepared to tackle more advanced topics in programming and develop complex C++ applications.

Good luck, and enjoy your journey into the world of C++ programming!
