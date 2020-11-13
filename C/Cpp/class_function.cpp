#include <iostream>
#include <cstring>
using namespace std;

namespace NAMESPC{

    class Point
    {
        private:
            int xpos, ypos;
        public:
            Point(int x,int y):xpos(x),ypos(y){}
            
            void Show_point_info() const
            {
                cout<<"["<<xpos<<","<<ypos<<"]"<<endl;
            }
    };

    class Circle
    {
        private:
            int rad;
            Point center;
        public:
            Circle(int x,int y,int r):center(x,y)
            {
                rad=r;
            }

            void Show_Circle_info() const
            {
                cout<<"rad is "<<rad<<endl;
                center.Show_point_info();                
            }
    };

    class Ring
    {
        private:
            Circle incir;
            Circle outcir;
        public:
            Ring(int inx,int iny, int inr, int outx, int outy, int outr):incir(inx,iny,inr),outcir(outx,outy,outr){}

            void Show_ring_info() const
            {
                cout<<"inner circle info"<<endl;
                incir.Show_Circle_info();
                cout<<"outter circle info"<<endl;
                outcir.Show_Circle_info();
            }
    };
}

int main(void)
{
    NAMESPC::Ring r(1,1,4,2,2,9);
    r.Show_ring_info();

    return 0;
}