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

int main(void)
{
	int i, nx=5, ky=8, idx;
	int *x;

    x= new int[nx];							
	//x = calloc(nx, sizeof(int));	

	for (i = 0; i < nx; i++) {
		std::cout<<"x["<<i<<"] : ";
		std::cin>>x[i];
	}
	
	idx = search(x, nx, ky);

	if (idx == -1)
		std::cout<<"search error.";
	else
		std::cout<<ky<<" is in the x["<<idx<<"]";
	
	//free(x);
    delete x;
	
	return 0;
}