#pragma once

#include <iostream>

inline void func1()
{
    std::cout << "This is func1.\n";
}

class A
{
public:
    void method1();
};

inline void A::method1()
{
    std::cout << "This is method1.\n";
}
