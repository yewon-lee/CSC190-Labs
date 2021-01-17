from stackLib import stack

def bc(string):

	cnt = -1
	printed = 0
	x = stack()
	L = []
	fail = False
	#print('hello world')

	while True:
	
	# the first if statement deals with the case where string has one element
		if (len(string) == cnt+2):
			#print ('hello world 1')
			if (string[cnt+1] == '(' or string[cnt+1] == '[' or string[cnt+1] == '{'):
				x.push(string[cnt+1])
				cnt = cnt +1;
				fail = True
				break
			elif (string[cnt+1] == ')'):
				if (x.isNULL() == True):
					cnt = cnt + 1
					fail = True
					break
				elif (x.isNULL() == False and x.popped_val() == '('):
					x.pop()
					cnt = cnt + 1
					fail = False
					break
				else:
					cnt = cnt + 1
					fail = True
					break
			elif (string[cnt+1] == ']'):
				if (x.isNULL() == True):
                                        cnt = cnt + 1
                                        fail = True
					#print("here dudee\n")
					break
                                elif (x.popped_val() == '[' and x.popped_val() == '['): #actually elif (x.isNULL() == False and x.popped_val() == '[')
                                        x.pop()
                                        cnt = cnt + 1
					fail = False
                                        break
                                else:
                                        cnt = cnt + 1
					fail = True
					#print('nah we here\n')
                                        break
			elif (string[cnt+1] == '}'):
				if (x.isNULL() == True):
                                        cnt = cnt + 1
					fail = True
                                        break
                                elif (x.isNULL() == False and x.popped_val() == '{'):
                                        x.pop()
                                        cnt = cnt + 1
					fail = False
                                        break
                                else:
                                        cnt = cnt + 1
					fail = True
                                        break
			else:
				cnt = cnt + 1;
				break
		
	# second case: string is at more than one element
		elif (len(string) <> cnt + 2):
			#print ('hello world 2')
			if (string[cnt+1] == '(' or string[cnt+1] == '[' or string[cnt+1] == '{'):
				#print('hw A')
				x.push(string[cnt+1])
				cnt = cnt + 1
				#print ('here A')
			elif (string[cnt+1] == ')'):
				#print('hw B')
				if (x.isNULL() == True):
					cnt = cnt + 1
					fail = True
					break
				elif (x.popped_val() == '('):
					x.pop()
					cnt = cnt + 1
					#print('here B')
				else:
					cnt = cnt + 1
					fail = True
					break
			elif (string[cnt+1] == ']'):
				#print ('hw C')
				if (x.isNULL() == True):
                                        cnt = cnt + 1
                                        fail = True
					#print("we here")
                                        break
                                elif (x.popped_val() == '['):
                                        x.pop()
                                        cnt = cnt + 1
					#print('here C')
                                else:
                                        cnt = cnt + 1
                                        fail = True
					#x.print_it()
					#x.popped_val()
					#print("nah we here dude :)")
                                        break
			elif (string[cnt+1] == '}'):
				#print('hw D')
				if (x.isNULL() == True):
					cnt = cnt + 1
                                        fail = True
                                        break
                                elif (x.popped_val() == '{'):
                                        x.pop()
                                        cnt = cnt + 1
					#print('here D')
                                else:
                                        cnt = cnt + 1
                                        fail = True
                                        break
			else:
				cnt = cnt + 1
	if (fail == True):
		L = [False] + [cnt]
		#print L
		return L
	elif (fail == False):
		L = [True] + [0]		
		#print L
		return L


#print bc(')')	
#print bc('()')
#print bc('(]')
#print bc('([])')
#print bc('([{[{}]}])')
#print bc('][{[{}]}])')
#print bc('(]{[{}]}])')
#print bc('([}[{}]}])')
#print bc('([{){}]}])')
#print bc('([{[)}]}])')
#print bc('([{[{)]}])')
#bc('([{[{)]}])')	
#print bc('([{[{})}])')
#print bc('([{[{}])])')
#print bc('([{[{}]})]')
#print bc('([{[{}]}}]')
#m = '1+2*(3+4*[5-6*{100+200}])'
#print len(m)
#print bc('1+2*(3+4*[5-6*{100+200}])')
#bc('1(')


#print bc(')(')

#print bc('(')
#print bc('((')


















			





					

	
