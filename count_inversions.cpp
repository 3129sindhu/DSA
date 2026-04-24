#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;
int cnt=0;

int merge(vector<int> &arr,int left,int mid, int right){
    vector<int> temp;
    int low=left;
    int high=mid+1;
    int cnt=0;
    while(low<=mid&& high<=right){
        if(arr[low]<=arr[high]){
            temp.push_back(arr[low]);
            low++;
        }else{
            temp.push_back(arr[high]);
            cnt+=(mid-low+1);
            high++;
        }
    }
        while(low<=mid){
            temp.push_back(arr[low]);
            low++;
        }
        while(high<=right){
            temp.push_back(arr[high]);
            high++;

        }
        for(int i=left;i<=right;i++)
        {
            arr[i]=temp[i-left];
        }
        return cnt;
    }


int mergeSort(vector<int> &arr, int left, int right)
{
    
    int cnt=0;
    if(left>=right) return cnt;
    int mid=(left+right)/2;
    cnt+=mergeSort(arr,left,mid);
    cnt+=mergeSort(arr,mid+1,right);
    cnt+=merge(arr,left,mid,right);
    return cnt;
    
}




int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=0;
    cnt=mergeSort(arr,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"count of inversions: "<<cnt<<endl;
    return 0;
}