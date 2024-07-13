#include<bits/stdc++.h>

using namespace std;

int longestsubstring(string s)
{
    int maxi=0, start=-1;
    vector<int>arr(256, -1);
    for(int i=0; i<s.length(); i++)
    {
        if(arr[s[i]]>start)
        {
            start=arr[s[i]];
        }
        arr[s[i]]=i;
        maxi=max(maxi, i-start);
    }
    return maxi;
}

int main()
{
    string s;
    cout<<"Enter any string : ";
    cin>>s;

    cout<<"Longest substring without repeating is : "<<longestsubstring(s)<<endl;
    return 0;
}