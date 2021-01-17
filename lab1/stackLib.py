class stack:
	
	def __init__(self):
		self.store = []
	
	def push(self,value):
		self.store = [value] + self.store 
		#print self.store
		return True

	def pop(self):
		accum = []
		for i in range (1,len(self.store)):
			accum = accum + [self.store[i]]
		self.store = accum
		#print self.store
		return True
	def print_it(self):
		print self.store
		return True
	def isNULL(self):
		if (len(self.store) == 0):
			return True
		else:
			return False
	def popped_val(self):
		x = self.store[0]
		#print x
		return x

#x = stack()
#x.push('[')
#x.push('{')
#x.push(']')
#x.push(')')
#x.print_it()
#print('the val that will pop now is')
#print x.popped_val()
#x.pop()
#x.print_it()
#x.pop()
#x.print_it()
#x.pop()
#x.print_it()
#x.pop()
#x.print_it()

	
