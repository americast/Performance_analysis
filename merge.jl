function man(arr, beg, mid1, mid2, endn)
  temp=[]
  i=beg; j=mid2
  while (true)
    if (i>mid1 || j>endn)
      break
    end
    if (arr[i]<=arr[j])
      push!(temp,arr[i])
      i+=1; continue
    else
      push!(temp,arr[j])
      j+=1; continue
    end
  end
  while (i<=mid1)
    push!(temp,arr[i])
    i+=1
  end
  while(j<=endn)
    push!(temp,arr[j])
    j+=1
  end
  j=1
  for i in beg:endn
    arr[i]=temp[j]
    j+=1
  end
end


function pungi(arr,l,r)
  if (l<r)
    pungi(arr,l,div((l+r),2))
    pungi(arr,(1+div((l+r),2)),r)
    man(arr,l,div((l+r),2),div((l+r),2)+1,r)
  end
end



arr=map(x->parse(Int,x),split(readline(STDIN)))
arr=arr[2:end-1]
n=size(arr)[1]
tic()
pungi(arr,1,n)
#println(arr)
toc()
