#include <stdio.h>
int maxElement(int arr[],int n){
if(n==1)return arr[0];
int max=maxElement(arr,n-1);
return(arr[n-1]>max)?arr[n-1]:max;
}
int main(){
    int arr[]={23,3445,455,4657};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("maximum element in the arra :%d\n",maxElement(arr,n));
    return 0;
}


