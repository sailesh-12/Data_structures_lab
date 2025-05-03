#include<stdio.h>
#include<iostream>

void bubble_sort(int arr[], int len) {
    int temp; // Temporary variable for swapping
    int flag=0;
    for(int i = len - 1; i >= 1; i--) {
        for(int j = 0; j < i; j++) { // Inner loop should be j < i
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag=1;
                
            }
           
        }
        if(flag==0) break;
    }

}

void insertion_sort(int arr[],int len){
    int temp;
    
    for(int i=0;i<=len-1;i++)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
    
}
void selection_sort(int arr[], int len){
    int temp,min;
    for(int i=0;i<=len-2;i++)
    {
        min=i;

        for(int j=i;j<=len-1;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }

        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
   
}