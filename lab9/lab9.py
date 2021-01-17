def partition(u,ini,fin):
	pIndex = fin
	firsthigh = ini
	for i in range(ini,fin):
		if (u[i] < u[pIndex]):
			temp = u[i]
			u[i] = u[firsthigh]
			u[firsthigh] = temp
			firsthigh = firsthigh + 1
	temp = u[pIndex]
	u[pIndex] = u[firsthigh]
	u[firsthigh] = temp
	return firsthigh

def quick_sort(u,ini,fin):
	if ((fin-ini)>0):
		pIndex = partition(u,ini,fin)
		quick_sort(u,ini,pIndex-1)
		quick_sort(u,pIndex+1,fin)
	return True

def hanoi(n, start, tmp, final):
	if (n>0):
		hanoi(n-1,start, final, tmp)
		final.append(start.pop())
		hanoi(n-1,tmp,start,final)
		print start,tmp,final
		return True
	else:
		return True
	
