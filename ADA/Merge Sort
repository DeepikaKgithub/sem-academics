#include<stdio.h>
void merge(int *array ,int low,int mid,int high)
{
    int resarray[25];
    int i=low;
    int k=low;
    int j=mid+1;
    
    while(i<=mid && j<=high)
    {
        if(array[i]<array[j])
        {
        resarray[k]=array[i];
        i++;
        k++;
        }
        else
        {
          resarray[k]=array[j];  
          j++;
          k++;
        }
    }
    while(i<=mid)
        resarray[k++]=array[i++];
    while(j<=high)
        resarray[k++]=array[j++];
    for(int m=low;m<=high;m++)
			array[m]=resarray[m];
}
void sort(int *array,int low,int high)
{
		if(low<high)
		{
			int mid=(low+high)/2;
			sort(array,low,mid);
			sort(array,mid+1,high);
			merge(array,low,mid,high);
		}
}
int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
 
    int array[n];
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
 
    sort(array, 0, n - 1);
 
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
