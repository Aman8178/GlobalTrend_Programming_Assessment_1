#include<bits/stdc++.h>

using namespace std;

bool isAlphabetic(string& s) {
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>=65 && s[i]<=90)
        {
            continue;
        }
        else if(s[i]>=97 && s[i]<=122)
        {
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cout<<"Enter any string : ";
    cin>>s;
    cout<<isAlphabetic(s)<<endl;
    return 0;
}
