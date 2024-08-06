#include<stdio.h>
    int partition(int a[25],int low,int high)
{
	int p,i,j,temp;
	p=a[low];
	i=low+1;
	j=high;
	while(low<high)
	{
		while(a[i]<=p&&i<high)
			i++;
		while(a[j]>p)
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			temp=a[low];
			a[low]=a[j];
			a[j]=temp;
			return j;
		}
	}
		return j;
	}
	void sort(int a[],int low,int high)
	{
		if(low<high)
		{
			int s=partition(a,low,high);
			sort(a,low,s-1);
			sort(a,s+1,high);
		}
	}
int main()
{
   int i, n, a[25];
   printf("Enter the array size: ");
   scanf("%d",&n);
   printf("Enter array elements:",n);
   for(i=0;i<n;i++)
    scanf("%d",&a[i]);
   sort(a,0,n-1);
   printf("Order of Sorted elements: ");
   for(i=0;i<n;i++)
   printf(" %d",a[i]);
   return 0;
}
