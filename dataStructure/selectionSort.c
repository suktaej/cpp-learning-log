#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define MAX_SIZE 101

void selectionSort(int [],int);
void swap(int *,int *);

int main(void)
{
    int i, n, *pi;
    int list[MAX_SIZE];

    n=10;

    if(n<1||n>MAX_SIZE)
    {
        fprintf(stderr,"Improper value of n\n");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<n;i++)
    {
        list[i] = rand()% 100;
        printf("%d ",list[i]);
    }
    printf("\n");

    selectionSort(list,n);

    for(i=0;i<n;i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int list[], int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(list[j]<list[min])
            min = j;
        SWAP(list[i],list[min],temp);
        }
    }
}