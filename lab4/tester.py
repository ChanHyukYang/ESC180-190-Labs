from seqdetectorlib import *
words_list=['blah','here','are','the','solutions','to','the','next','exam','blah','here','are','the','solutions','to','the','next','exam']
def main():
   x=seqdetector()
   n=0
   for i in words_list:
      status=x.evolve(i) 
      if status == True:
         print ("Detected: end position is",n)
      n = n+1
   return True
main()
