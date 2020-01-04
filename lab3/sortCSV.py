# This is an example of a program that will take in arguments.
# It is best to name your arguments rather than relying on position;
# this enables a user to use your program without memorizing
# argument order. This is a standard industrial practice.
# Below, you see that there are two named arguments that each take
# an additional parameter:
# --fin <ADDITIONAL-PARAM> --fout <ADDITIONAL-PARAM>
# This may be used in a program that takes in the name of
# an input and output file, in order to do further processing.
# You may modify this template for your purposes.
#
# The loop that is iterating over all the input arguments begins at
# 1, since sys.argv[0] is always the name of the program
# (in this case, "argtest.py", unless you renamed it).
# The loop is incrementing one arg at a time; since --fin and --fout
# take an additional argument, I created a variable called "skip"
# that enables you to skip over the filename during the looping
# since the --fin and --fout processing will always look at and
# consume the next argument. Note that I test to ensure
# --fin or --fout always have a trailing argument. Otherways, the
# program will give an "out of range" warning.
#
# This is course content. You must understand this. To understand this
# use it, modify it and experiment with it.
#
# usage: python argtest.py --fin blah_in --fout blah_out
# where you may change the names blah_in and blah_out as needed
#
# mathaine@ecf.utoronto.ca


import sys

CSVFILE_IN=""
CSVFILE_OUT=""
COLUMNNUMBER=""
DIR=""
nargs=len(sys.argv)
skip=False
for i in range(1,nargs):
   if not skip:
      arg=sys.argv[i]
      print("INFO: processing",arg)
      if arg == "--fin":
         if i != nargs-1:
            CSVFILE_IN=sys.argv[i+1]
            skip=True
      elif arg == "--fout":
         if i != nargs-1:
            CSVFILE_OUT=sys.argv[i+1]
            skip=True 
      elif arg == "--col": 
         if i != nargs-1:
            COLUMNNUMBER=sys.argv[i+1]
            skip=True
      elif arg == "--dir":
         if i != nargs-1:
            DIR=sys.argv[i+1]
            skip=True
      else:
         print("ERR: unknown arg:",arg)
   else:
      skip=False

print("INFO: CSVFILE_IN",CSVFILE_IN)
print("INFO: CSVFILE_OUT",CSVFILE_OUT)

f=open(CSVFILE_IN, 'r')
lines=f.readlines()
f.close()
accum=[]
for i in lines:
   j=i.split("\n")[0]
   k=j.split(",")
   r=[]
   for x in k:
      r = r + [float(x)]
   accum = accum + [r]
while True:
   try:
      COLUMNNUMBER = int(COLUMNNUMBER)
   except:
      print("Error, column number must be an integer")
      break
   if COLUMNNUMBER >= len(accum[0]):
      print("Error, column value is too large")
      break
   elif COLUMNNUMBER < 0:
      print("Error, column value is too small")
      break
   else:
      def genSortKey(col,up):
           def key(x):
               return x[col] if up=='+' else -x[col]
           return key
      myKey=genSortKey(COLUMNNUMBER,DIR)
      sortaccum = sorted(accum, key=myKey)

      g=open(CSVFILE_OUT,'w')
      for i in sortaccum:
          n = 0
          for k in i:
            g.write(str(k))
            n = n + 1
            if n != len(i):
               g.write(',')
            if n == len(i):
               g.write('\n')
      break
         
            
      
