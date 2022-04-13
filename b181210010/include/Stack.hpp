#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
using namespace std;
#include "Dugum.hpp"

class Stack
{
public:
    int *elemanlar;
    int ilk;
    int boyut;
    int kapasite;
    Stack();
    void Reserve(int kapasite);
    void Push(int veri);
    void Pop();
    void stackYazdir();
    ~Stack();
};
#endif