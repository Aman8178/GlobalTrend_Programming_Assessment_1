#include<bits/stdc++.h>

using namespace std;

int computeSum(int n)
{
    int sum=0;
    while(n>0)
    {
        int rem=n%10;
        sum+=rem;
        n=n/10;
    }
    return sum;
}

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Sum of digit of numbers is = "<<computeSum(n)<<endl;
    return 0;
}