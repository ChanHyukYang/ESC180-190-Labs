def selection_sort(u):
   counter = 0
   while True:
      min = u[counter]
      oldplace = counter
      for i in range(counter,len(u),1):         
         if u[i] < min:
            min = u[i]
            oldplace = i
      hold = u[counter]
      u[counter] = min
      u[oldplace] = hold
      if counter == len(u) -1:
         break
      counter = counter + 1
   return True
def selection_sort(u):
   counter = 0
   while True:
      min = u[counter]
      oldplace = counter
      for i in range(counter,len(u),1):
         if u[i] < min:
            min = u[i]
            oldplace = i
      hold = u[counter]
      u[counter] = min
      u[oldplace] = hold
      if counter == len(u) -1:
         break
      counter = counter + 1
   return True

def heapify(u):
   heap = []
   for val in u:
      heap = heap + [val]
      pos = len(heap)-1
      while True:
         if pos % 2 == 1:
            key = int((pos-1)/2)
            if key < 0:
               break
            if heap[key] > heap[pos]:
               hold = heap[key]
               heap[key] = heap[pos]
               heap[pos] = hold
               pos = key
            elif heap[key] < heap[pos]:
               break
         elif pos % 2 == 0:
            key = int((pos-2)/2)
            if key < 0:
               break
            if heap[key] > heap[pos]:
               hold = heap[key]
               heap[key] = heap[pos]
               heap[pos] = hold
               pos = key
            elif heap[key] < heap[pos]:
               break         
   u[:] = heap[:]
   return True

def reheapify(u,end):
   subList = u[end:]
   heapify(subList)
   u[end:] = subList
   return True
def heap_sort(u):
   pos = 0
   heapify(u)
   end = len(u)
   for i in range(1,len(u),1):
      reheapify(u, i) 
   return True
def sorthelper(l,r):
   new=[]
   lcount=0
   rcount=0
   while True:
      if (len(new))==(len(l))+(len(r)):
         return new
      print(r)
      print(l)
      print(rcount)
      print(lcount)
      if lcount<len(l):
         if rcount<len(r):
            if l[lcount]<r[rcount]:
               new=new+[l[lcount]]
               lcount = lcount + 1
         else:
            new=new+[l[lcount]]
            lcount=lcount+1
      if rcount<len(r):
         if lcount<len(l):
            if r[rcount]<l[lcount]:
               new=new+[r[rcount]]
               rcount = rcount + 1 
         else:
            new=new+[r[rcount]]
            rcount = rcount + 1
def merge_sort(u):
   if len(u) == 1:
      return True
   i = len(u)//2
   j = len(u) - i
   left = u[0:i]
   right = u[i:len(u)]
   merge_sort(left)
   merge_sort(right)
   u[:] = sorthelper(left,right)
   return True

