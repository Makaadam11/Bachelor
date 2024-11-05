print("\n-------------------zadanie 6.3 --------------------\n") 


from points import Point


class Triangle:

    def __init__(self, x1, y1, x2, y2, x3, y3):
        self.point1 = Point(x1,y1)
        self.point2 = Point(x2,y2)
        self.point3 = Point(x3,y3)

    def __str__(self):              
        return "[{0}, {1}, {2}]".format(self.point1, self.point2, self.point3)

    def __repr__(self):             
        return "Rectangle({0}, {1}, {2}, {3}, {4}, {5})".format(self.point1.cord_x,self.point1.cord_y, 
        self.point2.cord_x, self.point2.cord_y, self.point3.cord_x, self.point3.cord_y)

    def __eq__(self, other):       
        return (self.point1 == other.point1) and (self.point2 == other.point2)

    def __ne__(self, other):        
        return not self == other

    def center(self):               
        return Point((self.point1.cord_x + self.point2.cord_x+ self.point3.cord_x)/3, (self.point1.cord_y + self.point2.cord_y+ self.point3.cord_y)/3)

    def area(self):
        area=abs(0.5*((self.point1.cord_x*(self.point2.cord_y-self.point3.cord_y)) + 
        (self.point2.cord_x*(self.point3.cord_y-self.point1.cord_y)) + 
        (self.point3.cord_x*(self.point1.cord_y-self.point2.cord_y))))
        return area

    def move(self, x, y):           
        self.point1 = self.point1 + Point(x, y)
        self.point2 = self.point2 + Point(x, y)
        self.point3 = self.point3 + Point(x, y)

import unittest

class TestRectangle(unittest.TestCase): 
    def setUp(self):
        self.triangle1 = Triangle(0,0,0,0,0,0)
        self.triangle2 = Triangle(2, 5, 6, 3, 5, 6)
        self.triangle3 = Triangle(3, 2, -6, 5, 2, 6)

    def test_str(self):	
        self.assertEqual(self.triangle2.__str__(), "[(2, 5), (6, 3), (5, 6)]")
        self.assertEqual(self.triangle3.__str__(), "[(3, 2), (-6, 5), (2, 6)]")


    def test_repr(self):
        self.assertEqual(self.triangle2.__repr__(), "Rectangle(2, 5, 6, 3, 5, 6)")
        self.assertEqual(self.triangle2.__repr__(), "Rectangle(2, 5, 6, 3, 5, 6)")

    def test_eq(self):
        self.assertEqual(self.triangle3 == self.triangle3, True)
        self.assertEqual(self.triangle3 == self.triangle2, False)

    def test_center(self):

        self.assertEqual(self.triangle1.center(), Point())
        self.assertEqual(self.triangle2.center(), Point(4.333333333333333, 4.666666666666667))
        self.assertEqual(self.triangle3.center(), Point(-0.3333333333333333,4.333333333333333))

    def test_area(self):
        self.assertEqual(self.triangle1.area(), 0)
        self.assertEqual(self.triangle2.area(), 5)
        self.assertEqual(self.triangle3.area(), 16.5)

    def test_move(self):
        self.triangle1.move(2, 1)
        self.triangle2.move(2, 1)
        self.assertEqual(self.triangle1, Triangle(2, 1, 2, 1, 2, 1))
        self.assertEqual(self.triangle2, Triangle(4, 6, 8, 4, 7, 8))


if __name__ == '__main__':
    unittest.main()