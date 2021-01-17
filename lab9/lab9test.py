from lab9 import *

v1 = [10,9,8,7,6,5,4,3,2,1,0]
v2 = [100,1,1000,9,8,7,2,2000,10]
v3 = [100,10,1000,9,7,6,5,2,3,1]

for i in [v1,v2,v3]:
	x = list(i)
	quick_sort(x,0,len(x)-1)
	print x

start = [1,2,3]
tmp = []
final = []	
hanoi(3,start,tmp,final)
