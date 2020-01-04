class Queue:
   def __init__(self):
      self.store=[]
   def enqueue(self,val):
      self.store = self.store + [val]
      return True
   def dequeue(self):
      r = self.store[0]
      self.store = self.store[1:len(self.store)]
      return r
   def empty(self):
      if self.store == []:
         return True
      elif self.store != []:
         return False


