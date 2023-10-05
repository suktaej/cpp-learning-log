#include<iostream>
#include<string>

int main(void)
{
    const int SIZE = 20;
    char addr[SIZE];
    char name[SIZE];
    std::string text;
    std::string text2 = "C++ Programming";

/*  std::cin.get(name,SIZE).get();
    std::cin.get(addr,SIZE).ignore(SIZE,'\n');
    getline(std::cin,text);

    std::cout<<name<<"\\"<<addr<<"\\"<<text<<std::endl;
*/
    std::cout<<text2.length()<<"\\"<<text2.size()<<std::endl;
    return 0;
}