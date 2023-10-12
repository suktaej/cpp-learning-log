#include<iostream>

using namespace std;

struct Name
{
    string first;
    string last;
};

struct book
{
    string title;
    //string author;
    struct Name author;
    int price;
    int sale;
};

typedef struct
{
    string title;
    //string author;
    struct Name author;
    int price;
    int sale;
} Book;

int Calc(int, int);
int PtrCalc(const book*);

int main(void)
{
    struct book webBook = {"HTML&CSS",{"Kim","NARA"},28000,10000};
    Book javaBook = {"Java",{"Lee","DARE"},10000,5000};
    int salePrice;

    salePrice = Calc(webBook.price,webBook.sale);
    cout<<webBook.author.first<<webBook.author.last<<"\\"<<webBook.title<<"\\"<<webBook.price<<"\\"<<salePrice<<endl;
    
    salePrice = PtrCalc(&javaBook);
    cout<<javaBook.author.first<<javaBook.author.last<<"\\"<<javaBook.title<<"\\"<<javaBook.price<<"\\"<<salePrice<<endl;

    return 0;
}

int Calc(int a, int b)
{
    return (a-b);
}

int PtrCalc(const book* wbook)
{
    //wbook->price=30000;
    return(wbook->price - wbook->sale);
}