class student:
    def __init__(self,name):
        self.name=name
    def display(self):
        print("Name=",self.name)
class mcastudent(student):
    def __init__(self,name,semester):
        super().__init__(name)
        self.semester=semester
    def showdetails(self):
        self.display()
        print("Semester=",self.semester)
name=input("Enter name:")
semester=int(input("Enter semester:"))
s=mcastudent(name,semester)
print("Student Details =>")
s.showdetails()
