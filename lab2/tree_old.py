from lib import lib 


def convert_list(L):
	Lcopy = L
	while True:
		score = 0
		for i in range (0,len(Lcopy)):
			if (type(Lcopy[i]) == int):
				score = score + 0
			else:
				score = score + 1
		if (score == 0):
			break
		else:	
			for k in range(0,len(Lcopy)):
				if (type(Lcopy[k]) == int):
					Lcopy = Lcopy 
				elif (type(Lcopy[k]) == list):
					if (len(Lcopy) == k+1):
						Lcopy = Lcopy[0:k] + Lcopy[k][0:len(Lcopy[k])]
					else:
						Lcopy = Lcopy[0:k] + Lcopy[k][0:len(Lcopy[k])] + Lcopy[k+1:len(Lcopy)]	
	print Lcopy
	return True		

def print_it(L):
	for i in range(0,len(L)):
		if (type(L[i]) == int):
			print(L[i])
		else:
			return print_it(L[i])
	return True
	

class tree:
	
	def __init__(self,x):
		self.store = [x,[]]
		self.n = 0
	
	def AddSuccessor(self,x):
		self.store[1] = self.store[1] + [x]
		x.n = self.n + 1
		return True
	
	def Print_DepthFirst(self):
		accum = ''
		for j in range(0,self.n):
			accum = accum + '	'
		print accum + str(self.store[0])
		for i in range(0,len(self.store[1])):
			x = self.store[1][i]
			#print('B')
			x.Print_DepthFirst()
		#print('how many times were we here??')
		return True
			
#	def convert_list(self):
#		x = lib()
#		x.push([self.n,self.store[0]])
#		cnt = 0
#		for i in range(0,len(self.store[1])):
#			y = self.store[1][i]
			#accum2 = accum
	#		cnt = 1
#			y.convert_list()
		
	#	if (cnt == 0):
			#accum2 = accum2 + accum
	#		x.print_self()	
	#		return True
	
#	def convert_diff(self):
#		Lcopy = list(self.store)
#		while True:
#			score = 0
#			for i in range(0,len(Lcopy)):
#				if (type(Lcopy[i]) == int):
#					score = score + 0
#				else:
#					score = score + 1
#			if (score == 0):
#				break	
#			else:
#				for k in range(0,len(Lcopy)):
#					if (type(Lcopy[k]) == int):
#						Lcopy = Lcopy
#					else:
#						if (len(Lcopy[k]) == k+1):
#							Lcopy = Lcopy[0:k] + Lcopy[k][0:len(Lcopy[k])]
#						else:
#							Lcopy = Lcopy[0:k] + Lcopy[k][0:len(Lcopy[k])] + Lcopy[k+1:len(Lcopy)]
#		print Lcopy
#		return True

#	def find_by_level(self,level):
#		if (level == 0):
#			return [self.store[0]]
#		elif(level == 1):
#			accum = []
#			for i in range(0,len(self.store[1])):
#				accum = accum + [self.store[1][i].store[0]]
#		elif (level == 2):
#			accum = []
#			for i in range(0,len(self.store[1])):
#				for j in range(0,len(self.store[1][i].store[1])):
#					accum = accum + [self.store[1][i].store[1][j]]
#			return accum
#		else:
#			x = self.store[0][1]
#			x.find_by_level()
		
#	def Get_LevelOrder(self,accum,N):
#		cnt = 0
#		for i in range(0,len(self.store[1])):
#			cnt = 1
#			x = self.store[1][i]
#			if (x.n == N):
#				accum = accum + self.store[i]
#				score = score + 1
#			else:
#				score = score + 0
#			if (score == 0):
#				N = N + 1
#				x = self.store
#				return x.Get_LevelOrder(accum,N)
#		if (cnt == 0):
#			print accum
		
                            
	
							
				
x = tree(1000)
y = tree(2000)
z = tree(3000)
s = tree(4000)
x.AddSuccessor(y)
x.AddSuccessor(z)
x.AddSuccessor(s)

c = tree(5)
a = tree(6)
b = tree(7)
d = tree(8)
z.AddSuccessor(c)
z.AddSuccessor(a)
y.AddSuccessor(b)
s.AddSuccessor(d)

#status = x.Print_DepthFirst()
#print('the status is'+str(status))
Z = []
Y = []
x.convert_diff()
#x.Get_LevelOrder(Z)






