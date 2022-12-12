#include<bits/stdc++.h>
using namespace std;
int maximumANDSum(int* nums, int n, int k){

  int a[1000],b[1000][2],c[1000];
  int max=0,sum=0,mp1=0,mp2=0,count=0;
  int x,i,j,h,temp;


  for(i=0;i<n;i++)
  { a[i]=*(nums+i);
  }

  for(i=0;i<n;i++)
  { count=0;
    for(j=1;j<=k;j++)
    { if((a[i]&j)>0)
      count++;
      c[i]=count;
    }
  }
  for(j=0;j<=k;j++)  //initialize -1
  { for(h=0;h<2;h++)
    {
     b[j][h]=-1;
    }
  }

for(i=0;i<n;i++) //loop for a[n] elements
  { max=0;
    if(a[i]==-1)
    continue;
    for(j=1;j<=k;j++) //loop for b[k][2] array
    { for(h=0;h<2;h++)
	{

		if( ((a[i]&j)>max || (c[i]==0)) && (b[j][h]==-1) )
		{ max=a[i]&j;
		  mp1=j;
		  mp2=h;
		  break;
		}


	}
    }

    b[mp1][mp2]=a[i];
    sum+=max;
  }

  return sum;
}
int main()
{ int a[20],b[10][2],c[20];
  int i,j,n,k,result;

  printf("enter N value:");
  scanf("%d",&n);
  printf("enter %d values:\n",n);
  for(i=0;i<n;i++)
  { scanf("%d",&a[i]); }
  printf("enter k value:");
  scanf("%d",&k);

  result=maximumANDSum(a,n,k);
  printf("sum=%d",result);
}