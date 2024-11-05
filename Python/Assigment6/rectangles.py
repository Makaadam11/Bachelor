print("\n-------------------zadanie 6.3 --------------------\n") 

import unittest
from points import Point


class Rectangle:

	def __init__(self, x1=0, y1=0, x2=0, y2=0):
		self.point1 = Point(x1, y1)
		self.point2 = Point(x2, y2)

	def __str__(self):              
		return "[{0}, {1}]".format(self.point1, self.point2)

	def __repr__(self):             
		return "Rectangle({0}, {1}, {2}, {3})".format(self.point1.cord_x,self.point1.cord_y, self.point2.cord_x, self.point2.cord_y)

	def __eq__(self, other):       
		return (self.point1 == other.point1) and (self.point2 == other.point2)

	def __ne__(self, other):        
		return not self == other

	def center(self):               
		return Point((self.point1.cord_x + self.point2.cord_x)/2, (self.point1.cord_y + self.point2.cord_y)/2)

	def area(self):                 
		return abs((self.point1.cord_x - self.point2.cord_x) * (self.point1.cord_y - self.point2.cord_y))

	def move(self, x, y):           
		self.point1 = self.point1 + Point(x, y)
		self.point2 = self.point2 + Point(x, y)



class TestRectangle(unittest.TestCase): 
	def setUp(self):
		self.rectangle1 = Rectangle()
		self.rectangle2 = Rectangle(2, 5, 6, 3)
		self.rectangle3 = Rectangle(3, 2, -6, 5)

	def test_str(self):
		self.assertEqual(self.rectangle2.__str__(), "[(2, 5), (6, 3)]")
		self.assertEqual(self.rectangle3.__str__(), "[(3, 2), (-6, 5)]")	

	def test_repr(self):
		self.assertEqual(self.rectangle2.__repr__(), "Rectangle(2, 5, 6, 3)")
		self.assertEqual(self.rectangle3.__repr__(), "Rectangle(3, 2, -6, 5)")

	def test_eq(self):
		self.assertEqual(self.rectangle3 == self.rectangle3, True)
		self.assertEqual(self.rectangle3 == self.rectangle2, False)

	def test_center(self):
		self.assertEqual(self.rectangle1.center(), Point())
		self.assertEqual(self.rectangle2.center(), Point(4, 4))
		self.assertEqual(self.rectangle3.center(), Point(-1.5,3.5))

	def test_area(self):
		self.assertEqual(self.rectangle1.area(), 0)
		self.assertEqual(self.rectangle2.area(), 8)
		self.assertEqual(self.rectangle3.area(), 27)

	def test_move(self):
		self.rectangle1.move(2, 1)
		self.rectangle2.move(2, 1)
		self.assertEqual(self.rectangle1, Rectangle(2, 1, 2, 1))
		self.assertEqual(self.rectangle2, Rectangle(4, 6, 8, 4))


if __name__ == '__main__':
	unittest.main()