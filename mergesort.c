#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;

    //definning two temp arrays of size n1,n2
    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }

    for(int j=0;j<n2;j++)
    {
        b[i]=arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=1;

    while(i<n1 && j<n2)
    {
        arr[k]=arr[i];
        k++;
        i++;
    }


}