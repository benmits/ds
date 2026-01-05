class rectangle:
    def __init__(self,width,length):
        self.width=width
        self.length=length
    def area(self):
        return self.length*self.width      
    def __lt__(self,other):
        return self.area()<other.area()       
print("Enter Measurement of Rectangle 1")
l1=int(input("Enter length:"))
w1=int(input("Enter width:"))
print("Enter Measurement of Rectangle 2")
l2=int(input("Enter length:"))
w2=int(input("Enter width:"))
r1=rectangle(l1,w1)
r2=rectangle(l2,w2)
print("Area of Rectangle 1:",r1.area())
print("Area of Rectangle 2:",r2.area())
if r1<r2:
   print("Area of Rectangle 1 is small")
else:
     print("Area of Rectangle 2 is small") 
