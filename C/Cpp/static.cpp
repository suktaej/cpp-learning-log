#include <iostream>

using namespace std;

class SoSimple
{
    public:
        static int simO;
    public:
        SoSimple()
        {
            simO++;
        }
};

int SoSimple::simO=0;

int main(void)
{
    cout<<SoSimple::simO<<endl;
    SoSimple sim1;
    SoSimple sim2;

    cout<<SoSimple::simO<<endl;
    cout<<sim1.simO<<endl;
    cout<<sim2.simO<<endl;

    return 0;
}