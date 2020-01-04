def fibo(n):
   if n == 0:
      return 1
   elif n == 1:
      return 1
   else:
      return fibo(n-1) + fibo(n-2)

for i in range(0,10,1):
   print(fibo(i))

