#include <bits/stdc++.h>
using namespace std;
int * BubbleSort(int a[],int n){
    int *A=(int *)malloc(n*sizeof(int ));
    for(int i=0;i<n;i++){A[i]=a[i];}
    int i=0;
    while(i<n-1){
        for(int j=0;j<n-i;j++){
            if(A[j]>A[j+1]){int temp=A[j];A[j]=A[j+1];A[j+1]=temp;}
        }
        i++;
    }
    return A;
    // this code can also be written as
    /*
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){int temp=A[j];A[j]=A[j+1];A[j+1]=temp;}
        }
    }
    return A;
    */
}


int * SelectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int l=i;
        int min=a[i];
        for(int j=0;j<n-i-1;j++){
            if(a[j+i]<min) {min=a[j+i];l=j+i;}    
        }
        a[l]=a[i];a[i]=min; //swapping the numbers
    }
    int *A=(int *)malloc(n*sizeof(int ));
    for(int i=0;i<n;i++){A[i]=a[i];}
    return A;
}


// insertion sort -> the element is shifted to its correct position
void InsertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i;
        int temp=a[i];
        while(a[j-1]>temp && j>0){
            a[j]=a[j-1];
            j--;
        }
        a[j] =temp; 
        
    }
}
//merge sort the array is divided and merged
void merge(int *a, int l,int mid, int e){
    int n1=mid+1-l,n2=e-mid;
    int x[n1],y[n2];
    for(int i=0;i<n1;i++)x[i]=a[l+i];
    for(int i=0;i<n2;i++)y[i]=a[mid+1+i];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(x[i]<y[j]){
            a[k]=x[i];
            i++;k++;
        }
        else{
            a[k]=y[j];
            j++;k++;
        }
    }
    while(i<n1){
        a[k]=x[i];
        i++;k++;
    }
    while(j<n2){
        a[k]=y[j];
        j++;k++;
    }
}

void mergesort(int *a, int l, int e){
    if(l<e){
        int mid=(l+e)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,e);
        merge(a,l,mid,e);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    //int *A=BubbleSort(a,n);
    //int *A=SelectionSort(a,n);
    //for(int i=0;i<n;i++){cout<<A[i]<<endl;}
    
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<endl;
}