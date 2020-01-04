from queue import *
from stack import *
from binary_tree import *
class tree:
   def __init__(self,x):
      self.store = [x,[]]

   def AddSuccessor(self,x):
      self.store[1] = self.store[1] + [x]
      return True

   def Print_DepthFirst(self):
      space = "   "
      n=0
      print(space*n + str(self.store[0]))
      n=1
      for i in self.store[1]:
         i.Print_Helper(n)
      return True
   
   def Print_Helper(self,n):
      space = "   "
      print(space*n + str(self.store[0]))
      for i in self.store[1]:
         i.Print_Helper(n+1)
      return True
   
   def Get_LevelOrder(self):
      lists=[]
      a=Queue()
      a.enqueue(self)
      while(a.empty() == False):
         r=a.dequeue()
         lists = lists + [r.store[0]]
         for i in r.store[1]:
            a.enqueue(i)
      print(lists)
      return True

   def ConvertToBinaryTree(self):
      bi=binary_tree(self)
      value = self.store[0]
      nextlist = self.store[1]
      bi.store[0] = value
      bi.AddLeft(self.binaryhelp(nextlist))
      return bi

   def binaryhelp(self, gentree):
      if gentree != []:
         left = gentree[0]
         right = gentree[1:]
         root = binary_tree(left.store[0])
         lb = self.binaryhelp(left.store[1])
         rb = self.binaryhelp(right)
         root.AddLeft(lb)
         root.AddRight(rb)
         return root
      else:
         return("null")
