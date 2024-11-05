print("\n-------------------zadanie 4.2A --------------------") 

import math

def ruler(length):
	marks="|"
	for n in range(length):
		marks+="....|"

	numbers=""
	for n in range(length+1):
		numbers+=str(n)
		spaces=4 - math.ceil(len(str(n + 1)) // 2)
		numbers+=(" " * spaces)
	return marks + '\n' + numbers

print(ruler(10))

print("\n-------------------zadanie 4.2B --------------------") 

def squarestr(length, width):
	"""Returns string with square"""
	start="+"
	width1=width

	while width1 != 0:
		start+="---+"
		width1-=1
	square=start + "\n"

	for n in range(length):
		width2=width
		line1="|"
		line2="+"
		while width2 != 0:
			line1+="   |"
			line2+="---+"
			width2-=1
		square+=line1 + "\n"
		square+=line2 + "\n"
	return square

print(squarestr(5,5))

print("\n-------------------zadanie 4.3 --------------------") 

def factorial(n):
	result=1
	for i in range(1, n+1):
		result=result*i
	return result

print(factorial(5))

print("\n-------------------zadanie 4.4 --------------------") 

def fibonacci(n):
	factor0=0
	factor1=1
	for i in range(n-1):
		tmp=factor1
		factor1=factor1+factor0
		factor0=tmp
	return factor1

print(fibonacci(10))

print("\n-------------------zadanie 4.5 --------------------") 

print("\n iteracja")
def odwracanie_iter(L, l_value, r_value):
	it=(r_value - l_value) // 2
	for i in range(it):
		L[l_value], L[r_value] = L[r_value], L[l_value] # swap
		l_value+=1
		r_value-=1
	return L	

L=[x for x in range(11)]
print(odwracanie_iter(L, 2, 7))

#[0, 1, 7, 6, 4, 5, 3, 2, 8, 9, 10]

print("\n rekurencja")

def odwracanie_rekt(L, l_value, r_value):
	if l_value+1 != r_value and l_value != r_value:
		L[l_value], L[r_value] = L[r_value], L[l_value]
		odwracanie_rekt(L, l_value+1, r_value-1)
	return L	

L1=[x for x in range(11)]
print(odwracanie_rekt(L1,2,7))

print("\n-------------------zadanie 4.6 --------------------") 

def sum_seq(sequence):
	result=0
	for item in sequence:
		if isinstance(item, (list, tuple)):
			result+=sum_seq(item)
		else:
			result+=item
	return result

seq1= [1,(2,3),[],[4,(5,6,7)],8,[9]]
print(sum_seq(seq1))

print("\n-------------------zadanie 4.7 --------------------") 

def flatten(sequence):
	result=[]
	for item in sequence:
		if isinstance(item, (list, tuple)):
			result+=flatten(item)
		else:
			result.append(item)
	return result

seq = [1,(2,3),[],[4,(5,6,7)],8,[9]]
print(flatten(seq))
