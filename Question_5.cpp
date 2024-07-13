#include<bits/stdc++.h>

using namespace std;

void rightRotate(int n, int k,int arr[])
{
    int t[n];
    for(int i=0; i<n; i++)
    {
        t[i]=arr[(i+k)%n];
    }
    for(int i=0; i<n; i++)
    {
        arr[i]=t[i];
    }
}
void printArray(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n, k;
    cout<<"Enter n and k of array : ";
    cin>>n>>k;
    int arr[n];
    cout<<"Enter array elements : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Before rotate right by "<<k<<" steps: "<<endl;
    printArray(n, arr);
    cout<<endl;
    cout<<"After rotate right by "<<k<<" steps: "<<endl;
    rightRotate(n, k, arr);
    printArray(n, arr);
    cout<<endl;
    return 0;
}