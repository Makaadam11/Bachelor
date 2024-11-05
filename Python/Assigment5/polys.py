print("\n-------------------zadanie 5.3 --------------------\n") 

import operator 

def add_poly(polynomial1, polynomial2):
	poly=poly_length_fit(polynomial1, polynomial2)
	return [iter for iter in map(operator.add, poly[0], poly[1])]

def sub_poly(polynomial1, polynomial2):
	poly=poly_length_fit(polynomial1, polynomial2)
	return [iter for iter in map(operator.sub, poly[0], poly[1])]

def mul_poly(polynomial1, polynomial2):
	result=[0 for x in range(len(polynomial1)+len(polynomial2)-1)]
	for iter1 in range(len(polynomial1)):
		for iter2 in range(len(polynomial2)):
			result[iter1+iter2]+=polynomial1[iter1]*polynomial2[iter2]
	return result

def is_zero(polynomial):
	for iter in polynomial:
		if iter != 0:
			return False
	return True

def cmp_poly(polynomial1, polynomial2):
	return True if polynomial1 == polynomial2 else False

def eval_poly(polynomial, x0):
	b0 = polynomial[-1]
	for i in range(-2, -(len(polynomial)+1), -1):
		b1 = polynomial[i] + b0*x0
		b0 = b1
	return b0

def combine_poly(polynomial1, polynomial2):
	result = [polynomial1[-1]]
	for i in range(len(polynomial1)-2, -1, -1):
		result = add_poly(mul_poly(result, polynomial2), [polynomial1[i]])
	return result

def pow_poly(polynomial, power):
	result = polynomial
	for i in range(power-1):
		result = mul_poly(polynomial, result)
	return result

def diff_poly(polynomial):
	result = [0]*len(polynomial)
	for i in range(len(polynomial)):
		result[i] = i*polynomial[i]
	result.pop(0)
	return result

def poly_length_fit(polynomial1, polynomial2):
	
	lower_polynomial = list(polynomial2 if len(polynomial1) > len(polynomial2) else polynomial1)
	highier_polynomial = list(polynomial2 if len(polynomial1) < len(polynomial2) else polynomial1)
	fill_with_zeroes = abs(len(polynomial1) - len(polynomial2))
	if fill_with_zeroes != 0:
		lower_polynomial.extend([0 for iter in range(fill_with_zeroes)])
	if highier_polynomial == polynomial1:  
		return [highier_polynomial, lower_polynomial]
	else:
		return [lower_polynomial, highier_polynomial]

import unittest

class TestPolynominals(unittest.TestCase):


	def test_add_poly(self):
		self.assertEqual(add_poly(self.p1, self.p2), [0, 4, 6])
		self.assertEqual(add_poly(self.p3, self.p4), [8, 21, 4])

	def test_sub_poly(self):
		self.assertEqual(sub_poly(self.p2, self.p1), [0, 0, 6])
		self.assertEqual(sub_poly(self.p4, self.p3), [4, 9, -4])

	def test_mul_poly(self):
		self.assertEqual(mul_poly(self.p3, self.p4), [12, 66, 114, 60])
		self.assertEqual(mul_poly(self.p1, self.p2), [0, 0, 4, 12])

	def test_is_zero(self):
		self.assertEqual(is_zero([0, 0, 0]), True)
		self.assertEqual(is_zero([0, 1, 0, 0]), False)

	def test_eval_poly(self):
		self.assertEqual(eval_poly(self.p1, 4), 8)
		self.assertEqual(eval_poly(self.p3, 4), 90)

	def test_cmp_poly(self):
		self.assertEqual(cmp_poly(self.p3, self.p3), True)
		self.assertEqual(cmp_poly(self.p1, self.p4), False)

	def test_combine_poly(self):
		self.assertEqual(combine_poly(self.p5, self.p6), [38, 322, 864, 2112, 4464, 3456, 6912])

	def test_pow_poly(self):
		self.assertEqual(pow_poly(self.p5, 3), [64, 1056, 6384, 16984, 19152, 9504, 1728])

	def test_diff_poly(self):
		self.assertEqual(diff_poly(self.p2), [2, 12])
		self.assertEqual(diff_poly(self.p6), [7, 12, 72])

	def setUp(self):
		self.p1 = [0, 2]      
		self.p2 = [0, 2, 6]   
		self.p3 = [2, 6, 4]   
		self.p4 = [6, 15]      
		self.p5 = [4, 22, 12]
		self.p6 = [1, 7, 6, 24]	

if __name__ == '__main__':
	unittest.main()