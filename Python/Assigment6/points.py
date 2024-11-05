class Point:
	"""Class represents points on surface"""

	def __init__(self, cord_x=0, cord_y=0):  # constuctor
		self.cord_x = cord_x
		self.cord_y = cord_y

	def __str__(self):              # return string "(cord_x, cord_y)"
		return "({0}, {1})".format(self.cord_x, self.cord_y)

	def __repr__(self):             # return string "Point(cord_x, cord_y)"
		return "Point({0}, {1})".format(self.cord_x, self.cord_y)

	def __eq__(self, other):        # serve point1 == point2
		return (self.cord_x == other.cord_x) and (self.cord_y == other.cord_y)

	def __ne__(self, other):        # serve point1 != point2
		return not self == other

	# Punktcord_y jako wektorcord_y 2D.
	def __add__(self, other):       # v1 + v2
		return Point(self.cord_x + other.cord_x, self.cord_y + other.cord_y)

	def __sub__(self, other):       # v1 - v2
		return Point(self.cord_x - other.cord_x, self.cord_y - other.cord_y)

	def __mul__(self, other):       # v1 * v2, dot product 
		return self.cord_x * other.cord_x + self.cord_y * other.cord_y

	def cross(self, other):         # v1 cord_x v2, cross product 2D
		return self.cord_x * other.cord_y - self.cord_y * other.cord_x

	def length(self):               # vector length
		import math
		return math.sqrt(self.cord_x*self.cord_x + self.cord_y*self.cord_y)

# testing

import unittest

class TestPoint(unittest.TestCase): 
	def setUp(self):
		self.p1=Point(0, 1)
		self.p2=Point(1, 0)
		self.p3=Point(3, 4)
		self.p4=Point(2, 5)

	def test_str(self):
		self.assertEqual(self.p1.__str__(), "(0, 1)")

	def test_repr(self):
		self.assertEqual(self.p1.__repr__(), "Point(0, 1)")

	def test_eq(self):
		self.assertEqual(self.p1 == self.p2, False)
		self.assertEqual(self.p1 == self.p1, True)

	def test_ne(self):
		self.assertEqual(self.p1 != self.p1, False)
		self.assertEqual(self.p1 != self.p2, True)

	def test_add(self):
		self.assertEqual(self.p1 + self.p2, Point(1, 1))

	def test_sub(self):
		self.assertEqual(self.p1 - self.p2, Point(-1, 1))

	def test_mul(self):
		self.assertEqual(self.p3 * self.p4, 26)
		self.assertEqual(self.p1 * self.p2, 0)

	def test_cross(self):
		self.assertEqual(Point.cross(self.p3, self.p4), 7)

	def test_length(self):
		self.assertEqual(self.p1.length(), 1)
		self.assertEqual(self.p3.length(), 5)

if __name__=='__main__':
	unittest.main()















