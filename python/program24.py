area1 = lambda a: a * a
area2 = lambda l, b: l * b
area3 = lambda b, h: 0.5 * b * h

a = float(input("Enter side of square: "))
l = float(input("Enter length of rectangle: "))
b = float(input("Enter breadth of rectangle: "))
tb = float(input("Enter base of triangle: "))
h = float(input("Enter height of triangle: "))

print("\nArea of Square =", area1(a))
print("Area of Rectangle =", area2(l, b))
print("Area of Triangle =", area3(tb, h))
