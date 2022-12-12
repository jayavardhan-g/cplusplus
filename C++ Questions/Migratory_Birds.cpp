#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int s[n];
    int f[5] = {0};
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case 1:
            f[0] += 1;
            break;
        case 2:
            f[1] += 1;
            break;
        case 3:
            f[2] += 1;
            break;
        case 4:
            f[3] += 1;
            break;
        case 5:
            f[4] += 1;
            break;
        default:
            cout << "The input is incorrect";
        }
    }
    // for(int i=0;i<5;i++){
    //     cout<<f[i]<<endl;
    // }
    int max = -1, mf;
    for (int i = 0; i < n; i++)
    {
        if (f[i] > max)
        {
            max = f[i];
            mf = i;
        }
    }

    cout << mf;
}