class counter:
   def __init__(self, initCnt):
      self.cnt = initCnt
   def evolve(self,x):
      self.cnt = self.cnt + x
      return True
   def getState(self):
      return self.cnt
myCnt=counter(100)
x=counter(1000)
y=counter(50)
print(myCnt.cnt)
print(x.cnt)
print(y.cnt)
myCnt.evolve(2)
x.evolve(4)
y.evolve(6)
print(myCnt.getState())
print(x.getState())
print(y.getState())
