#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(void)
{
    const int SIZE = 20;
    char addr[SIZE] = "Char";
    char name[SIZE] = "Text";
    std::string text = "가나다";
    std::string text2 = "C++ Programming";
    std::string text3 = "New Text is ";

/*  std::cin.get(name,SIZE).get();
    std::cin.get(addr,SIZE).ignore(SIZE,'\n');
    getline(std::cin,text);

    std::cout<<name<<"\\"<<addr<<"\\"<<text<<std::endl;
    std::cout<<text2.length()<<"\\"<<text2.size()<<std::endl;

    strcat(addr,name);
    cout<<addr<<endl;
    strncat(addr,name,sizeof(char));
    cout<<addr<<endl;

    string::size_type index = 4;
    text2.replace(index,text3.length(),text3);
    cout<<text2<<endl;
*/
    return 0;
}