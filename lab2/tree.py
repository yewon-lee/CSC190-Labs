from queue import queue 
from binary_tree import binary_tree

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

	def Get_LevelOrder(self):		
		Q = queue()
		Q.enqueue(self.store)
		accum = []
		while (Q.Empty() == False):
			node = Q.dequeue()
			#print ('the node[0] is ',str(node[0]))
			#print node
			accum = accum + [node[0]]
			for i in range(0,len(node[1])):
				Q.enqueue(node[1][i].store)
		#print accum
		print accum
		return accum
	
	
#	def ConvertToBinaryTree(self):
#		BT = binary_tree(self.store[0])
#		BT.Print_DepthFirst()
#		if (type(self.store[1][0].store[0]) == int):
#			print('A')
#			X = binary_tree(self.store[1][0].store[0])
#			BT.AddLeft(X)
#			print('B')
#			Y = binary_tree(self.store[1][0].store[1][0].store[0])
#			print('C')
#			return Y.AddLeft(X)
#		print('we are here')
#		BT.Print_DepthFirst()

#	def getDepth(self):
#		Q = queue()
#		Q.enqueue(self.store)
#		accum = []
#		while (Q.Empty() == False):
#			node = Q.dequeue()
#			accum = accum + [[node[0],node[1][0].n-1]]
#			for i in range(0,len(node[1])):
#				Q.enqueue(node[1][i].store)
		
	
	def getFirstLeaf(self):
		X = self.store
		depth = X.getDepth()
		copyTree = list(self.store)
		for i in range(0,depth):
			copyTree = copyTree[1][0].store
		return copyTree

	def Gen_BinaryTree_helper(self,Siblings):
		Root = self.store[0]
	

	def ConvertToBinaryTree(self):
		return self.store
		





#x = tree(1000)
#y = tree(2000)
#z = tree(3000)
#s = tree(4000)
#x.AddSuccessor(y)
#x.AddSuccessor(z)
#x.AddSuccessor(s)

#c = tree(5)
#a = tree(6)
#b = tree(7)
#d = tree(8)
#z.AddSuccessor(c)
#z.AddSuccessor(a)
#y.AddSuccessor(b)
#s.AddSuccessor(d)

#x.ConvertToBinaryTree()
#x.Print_DepthFirst()
#x.Get_LevelOrder()

#x.getDepth()





