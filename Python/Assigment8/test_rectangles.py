print("\n-------------------zadanie 8.1 --------------------\n") 

import pytest
from rectangles import Rectangle
from points import Point

    
def test_from_points():
    rectangle = Rectangle.from_points((Point(2, 3), Point(4, 6))) 
    assert str(rectangle) == '[(2, 3), (4, 6)]'

def test_size_get():

    rectangle = Rectangle(2, 3, 4, 6) 
    assert rectangle.length == 3
    assert rectangle.width == 2
    assert rectangle.cord_y2 == 6
    assert rectangle.cord_y1 == 3
    assert rectangle.cord_x1 == 2
    assert rectangle.cord_x2 == 4

def test_point_get():
   
    p1 = Point(2, 3)
    p2 = Point(4, 6)
    rectangle = Rectangle.from_points((p1, p2))

    assert rectangle.bottomleft == (2,3)
    
    assert rectangle.topright == (4,6)
    
    assert rectangle.topleft == (2,6)
    
    assert rectangle.bottomright == (4,3)


if __name__ == '__main__':
	pytest.main()