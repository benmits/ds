with open("student.txt",'w')as f:
 	f.write("roll number:12 \n name:alex \n age:21")
 	f=open("student.txt")
 	print(f.read())
