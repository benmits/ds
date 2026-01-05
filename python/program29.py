class student:
     def __init__(self,name,mark1,mark2):
        self.name=name
        self.mark1=mark1
        self.mark2=mark2
     def display(self):
        print(“Student Details =>”)
        print("Name:",self.name)
        print("Mark1:",self.mark1)
        print("Mark2:",self.mark2)
     def total(self):
        return self.mark1+self.mark2     
name=input("Enter name:")
mark1=int(input("Enter mark 1:"))
mark2=int(input("Enter mark 2:"))
s1=student(name,mark1,mark2)
s1.display()
print("Total marks=",s1.total())
