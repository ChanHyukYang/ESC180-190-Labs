import stackLib

def bc(string):
   n=stack()
   j = 0
   for i in string:
      if i == "(":
         n.push("(")
      elif i == "{":
         n.push("{")
      elif i == "[":
         n.push("[")
      elif i == ")":
         n.pop()
         if r != "(":
            return [False,j]
      elif i == "}":
         n.pop()
         if r != "{":
            return [False,j]
      elif i == "]":
         n.pop()
         if r != "[":
            return [False,j]
      j=j+1
   if len(n.item) != 0:
      return [False,j]
   return [True,0]

