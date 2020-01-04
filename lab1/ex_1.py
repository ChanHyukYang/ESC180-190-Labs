class check:
   def __init__(self, string):
      self.str = string

   def check(self):
      list = []
      for i in self.str:
         if i == "(":
            list = list + [i]
         elif i == "[":
            list = list + [i]
         elif i == "{":
            list = list + [i]
      for i in self.str:
         if i == ")":    
            for n in list:
               if n == "(":
                  list[n] = 0
                     break
         elif i == "]":    
            for n in list:
               if n == "(":
                  list[n] = 0
                     break
         elif i == "}":    
            for n in list:
               if n == "(":
                  list[n] = 0
                     break
      for i in list:
         if i != 0:
            return False
      return True
      
