#include <iostream>
using namespace std;

void pibo(int count){

    int temp=0;
    
    for(int i=1;i<count+1;i++){
        temp+=i;
        cout<<temp<<endl;
    }
}

void gaus(int count){

    int val=0;
    int val2=0;

    if(count%2==0){
        val=(1+count)*count/2;
        cout<<"gaus sum:"<<val<<endl;
    }
    else{
        val=((1+(count-1))*(count-1)/2)+count;
        cout<<"gaus sum:"<<val<<endl;
    }
//	(count+1)*(count/2)+(count%2==1 ? (count+1) / 2 : 0);
    
    for(int i=1;i<count+1;i++){
         val2+=i;
    }

    cout<<"sum:"<<val2<<endl;
    
}

int min_max_add(int min,int max){

    int temp=min;

    for(int i=min;i<=max;i++){
        temp+=i;
    }

    return temp;
}

int main(void){

    int count=0;
    int min, max;
    cin>>count;

    //pibo(count); 
    //gaus(count);

    return 0;
}