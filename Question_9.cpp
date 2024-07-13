#include<bits/stdc++.h>

using namespace std;

int maxDiff(int n, int arr[])
{
    int mini=INT_MAX, maxi=0;
    for(int i=0; i<n; i++)
    {
        mini=min(mini, arr[i]);
        maxi=max(maxi, arr[i]);
    }
    return maxi-mini;
}

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Maximum difference is = ";
    cout<<maxDiff(n, arr)<<endl;
    return 0;
}