from tree import *
from binary_tree import *

# test code for tree.py
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

print('INFO: We are now printing depth first')
x.Print_DepthFirst()
print('INFO: Converting the tree into a level-ordered list:')
x.Get_LevelOrder()
correctList = [1000,2000,3000,4000,7,5,6,8]
if (x.Get_LevelOrder() == correctList):
	print('Passed test for Get_LevelOrder')

print('INFO: Testing Assignment 4')
print x.ConvertToBinaryTree

# this test code below is for binary_tree.py
X = binary_tree(1000)
Y = binary_tree(2000)
Z = binary_tree(3000)
X.AddLeft(Y)
X.AddRight(Z)
C = binary_tree(5)
Z.AddRight(C)

print('INFO: Printing depth first for the binary tree')
X.Print_DepthFirst()

print('INFO: Testing Assignment 5')
print X.ConvertToTree()

