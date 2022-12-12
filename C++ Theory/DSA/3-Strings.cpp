#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string a="abc";
    string b="xyz";
    string c="lqj";
    cout<<a.compare(b); //  
    string s="Hello World Less Goooooooooooo";
    sort(s.begin(), s.end());
    cout<<s;
    string l="Hello World Less Goooooooooooo";
    sort(l[5],l[10]);
    cout<<l;
}