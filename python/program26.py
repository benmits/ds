#rectangle.py
def area (length,width):
    return length*width
def perimeter (length,width):
    return 2*length+width

#circle.py
import math
def area(radius):
    return math.pi*radius**2
def perimeter(radius):
    return 2*math.pi*radius
    
#cuboid.py
def surface_area(l,w,h):
    return 2*(l*w+w*h+l*h)
def volume(l,w,h):
    return l*w*h
	
#sphere.py
import math
def surface_area(r):
    return 4*math.pi*r**2
def volume(r):
    return 4/3*(math.pi*r**3)
	
#main.py
from graphics import rectangle,circle
from graphics.ThreeD import cuboid,sphere
l=float(input(“Enter a length:”))
b=float(input(“Enter a breadth:”))
r=float(input(“Enter a radius:”))
h=float(input(“Enter a height:”))
print("\nrectangle")
print("area is",rectangle.area(l,b))
print("perimeter is",rectangle.perimeter(l,b))
print("\n")
print("circle")
print("area is",circle.area(r))
print("perimeter is",circle.perimeter(r))

#using cuboid module using subpackage 3D
print("\n")
print("cuboid")
print("area is",cuboid.surface_area(l,b,h))
print("volume is",cuboid.volume(l,b,h))
print("\n")

#using sphere module using subpackage 3D
print("sphere")
print("area is",sphere.surface_area(r))
print("volume is",sphere.volume(r))