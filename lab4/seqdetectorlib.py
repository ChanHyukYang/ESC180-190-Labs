class seqdetector:
   def __init__(self):
      self.x = ['','','','','','','','']
   def evolve(self,word):
      self.x = self.x[1:len(self.x)] + [word]
      if str(self.x[0]) + str(self.x[1]) +  str(self.x[2]) + str(self.x[3]) + str(self.x[4]) + str(self.x[5]) + str(self.x[6])+ str(self.x[7]) == "herearethesolutionstothenextexam":
         return True
      else:
         return False
