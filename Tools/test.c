#include<stdio.h>
#include<string.h>

char* fun(char *ptr){
    ptr+=2;
    return (ptr);
}

int main(){
    char *str= "x";
    char c='x';
    char arr[2];
    arr[0]=c;

    // b=fun(a);
    printf("%d %d", strlen(str), strlen(arr));
    return 0;
}