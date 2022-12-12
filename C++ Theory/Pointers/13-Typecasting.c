#include<stdio.h>

int main(){
    int a=1025;
    int *p;
    p=&a;
    printf("%d\n%d\n",p,*p); // address of a, 1025
    char *c;
    c=(char*)p; // typecasting  
    printf("%d\n%d\n",c,*c); // address of a, 1 as 1 is the value of character byte '00000001'
    
    printf("%d\n%d",(p+1),*(p+1)); // address of next block of 4 bytes , value of next int block of 4 bytes
    printf("\n%d\n%d",(c+1),*(c+1)); // address of the 2nd byte in the int block , value of the 2nd byte in the int block '00000100'
}