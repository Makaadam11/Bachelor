print("\n-------------------zadanie 5.2 --------------------\n") 

import math 

def add_frac(fraction1, fraction2):
	if (fraction1[1] & fraction2[1]) == 0:
		raise ZeroDivisionError('dividing by zero error')
	add_result=[0, 0]
	add_result[0] = fraction1[0]*fraction2[1] + fraction2[0]*fraction1[1]
	add_result[1] = fraction1[1] * fraction2[1] 
	greatest_common_divisor = math.gcd(add_result[0], add_result[1])
	return [x//greatest_common_divisor for x in add_result]

def sub_frac(fraction1, fraction2):
	if (fraction1[1] & fraction2[1]) == 0:
		raise ZeroDivisionError('dividing by zero error')
	sub_result=[0, 0]
	sub_result[0] = fraction1[0]*fraction2[1] - fraction2[0]*fraction1[1]
	sub_result[1] = fraction1[1] * fraction2[1] 
	greatest_common_divisor = math.gcd(sub_result[0], sub_result[1])
	return [x//greatest_common_divisor for x in sub_result]

def mul_frac(fraction1, fraction2):
	if (fraction1[1] & fraction2[1]) == 0:
		raise ZeroDivisionError('dividing by zero error')
	mul_result=[0, 0]
	mul_result[0] = fraction1[0] * fraction2[0]
	mul_result[1] = fraction1[1] * fraction2[1]
	greatest_common_divisor = math.gcd(mul_result[0], mul_result[1])
	return [x//greatest_common_divisor for x in mul_result]

def div_frac(fraction1, fraction2):
	if (fraction1[1] & fraction2[1]) == 0:
		raise ZeroDivisionError('dividing by zero error')
	div_result=[0, 0]
	div_result[0] = fraction1[0] * fraction2[1]
	div_result[1] = fraction1[1] * fraction2[0]
	greatest_common_divisor = math.gcd(div_result[0], div_result[1])
	return [x//greatest_common_divisor for x in div_result]

def is_positive(fraction):
	if fraction[1] == 0:
		raise ZeroDivisionError('dividing by zero error')
	return True if fraction[0]*fraction[1] > 0 else False

def is_zero(fraction):
	if fraction[1] ==0:
		raise ZeroDivisionError('dividing by zero error') 
	return True if fraction[0] == 0 else False

def cmp_frac(fraction1, fraction2):
	if (fraction1[1] and fraction2[1]) == 0:
		raise ZeroDivisionError('dividing by zero error')
	compate_fraction1 = fraction1[0] * fraction2[1]
	compate_fraction2 = fraction2[0] * fraction1[1]
	if compate_fraction1 == compate_fraction2:
		return 0
	else:
		return 1 if compate_fraction1 > compate_fraction2 else -1

def frac2float(fraction):
	return float(fraction[0]/fraction[1])

import unittest

class TestFractions(unittest.TestCase):
	def setUp(self):
		self.zero = [0, 1]

	def test_add_frac(self):
		self.assertEqual(add_frac([1, 2], [1, 3]), [5, 6])

	def test_sub_frac(self):
		self.assertEqual(sub_frac([1, 2], [1, 3]), [1, 6])	

	def test_mul_frac(self):
		self.assertEqual(mul_frac([1, 2], [1, 3]), [1, 6])

	def test_div_frac(self):
		self.assertEqual(div_frac([1, 2], [1, 3]), [3, 2])

	def test_is_positive(self):
		self.assertEqual(is_positive([2, -6]), False)
		self.assertEqual(is_positive([-5, -2]), True)
		self.assertEqual(is_positive([5, 2]), True)

	def test_is_zero(self):
		self.assertEqual(is_zero([0, 4]), True)
		self.assertEqual(is_zero([5, 1]), False)

	def test_cmp_frac(self):
		self.assertEqual(cmp_frac([7, 4], [5, 7]), 1)
		self.assertEqual(cmp_frac([2, 2], [4, 4]), 0)
		self.assertEqual(cmp_frac([-3, 2], [5, 4]), -1)

	def test_frac2float(self):
		self.assertEqual(frac2float([3, 2]), 1.5)
		self.assertEqual(frac2float([1, 4]), 0.25)

if __name__ == '__main__':
	unittest.main()     