#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int a[n1][n2], b[n2][n3], r[n1][n3];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n3; j++)
            cin >> b[i][j];
    }

    for (int k = 0; k < n3; k++)
    {
        for (int i = 0; i < n1; i++)
        {
            int j=0;
            r[i][k]=0;
            for (j; j < n2; j++)
            {
                
                r[i][k] += a[i][j] * b[j][k];
            }
        }
    }
    //for(int k=0;k<n1;k++){
    //    for(int i=0;i<n2;i++){
    //        for(int j=0;j<n3;j++){
    //            int r[k][j]=
    //        }
    //    }
    //}
    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++)cout<<r[i][j]<<" ";
        cout<<endl;
    }
}