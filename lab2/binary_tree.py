class binary_tree:
	
	def __init__(self,x):
		self.store = [x,[]]
		self.n = 0
	
	def AddLeft(self,x):
		self.store[1] = [x] + self.store[1]
		x.n = self.n + 1
		return True

	def AddRight(self,x):
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
			x.Print_DepthFirst()
		return True

	def ConvertToTree(self):
		if (len(self.store[1]) > 1):
			print('the length of self.store is ' + str(len(self.store[1])))
			return [False]
		else:
			return [True,self.store]


#x = binary_tree(1000)
#y = binary_tree(2000)
#z = binary_tree(3000)
#x.AddLeft(y)
#x.AddRight(z)
#c = binary_tree(5)
#z.AddRight(c)

#x.Print_DepthFirst()

#print('convert to tree yields the result: ')
#print x.ConvertToTree()

