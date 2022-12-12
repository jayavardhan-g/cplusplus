#include <bits/stdc++.h>
using namespace std;
int AddBinary(int a,int b){
    int n,i=0;
    while(a>0||b>0){
        int l=a%10;
        int m=b%10;
        int carry=0,c=0;
        a/=10;b/=10;
        if(l+m==0){carry=0;c=0;}
        else if(l+m==1){carry=0;c=1;}
        else if(l+m==2){carry=1;c=0;}
        else {carry =1;c=1;}
        
        a=a+carry;
        n=n+c*pow(10,i);
        i++;
    }
    return n;

}
int AddOctal(int a,int b){
    //complete this 
    return 0;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<AddBinary(a,b);
}