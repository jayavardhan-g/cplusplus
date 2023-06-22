#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    double x,y;
    string s;
    double a;
    double i=0,j=0;
    while(x!=-1){
        cin>>x;
        cin>>s;
        if(s=="A+")y=10;
        else if(s=="A")y=9;
        else if(s=="B+")y=8;
        else if(s=="B")y=7;
        else if(s=="C+")y=6;
        else if(s=="C")y=5;
        else if(s=="D")y=4;
        if(x==-1)break;
        x/=2;
        i+=x;
        j+=x*y;
    }
    x=0;
    while(x!=-1){
        cin>>x;
        cin>>s;
        if(s=="A+")y=10;
        else if(s=="A")y=9;
        else if(s=="B+")y=8;
        else if(s=="B")y=7;
        else if(s=="C+")y=6;
        else if(s=="C")y=5;
        else if(s=="D")y=4;
        else y=7.2;
        if(x==-1)break;
        i+=x;
        j+=x*y;
    }
    x=0;
    y=0;
    while(x!=-1){
        cin>>x;
        cin>>y;
        if(x==-1)break;
        i+=x;
        j+=x*y;
    }

    a=j/i;
    cout<<setprecision(3)<<a;
}


/*
6 C+
6 C+
11 B
11 B+
9 C
4.5 A
4.5 C+
1.5 A
1.5 A
2 B

9 C+
5 B+
9 B+
11 B+
4 B+
1 C+
3 B
3 A
5 B+
2 A

9 C
9 C
9 C+
9 C
11 C
2 C+
2 C+

-1 X

9 D
9 C
9 C
9 C+
9 B+
2 B
2 A

9 D
9 D
9 B
9 C
9 B
2 B+
2 B

9 A
9 B
9 B
9 B
9 B
2 B+
2 B

-1 X

0 0

-1 X
*/