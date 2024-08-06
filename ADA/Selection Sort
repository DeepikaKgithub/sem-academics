#include<stdio.h>
int main()
{
int a[50],n,i,j,temp,min;
printf("Enter the value of n:\n");
scanf("%d",&n);
printf("Enter elements in an array:\n",n);
for(i=0;i<n;i++)
scanf("%d", &a[i]);
for(i = 0; i < n - 1; i++)
{
min=i;
for(j = i + 1; j < n; j++)
{
if(a[min] > a[j])
min=j;
}
if(min != i)
{
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
}
printf("Sorted Array:\n");
for(i = 0; i < n; i++)
printf("%d\n", a[i]);
return 0;
}
