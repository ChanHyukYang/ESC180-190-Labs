def sortr(L):
	return(recur_sortr(L, 0))

def recur_sortr(L, i):
	table = [[]]*10

	left = False
	for x in L:
		value = (x//(10**i))%10
		table[value] = table[value] + [x]
		if x//(10**i) > 0: 
			left = True

	LO = []
	for n in table:
		for x in n:
			LO += [x]
			
	L[:] = LO
	if left: 
		return(recur_sortr(L, i+1))
	else: 
		return(L)
