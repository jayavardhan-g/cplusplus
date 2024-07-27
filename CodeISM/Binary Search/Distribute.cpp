    //https://www.spoj.com/problems/PIE/
    #include<bits/stdc++.h>
    using namespace std;
    #define endl "\n"
    #define int long long
    #define double long double
    int n,f;


    int32_t main(){
        int t; cin>>t;
        vector<double> v;
        while(t--){

            cin>>n>>f;
            v.resize(n);
            for(int i=0;i<n;i++)cin>>v[i];
            for(int i=0;i<n;i++){
                v[i] = v[i]*v[i]*M_PI;
            }
            double lo=0,hi = 1e9, m,ans;
            for(int k=0;k<1000;k++){
                m = lo +(hi-lo)/2;
                int pies= 0;
                for(int i=0;i<n;i++){
                    pies += v[i]/m;
                }
                if(pies>=(f+1)){
                    ans=m;
                    lo =m;
                }else{
                    hi=m;
                }
            }
            cout<<fixed<<setprecision(4)<<ans<<endl;
            // printf( "%.4Lf\n" , ans);

        }   
    }