def quicksort(listn,start,end):
   if start<end:
      part = partition(listn,start,end)
      quicksort(listn,start,part-1)
      quicksort(listn,part+1,end)
   return True

def partition(listn,start,end):
   index = start-1
   pivot = listn[end]
   for i in range(start,end+1):
      if listn[i] <= pivot:
         index = index + 1
         listn[i],listn[index] = listn[start],listn[i]
   return index

def hanoi(n,start,tmp,final):
   if n > 0:
        hanoi(n - 1,start,final,tmp)
        final.append(start.pop())
        hanoi(n - 1,tmp,start,final)
        print (start,tmp,final)
        return True
   else:
        return True
