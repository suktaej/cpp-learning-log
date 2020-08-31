#include <iostream>
#include <cstdlib>
#include "stack.h"

int Initialize(Intstack *s,int max){

    s->ptr=0;
    //(*s).ptr=0;
    if((s->stk=new int[max])==NULL){
        s->max=0;
        return -1;
    }
    s->max=max;
    return 0;
}

int Push(Intstack *s,int x){

    if(s->ptr >= s->max)    return -1;

    s->stk[s->ptr++] = x;
    return 0;
}

int Pop(Intstack *s, int *x){
    
    if(s->ptr <= 0) return -1;

    *x=s->stk[s->ptr--];
    return 0;
}

int Peek(const Intstack *s,int *x){

    if(s->ptr<=0)   return -1;

    *x=s->stk[s->ptr-1];
    return 0;
}

void Clear(Intstack *s){

    s->ptr=0;
}