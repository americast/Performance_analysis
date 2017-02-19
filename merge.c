#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void man(long arr[], long beg, long mid1, long mid2, long endn)
{
  long temp[endn-beg+1];
  long i=beg, j=mid2, count=0;
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
  for (long i=beg; i<=endn; i++)
  {
    arr[i]=temp[j];
    j+=1;
  }
}

void pungi(long arr[],long l,long r)
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
  printf("Executing with C...");
  long n;
  scanf("%ld",&n);
  long arr[n];
  long count=0;
  while(1)
  {
    long num;
    scanf("%ld",&num);
    if (num==-1)
      break;
    count++;
    arr[count-1]=num;
  }
  n=count;
  clock_t launch = clock();
  pungi(arr,0,n-1);
/*  for (long i=0; i<n; i++)
    printf("%d ",arr[i]);*/
  clock_t done = clock();
  double diff = (double)(done - launch) / CLOCKS_PER_SEC;
  printf("elapsed time:%f\n",diff);
}
