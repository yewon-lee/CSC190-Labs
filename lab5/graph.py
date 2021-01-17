class stack:
	def __init__(self):
		self.storage = []
		self.count = 0
	def empty(self):
		if(self.count==0):
			return True
		else:
			return False
	def store(self,x):
		self.storage = self.storage + [x]
		self.count = self.count + 1
		return True
	def retrieve(self):
		if(self.count==0):
			return [False,0]
		else:
			self.count = self.count - 1
			rval = self.storage[-1]
			self.storage = self.storage[0:-1]
			return [True,rval]	
class queue:
	def __init__(self):
		self.storage = []
		self.cnt = 0	
	def empty(self):
		if (self.cnt==0):
			return True
		else:
			return False
	def store(self,value):
		self.storage = self.storage + [value]
		self.cnt = self.cnt + 1
		return self.cnt
	def retrieve(self):
		if (self.cnt==0):
			return [False,0]
		else:
			r = self.storage[0]
			self.cnt = self.cnt-1
			self.storage = self.storage[1:]
			return [True,r]	

class graph:
	def __init__(self):
		self.store = []

	def printEdges(self):
		print self.store

	def addVertex(self,n):
		if(n<=0):
			return -1
		else:
			for i in range(0,n):
				self.store = self.store + [[]]
			return len(self.store)

	def addEdge(self,from_idx,to_idx,directed,weight):
		if(from_idx<0 or to_idx<0):
			return False
		elif(from_idx>=len(self.store) or to_idx>=len(self.store)):
			return False
		elif(directed<>True and directed<>False):
			return False
		elif(weight==0):
			return False
		else:
			if (directed == True):
				self.store[from_idx] = self.store[from_idx]+[[to_idx,weight]]
			elif (directed == False):
				self.store[from_idx] = self.store[from_idx]+[[to_idx,weight]]
				self.store[to_idx] = self.store[to_idx]+[[from_idx,weight]]
			return True

	def traverseStartIsNone(self,start,typeBreadth):
		accum = []
		if (typeBreadth==True):
			C = queue()
		elif(typeBreadth==False):
			C = stack()
		Discovered = [False]*len(self.store)
		Processed = [False]*len(self.store)	 
		for i in range(0,len(self.store)): # i is the vertex, ie the idx for self.store
			miniaccum = []
			if (Discovered[i]==False):
				C.store(i)
			while(C.empty()==False):
				w = C.retrieve()
				if(Processed[w[1]]==False):	
					miniaccum = miniaccum + [w[1]]
					Processed[w[1]] = True
				for j in self.store[w[1]]:
					if (Discovered[j[0]]==False):
						C.store(j[0])
						Discovered[j[0]] = True
			
			if(len(miniaccum)>0):
				accum = accum + [miniaccum]
			else:
				accum = accum
		return accum
    
	def traverseStartIsSpeced(self,start,typeBreadth):
                accum = []
                if (typeBreadth==True):
                        C = queue()
                elif(typeBreadth==False):
                        C = stack()
                Discovered = [False]*len(self.store)
                Processed = [False]*len(self.store)
                for i in range(start,len(self.store)): # i is the vertex, ie the idx for self.store
                        miniaccum = []
                        if (Discovered[i]==False):
                                C.store(i)
                        while(C.empty()==False):
                                w = C.retrieve()
                                if(Processed[w[1]]==False):
                                        miniaccum = miniaccum + [w[1]]
                                        Processed[w[1]] = True
                                for j in self.store[w[1]]:
				#	print([w[1],j[0]])
				#	print(len(Discovered))
                                        if (Discovered[j[0]]==False):
                                                C.store(j[0])
                                                Discovered[j[0]] = True
                        if(len(miniaccum)==0):
				accum = accum 
			else:
				accum = accum + [miniaccum]
		return accum

	def traverse(self,start,typeBreadth):
		if (typeBreadth<>True and typeBreadth<>False):
			print"A"
			#print"here"
			return []
#		elif (start<0 or start>=len(self.store)):
#			#print"here"
#			return []
		elif(start==None):
			#print"HEREEE"
			return self.traverseStartIsNone(start,typeBreadth)
		elif(start>=0 and start<len(self.store)):
			return self.traverseStartIsSpeced(start,typeBreadth)
		elif (start<0 or start>=len(self.store)):
                        #print"here"
                        return []

	def connectivity(self,vx,vy):
		if(vx>=len(self.store) or vy>=len(self.store)):
			return [False,False]
		elif(vx<0 or vy<0):
			return [False,False]
		connectedA = -1
		for i in self.store[vx]:
			if(i[0]==vy):	
				connectedA = 0
		if (connectedA==-1):
			idx0 = False
		elif(connectedA==0):
			idx0 = True
		connectedB = -1
		for i in self.store[vy]:
			if(i[0]==vx):
				connectedB = 0
		if(connectedB==-1):
			idx1 = False
		elif(connectedB==0):
			idx1 = True
		return [idx0,idx1]

	def path(self,vx,vy):
		return []
 
				
		
