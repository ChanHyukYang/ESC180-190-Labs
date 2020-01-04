from stack import *
from queue import *
from tree import *
class binary_tree:
   def __init__(self,val):
      self.store = [val,"null","null"]
   def AddLeft(self, val):
      self.store[1] = val
      return True
   def AddRight(self, val):
      self.store[2] = val
      return True
   def Get_LevelOrder(self):
      lists = []
      a=Queue()
      a.enqueue(self.store)
      while(a.empty()==False):
         r=a.dequeue()
         if type(r)==int:
            lists = lists +[r]
         elif type(r)==list:
            lists = lists + [r[0]]
            for h in r[1:]:
               a.enqueue(h)
         elif type(r) != str:
            lists = lists + [r.store[0]]
            for h in r.store[1:]:
               a.enqueue(h)  
      print(lists)
      return True

   def ConvertToTree(self):
      if self.store[2] != "null":
         return(False,[])
      elif self.store[1] == "null":
         root = self.store[0]
         convertedtree = tree(val)
         return(True, convertedtree)
      else:
         root = self.store[0]
         branches = self.store[1]
         convertedtree = tree(root)
         for i in self.converterhelper(branches):
            convertedtree.AddSuccessor(i)
         return(True, convertedtree)

   def convertedtree(self,branches):
      if type(branches) == int:
         node = tree(branches)
         return node
      else:
         node = tree(branches[0])
         lnode = branches.store[1]
         rnode = branches.store[2]
      if lnode != "null":
         for h in self.convertedtree(lnode):
            node.AddSuccessor(i)
      if rnode != "null":
         return([node] + self.convertedtree(rnode))
      else:
         return([node])
