print("\n-------------------zadanie 7.3 --------------------\n") 

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

    def intersection(self, other):  
        point1_x = max(self.point1.cord_x, other.point1.cord_x)
        point1_y = max(self.point1.cord_y, other.point1.cord_y)
        point2_x = min(self.point2.cord_x, other.point2.cord_x)
        point2_y = min(self.point2.cord_y, other.point2.cord_y)
        if(point1_x > point2_x or point1_y > point2_y):
            raise ValueError("rectangles does not corss")
        return Rectangle(point1_x, point1_y, point2_x, point2_y)

    def cover(self, other):         
        point1_x = min(self.point1.cord_x, other.point1.cord_x)
        point1_y = min(self.point1.cord_y, other.point1.cord_y)
        point2_x = max(self.point2.cord_x, other.point2.cord_x)
        point2_y = max(self.point2.cord_y, other.point2.cord_y)
        return Rectangle(point1_x, point1_y, point2_x, point2_y)

    def make4(self):                
        if(self == Rectangle()):
            raise ValueError("forbidden division by zero")
        return [Rectangle(self.point1.cord_x, self.point1.cord_y, 
                        (self.point2.cord_x + self.point1.cord_x)/2, 
                        (self.point2.cord_y + self.point1.cord_x)/2),
                Rectangle((self.point2.cord_x + self.point1.cord_x)/2, 
                        self.point1.cord_y, self.point2.cord_x, 
                        (self.point2.cord_y + self.point1.cord_y)/2),
                Rectangle(self.point1.cord_x, (self.point2.cord_y + self.point1.cord_y)/2, 
                         (self.point2.cord_x + self.point1.cord_x)/2, self.point2.cord_y),
                Rectangle((self.point2.cord_x + self.point1.cord_x)/2, 
                        (self.point2.cord_y + self.point1.cord_y)/2, 
                        self.point2.cord_x, self.point2.cord_y)]



class TestRectangle(unittest.TestCase): 
    def setUp(self):
        self.rectangle1 = Rectangle()
        self.rectangle2 = Rectangle(2, 5, 6, 3)
        self.rectangle3 = Rectangle(3, 2, -6, 5)
        self.rectangle4 = Rectangle(2, 2, 8, 8)
        self.rectangle5 = Rectangle(1, 1, 10, 10)
        self.rectangle6 = Rectangle(2, 1, 10, 8)
        self.rectangle7 = Rectangle(1, 2, 8, 10)

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

    def test_intersection(self):
        self.assertEqual(self.rectangle6.intersection(self.rectangle7), Rectangle(2, 2, 8, 8))
        with self.assertRaises(ValueError):
            self.rectangle1.intersection(self.rectangle3)

    def test_cover(self):
        self.assertEqual(self.rectangle5.cover(self.rectangle4), self.rectangle5)
        self.assertEqual(self.rectangle6.cover(self.rectangle7), Rectangle(1, 1, 10, 10))

    def test_make4(self):
        self.assertEqual(self.rectangle4.make4(), [Rectangle(2, 2, 5, 5), 
            Rectangle(5, 2, 8, 5), Rectangle(2, 5, 5, 8), 
            Rectangle(5, 5, 8, 8)])
        with self.assertRaises(ValueError):
            self.rectangle1.make4()


if __name__ == '__main__':
	unittest.main()