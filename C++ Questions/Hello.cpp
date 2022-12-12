    #include <bits/stdc++.h>
    using namespace std;
    int main(){
        int n;
        int k;
        cin>>n>>k;
        int ar[]={1, 3, 2, 6, 1, 2};
        int s=0;
        for (int i=0;i<n;i++){
            for (int j=1;j<n-i;j++){    
                if (ar[i]+ar[j+i]==k) s++;
                else ; 
            }
        }
        cout<<s;
    }