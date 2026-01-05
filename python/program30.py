class student:
    def __init__(self,m1,m2):
        self.m1=m1
        self.m2=m2
    def total(self):
        return self.m1+self.m2
    def __add__(self,other):
        total1=self.total()
        total2=other.total()
        return total1+total2
print("Enter Marks of the student1\n")
m11=int(input("enter mark1 "))  
m12=int(input("enter mark2 "))       
print("\nEnter Markes of the student 2")
m21=int(input("enter mark1 "))  
m22=int(input("enter mark2 "))              
s1=student(m11,m12)
s2=student(m21,m22)    
print("Total Mark of student 1=",s1.total())
print("Total Mark of student 2=",s2.total())
ctotal=s1+s2
print("Combined total of both students ",ctotal)
