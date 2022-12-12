    #include <bits/stdc++.h>
    using namespace std;
    int main(){
        int i;
        cin>>i;
        int l=2;
        for(l=2;l<i;l++){
            int d=i%l;
            if(d==0){
                cout<<"The number is not prime";
                break;
            };
        }
        if(l==i) cout<<"The number is prime";else;

        // NOTE - The iterations can be limited to go only upto square root of n 
        // Even if there are factors of n after square root of n they would already have been found
        
    }