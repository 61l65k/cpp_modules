# Introduction to C++

+ Repo has all cpp modules

_C++ is a general-purpose programming language created by `Bjarne Stroustrup` as an extension of the C programming language, often referred to as "C with Classes". The goal of learning modules in C++ is to introduce you to Object-Oriented Programming (OOP). This serves as the starting point of your C++ journey. While many languages support OOP, we chose C++ due to its close relationship with C, a language you're familiar with. To keep things simple, your code will comply with the C++98 standard. It's worth noting that modern C++ has evolved significantly in many aspects._

In C++, Object-Oriented Programming (OOP) is a fundamental approach that utilizes classes to create objects, encapsulating data and behaviors within a single unit for enhanced code organization and reusability.

## Key Concepts:

### Object-Oriented Programming (OOP):

Object-Oriented Programming (OOP) revolves around the concept of "objects," instances of classes, and introduces several key principles:

1. **Classes and Objects:**
   - **Class:** A blueprint or template defining a data structure along with methods to operate on the data.
   - **Object:** An instance of a class, representing a real-world entity and encapsulating data and behavior.

**Example:**
```cpp
class Car {
    // Attributes
    private:
        std::string brand;
        int year;

    // Methods
    public:
        void setBrand(std::string b);
        void setYear(int y);
        void getInfo();
};
```

2. **Encapsulation:**
   - Bundling data (attributes) and methods into a single unit (class), hiding internal details and exposing only necessary functionalities.

**Example:**
```cpp
class Employee {
private:
    std::string name;
    int salary;

public:
    // Setter for salary
    void setSalary(int s) {
        salary = s;
    }

    // Getter for salary
    int getSalary() {
        return salary;
    }
};
```

3. **Inheritance:**
   - Mechanism allowing a class (subclass/derived class) to inherit properties and behaviors from another class (superclass/base class), promoting code reuse and establishing a class hierarchy.

**Example:**
```cpp
class Animal {
protected:
    std::string name;
public:
    void setName(std::string n) {
        name = n;
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << name << " barks!" << std::endl;
    }
};
```

4. **Polymorphism:**
   - Capability to treat objects as instances of their base class, enabling flexibility in handling different types of objects through a common interface.

**Example:**
```cpp
class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape" << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
};
```

5. **Abstraction:**
   - Simplifying complex systems by modeling classes based on essential characteristics, focusing on what an object does rather than how it achieves its functionality.

**Example:**
```cpp
class BankAccount {
private:
    int balance;

public:
    void deposit(int amount);
    void withdraw(int amount);
};
```

6. **Modularity:**
   - Achieved through the organization of code into classes and objects, each representing a modular unit with specific responsibilities and reusable in different parts of a program.

**Example:**
```cpp
// Class declaration
class Calculator {
public:
    int add(int a, int b);
    int subtract(int a, int b);
};

// Implementation
int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::subtract(int a, int b) {
    return a - b;
}
```

7. **Message Passing:**
   - Objects communicate by sending messages, invoking methods on objects, and responding with appropriate code execution.

**Example:**
```cpp
class Email {
public:
    void send(std::string recipient, std::string message);
};

void Email::send(std::string recipient, std::string message) {
    // Code to send email
    std::cout << "Email sent to " << recipient << ": " << message << std::endl;
}
```

### Attributes:

Attributes, also known as data members, store data related to the class and can be categorized as:

- **Private:** Accessible only within the class.

**Example:**
```cpp
class Student {
private:
    std::string name;
    int age;
};
```

### Methods (Member Functions):

Member functions associated with the class operate on its data, including constructors for object initialization and destructors for resource cleanup.

**Example:**
```cpp
class Rectangle {
public:
    // Constructor
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }

    // Method to calculate area
    int area() {
        return length * width;
    }

private:
    int length;
    int width;
};
```

### Objects:

Objects are specific instances of a class, containing data (attributes) and executing operations (methods). They are created using the class blueprint.

**Example:**
```cpp
Rectangle rect(5, 3); // Creating a Rectangle object
int area = rect.area(); // Calculating area using object's method
```

### Constructors and Destructors:

Constructors initialize objects during creation, and destructors clean up resources when an object is destroyed.

**Example:**
```cpp
class Book {
public:
    // Constructor
    Book(std::string t) {
        title = t;
        std::cout << "Book created with title: " << title << std::endl;
    }

    // Destructor
    ~Book() {
        std::cout << "Book destroyed with title: " << title << std::endl;
    }

private:
    std::string title;
};
```

### Setters and Getters:

**Example:**
```cpp
class Person {
private:
    std::string name;
    int age;

public:
    // Setter for name
    void setName(std::string n) {
        name = n;
    }

    // Getter for name
    std::string getName() {
        return name;
    }

    // Setter for age
    void setAge(int a) {
        age = a;
    }

    // Getter for age
    int getAge() {
        return age;
    }
};
```

## Conclusion

_Understanding classes in C++ and the principles of Object-Oriented Programming (OOP) is fundamental for building robust and maintainable software systems. By `encapsulating` data and behavior into classes, you can create modular, reusable, and scalable code. Through `inheritance`, `polymorphism`, `abstraction`, and other OOP concepts, C++ enables the creation of complex systems while maintaining code clarity and organization._ <br>

_Starting your C++ journey with a focus on OOP principles not only provides a solid foundation but also opens doors to mastering advanced programming techniques and exploring the rich ecosystem of libraries and frameworks available in the C++ community._ <br>
