print("\n-------------------zadanie 8.1 --------------------\n") 

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

    @classmethod
    def from_points(cls, points):
        point1, point2 = points
        if not (isinstance(point2, Point) and isinstance(point1, Point)):
            raise ValueError("Argument not iterable")
        return cls(point1.cord_x, point1.cord_y, point2.cord_x, point2.cord_y)
        
    

    @property
    def cord_x1(self):
        return self.point1.cord_x
    print()      
    @property
    def cord_y1(self):
        return self.point1.cord_y
    @property
    def cord_x2(self):
        return self.point2.cord_x
    @property
    def cord_y2(self):
        return self.point2.cord_y
    @property
    def width(self):
        return abs(self.point1.cord_x - self.point2.cord_x) 
    @property
    def length(self):
        return abs(self.point1.cord_y - self.point2.cord_y)         

    @property
    def topleft(self):
       return min(self.point1.cord_x,self.point2.cord_x),max(self.point1.cord_y,self.point2.cord_y)  
    @property
    def bottomleft(self):
       return min(self.point1.cord_x,self.point2.cord_x),min(self.point1.cord_y,self.point2.cord_y)  
    @property
    def topright(self):
       return max(self.point1.cord_x,self.point2.cord_x),max(self.point1.cord_y,self.point2.cord_y)  
    @property
    def bottomright(self):
       return max(self.point1.cord_x,self.point2.cord_x),min(self.point1.cord_y,self.point2.cord_y)  

