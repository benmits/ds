class student:
    def __init__(self,name,rollno,marks):
        self.name=name
        self.rollno=rollno
        self.marks=marks
    def display(self):
        print(“Student Details=>”)
        print("Name=",self.name)
        print("Rollno=",self.rollno)
        print("Marks=",self.marks)
    def updatemarks(self,newmarks):
        self.marks=newmarks
name=input("Enter Student Name:")
rollno=int(input("Enter Roll no:"))
marks=int(input("Enter Marks:"))
s1=student(name,rollno,marks)
s1.display()
newmarks=int(input("Enter new marks to update:"))
s1.updatemarks(newmarks)
s1.display()
