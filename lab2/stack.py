class stack:
   def __init__(self):
      self.item=[]
   def push(self,value):
      self.item = self.item + [value]
      return True
   def pop(self):
      r=self.item[-1]
      self.item=self.item[0:len(self.item)-1]
      return r


