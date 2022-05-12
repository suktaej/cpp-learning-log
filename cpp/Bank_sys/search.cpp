#include <iostream>
#include <cstdlib>

int linear_search(const int a[], int n, int key)
{
    int i=0;

    for(i=0;i<n;i++)
    {
        /*if(a[i]==key) return i;
        else return -1;*/
        if (a[i] == key)
			break;				
 
        std::cout<<i<<std::endl;
    }
    return i == n ? -1 : i;
}

int binary_search(const int a[], int n, int key)	//sorted
{
	int pl=0, pr=n-1;
	int pc=0;

	do{
		pc=(pl+pr)/2;
		if(key==a[pc])	return pc;
		else if(a[pc]<key)	pl=pc+1;
		else	pr=pc-1;

		std::cout<<"now pc:"<<pc<<std::endl;

	}while(pl<=pr);

	return -1;	
}

int main(void)
{
	int i, nx=9, ky=8, idx;
	/*int *x;

    //x= new int[nx];							
	x = calloc(nx, sizeof(int));	

	for (i = 0; i < nx; i++) {
		std::cout<<"x["<<i<<"] : ";
		std::cin>>x[i];
	}*/
	int x[9]={1,2,3,4,5,6,7,8,9};

	idx = binary_search(x, nx, ky);

	if (idx == -1)
		std::cout<<"search error.";
	else
		std::cout<<ky<<" is in the x["<<idx<<"]";
	
	//free(x);
    //delete x;
	
	return 0;
}