#include <iostream>
using namespace std;

int max4(int *a,int *b,int *c,int *d){

    int max_num=*a;

    if(*b>max_num) max_num=*b;
    if(*c>max_num) max_num=*c;
    if(*d>max_num) max_num=*d;

    return max_num;
}

int main(void){

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    cout<<max4(&a,&b,&c,&d)<<endl;

    return 0;
} 

