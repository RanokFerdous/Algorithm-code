
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // sort a string
    string s= "deacbAA" ;
    sort( s.begin(), s.end());

   // int sz= unique ( s.begin(), s.end())- s.begin();

    cout<<*max_element ( s.begin(), s.end())<<endl;

    //cout<<" index of max elemtn are: " <<max_element( s.begin(), s.end())-s.begin()<<endl;

    cout<<*min_element( s.begin(), s.end())<<endl;

   // cout<<" index of the min element are : "<< min_element( s.begin(), s.end())- s.begin()<<endl;
}
