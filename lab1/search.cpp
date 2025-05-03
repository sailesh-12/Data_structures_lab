#include "sort.h"
#include<iostream>
#include<stdio.h>

void linearSearch(int arr[],int,int);
int binarySearch(int arr[],int ,int);
int main()
{
    int len,target; 
    printf("Enter the number of elements:\n");
    scanf("%d", &len);

    int arr[len];
    printf("Enter the elements:\n");
    for(int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter target element to find:\n");
    scanf("%d",&target);
    linearSearch(arr,len,target);
    int index=binarySearch(arr,len,target);
    if(index==-1){
        printf("Element is not found\n");
    }else{
        printf("Element is found ");
    }
}

void linearSearch(int arr[],int len,int target){
    printf("Using Linear search:\n");
    for(int i=0;i<len;i++)
    {
        if(arr[i]==target)
        {
            printf("the element is found at index %d\n",i);

        }
    }
}
int binarySearch(int arr[], int len, int target)
{
    bubble_sort(arr, len);  // Assuming you have a bubble_sort function
  
    int low = 0;
    int high = len - 1;
    int mid = 0;

    printf("Using Binary search:\n");

    while (low <= high)
    {
        mid = (low+high)>>1;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
             low = mid + 1;
        }
        else
        {
           
            high = mid - 1;
        }
    }

    return -1;  // Return -1 if the element is not found
}
