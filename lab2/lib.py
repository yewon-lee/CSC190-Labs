class lib:
	def __init__(self):
		self.store = []

	def push(self,x):
		self.store = self.store + [x]	
	
	def print_self(self,accum):
		print self.store
		accum = accum + self.store
		return self.store
