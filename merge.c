#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void man(int arr[], int beg, int mid1, int mid2, int endn)
{
  int temp[endn-beg+1];
  int i=beg, j=mid2, count=0;
  while (1)
  {
    if (i>mid1 || j>endn)
      break;
    if (arr[i]<=arr[j])
    {
      temp[count]=(arr[i]);
      i+=1; count++; continue;
    }
    else
    {
      temp[count]=(arr[j]);
      j+=1; count++;continue;
    }
  }
  while (i<=mid1)
  {
    temp[count]=(arr[i]);
    i+=1;count++;
  }
  while(j<=endn)
  {
    temp[count]=(arr[j]);
    j+=1; count++;
  }
  j=0;
  for (int i=beg; i<=endn; i++)
  {
    arr[i]=temp[j];
    j+=1;
  }
}

void pungi(int arr[],int l,int r)
{
  if (l<r)
  {
    pungi(arr,l,((l+r)/2));
    pungi(arr,(1+((l+r)/2)),r);
    man(arr,l,((l+r)/2),((l+r)/2)+1,r);
  }
}

int main()
{
  printf("\n------\nExecuting with C...");
  int n;
  scanf("%d",&n);
  int arr[n];
  int count=0;
  while(1)
  {
    int num;
    scanf("%d",&num);
    if (num==-1)
      break;
    count++;
    arr[count-1]=num;
  }
  n=count;
  clock_t launch = clock();
  pungi(arr,0,n-1);
/*  for (int i=0; i<n; i++)
    printf("%d ",arr[i]);*/
  clock_t done = clock();
  double diff = (double)(done - launch) / CLOCKS_PER_SEC;
  printf("\nTime elapsed:%f\n",diff);
  printf("\Executed with C. No. of items: %d\n------\n\n",n);
}
