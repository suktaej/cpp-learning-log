#include <iostream>
#include <cstdlib>

using namespace std;

int maxof(const int a[], int n)
{
	int i;
	int max = a[0]; 		/* 최댓값 */

	for (i = 1; i < n; i++)
		if (a[i] > max) max = a[i];

	return max;
}

int sumof(const int a[], int n){

    int i;
    int sum=0;

    for(i=0;i<n;i++)    sum+=a[i];
    
    return sum;
}

int main(void)
{
	int i;
	int *height;			/* 배열의 첫 번째 요소의 포인터 */
	int number;				/* 인원 = 배열 ​​height의 요소 개수 */
	printf("사람 수 : ");
	scanf("%d", &number);
	height = (int*)calloc(number, sizeof(int));	/* 요솟수가 number개인 배열을 생성 */

	printf("%d 사람의 키를 입력하세요.\n", number);
	for (i = 0; i < number; i++) {
		printf("height[%d] : ", i);
		scanf("%d", &height[i]);
	}

	printf("최댓값은 %d입니다.\n", maxof(height, number));
	
	free(height); 				/* 배열 height를 해제 */

	return 0;
}