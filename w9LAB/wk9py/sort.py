def bubbleSort(array):
   n=len(array)
   rval=list(array)
   swapped = True
   if n<1:
      return[swapped,rval]
   check=0
   for a in array:
      if type(a)==int:
         check = check +1
   if check<len(array):
      return[False,rval]
   i=0
   hold=0
   while swapped:
      while i<n-1:
         k=rval[i]
         l=rval[i+1]
         if l>k:
            rval[i]=k
            rval[i+1]=l
            i=i+1
         elif l<k:
            rval[i]=l
            rval[i+1]=k
            hold=hold+1
            i=i+1
         elif l==k:
            i=i+1
      if hold>0:
         swapped=True
         i=0
         hold=0
      elif hold<1:
         swapped=False
   return[True,rval]
