#include <bits/stdc++.h>
using namespace std;
int main(){
    int i=5; // 0101
    // to check a bit
    i= i & 1<<2; // this compares 0101 and 0100 and only keeps one when there are both 1s -> 0100
    cout<<i; //4 as 0100 is 4
    // to insert a bit
    i= i | 1; // this compares 0100 and 0001 and keeps one where there is atleast 1 -> 0101 
    cout<<i;
    i = i | 1<<1; //compares 0101 and 0010 and outputs 0111
    cout<< i; // 7
    //To clear a bit from the number 
    i= i& ~(1<<2); // ~ is for compliment
    // to clear a bit we first send 1 to its place and take the compliment which makes it 0 and all others 1s 
    // now compare with & which will give 0 as the bit in its place is 0 done by the above step
    cout<<i;

    // Update bit
    //first clear the bit and then update the bit
    int value=1; //1 or 0
    int p=0;// position to update the bit
    i= i& ~(1<<p);
    i = i | (value<<p);
    
}