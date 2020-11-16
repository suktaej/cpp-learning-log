#include <iostream>

using namespace std;

int increment(int& n);
int increment2(int n);
int& increment3(int& n);

int main(void)
{
int num=0;
cout << "num= " << increment(num) << endl;
cout << num << endl;
cout << "num= " << increment2(num) << endl;
cout << num << endl;
cout << "num= " << increment3(num) << endl;
cout << num << endl;

getchar();
return 0;
}

int increment(int& n)
{
++n;
return n;
}

int increment2(int n)
{
++n;
return n;
}

int& increment3(int& n)
{
++n;
return n;
}