import csv
with open("student.csv")as f:
	c=csv.reader(f)
	for i in c:
		print(i)
