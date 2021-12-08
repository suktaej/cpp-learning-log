#include <iostream>
#include <cstring>
using namespace std;

namespace CLA
{
    enum {CLERK,SENIOR,ASSIST,MANAGER};

    void Show_Pos_info(int pos)
    {
        switch(pos)
        {
            case CLERK:
                cout<<"clerk"<<endl;
                break;
            case SENIOR:
                cout<<"senior"<<endl;
                break;
            case ASSIST:
                cout<<"assist"<<endl;
                break;
            case MANAGER:
                cout<<"manager"<<endl;
                break;
        }
    }
}

class Namecard
{
    private:
        char *name;
        char *company;
        char *phone;
        int position;
    public:
        Namecard(const char *name,const char *company,const char *phone, int pos):position(pos) //cpp do not allow char*. use const char*
        {
            this->name=new char[strlen(name)+1];
            this->company=new char[strlen(company)+1];
            this->phone=new char[strlen(phone)+1];
            strcpy(this->name,name);
            strcpy(this->company,company);
            strcpy(this->phone,phone);
        }

        Namecard(const Namecard &ref):position(ref.position)
        {
            name=new char[strlen(name)+1];
            company=new char[strlen(company)+1];
            phone=new char[strlen(phone)+1];
            strcpy(name,ref.name);
            strcpy(company,ref.company);
            strcpy(phone,ref.phone);
        }

        void Show_name_card_info(void)
        {
            cout<<name<<endl<<company<<endl<<phone<<endl<<position<<endl;
        }

        ~Namecard()
        {
            delete []name;
            delete []company;
            delete []phone;
        }
};

int main(void)
{
    Namecard man("Lee","ABCEng","010-4444-2222",CLA::ASSIST);
    man.Show_name_card_info();

    return 0;
}

