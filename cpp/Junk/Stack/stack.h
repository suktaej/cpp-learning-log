#include <iostream>

using namespace std;

#ifndef __IntStack
#define __IntStack

class Intstack{
public:
    int max;    //stack capacity
    int ptr;    //stack pointer
    int *stk;   //first element of stack
};

int Initalize(Intstack *s,int max);
int Push(Intstack *s,int x);
int Peek(const Intstack *s, int*x);
void Clear(Intstack);
int Captacity(const Intstack *s);
int Size(const Intstack *s);
int IsEmpty(const Intstack *s);
int IsFull(const Intstack *s);
int Search(const Intstack *s);
void Print(const Intstack *s);
void Terminate(Intstack *s);

#endif