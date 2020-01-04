def traverse_breadth(T):
   x=Queue()
   x.enqueue(T)
   while x.empty() == False:
      r=x.dequeue()
      print(r[0])
      for i in r[1:len(r)]:
         x.enqueue(i)
#I would create the class for a tree, making a Queue function to initialize the list for one, making a method empty to check if the list is empty, returning False if this is not the case, and a method enqueue which would add some integer i into the storing mechanism in class for the class.
