def man(arr, beg, mid1, mid2, endn):
  temp=[]
  i=beg; j=mid2
  while 1:
    if (i>mid1 or j>endn):
      break
    if (arr[i]<=arr[j]):
      temp.append(arr[i])
      i+=1; continue
    else:
      temp.append(arr[j])
      j+=1; continue
  while (i<=mid1):
    temp.append(arr[i])
    i+=1
  while(j<=endn):
    temp.append(arr[j])
    j+=1
  j=0
  for i in xrange(beg,endn+1):
    arr[i]=temp[j]
    j+=1


def pungi(arr,l,r):
  if (l<r):
    pungi(arr,l,((l+r)/2))
    pungi(arr,(1+((l+r)/2)),r)
    man(arr,l,((l+r)/2),((l+r)/2)+1,r)


import time
arr=raw_input().split(' ')
n=len(arr)-2
for i in xrange(0,len(arr)):
    try:
        arr[i]=int(arr[i])
    except: pass
arr=arr[1:-1]
tic=time.clock()
pungi(arr,0,n-1)
#print(arr)
print("Time elapsed: "+str(time.clock()-tic))
