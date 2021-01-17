# everything sorts in ascending order

def helper_find_highest(u,end):
	highidx = 0
	for i in range (1,end):
		if (u[i]>u[highidx]):
			highidx = i
		else:
			highidx = highidx
	return highidx

def selection_sort(u):
	for i in range(0,len(u)):
		#find lowest 
		end = len(u)-i
		highest = helper_find_highest(u,end)
		temp = u[end-1]
		u[end-1] = u[highest]
		u[highest] = temp
	return True

# we need a max heap
def heapify(u):
	heap = []
	for i in range(0,len(u)):
		heap = heap + [u[i]]
		temp = len(heap)-1
		while True:
			if(temp==0):
				break
			elif(heap[temp]>heap[temp-1]):
				important = heap[temp]
				heap[temp] = heap[temp-1]
				heap[temp-1] = important
				temp = temp - 1
			elif(heap[temp]<=heap[temp-1]):
				break
	for j in range(0,len(u)):
		u[j] = heap[j]
	return True

def reheapify(u,end):
	dummy = u[0:end] # end is non inclusive
	heapify(dummy)
	u[0:end] = dummy
	return True

def heap_sort(u):
	accum = []
	heapify(u)
	for i in range(0,len(u)):
		end = len(u)-i-1
		temp = u[end]
		u[end] = u[0]
		u[0] = temp
		reheapify(u,end)
	return True

def helper_merge(a,b):
	na = len(a)
	nb = len(b)
	n = na + nb
	ia = 0
	ib = 0
	u = [None]*n
	for i in range(0,n):
		#print("i equals "+str(i)+" u looks like: "+str(u))
		if (ia>=na):
			u[i] = b[ib]
			ib = ib + 1
		elif (ib>=nb):
			u[i] = a[ia]
			ia = ia + 1	
		elif (a[ia]<=b[ib]):
			u[i]=a[ia]
			ia = ia + 1
		elif (b[ib]<a[ia]):
			u[i] = b[ib]
			ib = ib + 1			
	return u
		
def merge_sort(u):
	if (len(u)>1):
		half = len(u)/2
		a = u[0:half]
		b = u[half:len(u)]
		merge_sort(a)
		merge_sort(b)
		rlist = helper_merge(a,b)
		for i in range(0,len(u)):
	#		print(u[i])
			u[i] = rlist[i]
		
	
	




