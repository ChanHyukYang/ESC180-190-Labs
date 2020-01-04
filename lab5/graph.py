class Queue:
   def __init__(self):
      self.store=[]
   def add(self,val):
      self.store = self.store + [val]
      return True
   def dele(self):
      r = self.store[0]
      self.store = self.store[1:len(self.store)]
      return r
   def empty(self):
      if self.store == []:
         return True
      elif self.store != []:
         return False
class stack:
   def __init__(self):
      self.store=[]
   def add(self,value):
      self.store = self.store + [value]
      return True
   def dele(self):
      r=self.store[-1]
      self.store=self.store[0:len(self.store)-1]
      return r
class graph:
   def __init__(self):
      self.store = []
   def addVertex(self,n):
      counter = 0
      if n < 0:
         return -1
      for i in range(0,n,1):
         self.store=self.store+[[]]
      for i in self.store:
         counter = counter + 1
      return counter
   def addEdge(self,from_idx,to_idx,directed,weight):
      if directed == True:
         self.store[from_idx] = self.store[from_idx] + [[to_idx,weight]]
      elif directed == False:
         self.store[from_idx] = self.store[from_idx] + [[to_idx,weight]]
         self.store[to_idx] = self.store[to_idx] + [[from_idx,weight]]
      elif directed != False and directed != True:
               return False
      return True
   def traverse(self,start,typeBreadth):
      final = []
      if typeBreadth == True:
         C=Queue()
      if typeBreadth == False:
         C=stack()
      discovered = []
      processed = []
      for i in self.store:
         discovered = discovered + [False]
         processed = processed + [False]
      if start != None and (start <0 or start > len(self.store)):
         return False
      if start == None:
         for i in range(0,len(self.store),1):
            if discovered[i] == False:
               C.add(i)
               discovered[i] = True
            hold = []
            while len(C.store) != 0:
               w = C.dele()
               if processed[w]==False:
                  hold = hold + [w]
                  processed[w]=True
               for j in self.store[w]:
                  if discovered[j[0]] == False:
                     C.add(j[0])                     
                     discovered[j[0]]=True
            final = final + [hold]
      elif start != None:
         discovered[start] = True
         C.add(start)
         hold = []
         while len(C.store) != 0:
            w = C.dele()
            if processed[w]==False:
               hold = hold + [w]
               processed[w]=True
               for j in self.store[w]:
                  if discovered[j[0]] == False:
                     C.add(j[0])
                     discovered[j[0]]=True
         final = final + hold
      return final
      
   def connectivity(self,vx,vy):
      final = []
      x = traverse(vx, False)
      y = traverse(vy, False)
      if vy in x:
         final = final + [True]
      elif vy not in x:
         final = final + [False]
      if vx in y:
         final = final + [True]
      elif vx not in y:
         final = final + [False]
      return final
   def path(self,vx,vy):
      final = []
      pathx = []
      pathy = []
      x = traverse(vx,False)
      y = traverse(vy,False)
      for i in range(0,len(x),1):
         pathx = pathx + x[i]
         if x[i] == vy:
            final = final + pathx
            break
      if len(final) == 0:
         final = final + []
      for i in range(0,len(y),1):
         pathy = pathy + y[i]
         if y[i] == vx:
            final = final + pathy
            break
      if len(final) == 0:
         final = final + []
      return final
