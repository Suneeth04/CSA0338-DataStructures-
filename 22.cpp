#include<stdio.h>
int main()
{
	int n;
	printf("enter the size of array");
	scanf("%d",&n);
	int arr[n];
	printf("enter %d elements:\n",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("odd or even for each element in the array:\n");
	for(int i=0;i<n;i++)
	{
		if(arr[i]%2==0)
		{
			printf("%d is an even number.\n",arr[i]);
		}
		else
		{
			printf("%d is an odd number.\n",arr[i]);
		}
	}
	return 0;
}