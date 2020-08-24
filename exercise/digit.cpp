#include <iostream>
using namespace std;

void mul_table(void){

    int count=9;

    for(int i=1;i<=count;i++){
        for(int j=1;j<=count;j++){
            cout<<i*j<<'\t';
        }
        cout<<endl;
    }
}

void pira(int n){

    int mid=n/2+1;
    int star=0;
    int term=mid;
    int i,j,k;
    
    for(i=0;i<n;i++){
        if(i<mid){

            star=(2*i)+1;  

            for(j=term;j>1;j--) cout<<'-';
            for(k=0;k<star;k++) cout<<'*';

            term--;
        }
        else{            
            
            star=(2*(n-i-1))+1;

            for(j=0;j<=term;j++) cout<<'-';
            for(k=0;k<star;k++) cout<<'*';
            term++;
        }
        cout<<term;
        cout<<endl;
        
    }
}

int main(void){

    pira(9);

    return 0;
}