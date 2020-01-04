def fibo(n):
    if n == 0:
        return 1
    elif n == 1:
        return 1
    else:
        return fibo(n-1) + fibo(n-2)
def fiboL(n):
    fiblist = []
    for i in range(0,n+1,1):
        fiblist = fiblist + [fibo(i)]
    return fiblist

def reduceSum(a,b):
   return a * b

def reduce(func,M):
   if len(M) == 1:
      return M[0]
   elif len(M) == 2:
      return func(M[0], M[1])
   else:
      return func(M[0], reduce(func,M[1:]))
def redfibo(n):
   return reduce(reduceSum, fiboL(n))
