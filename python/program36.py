import csv
with open("book.csv")as d: 
	col=csv.reader(d)
	print("The specific columns are:")
	for i in col:
		print(i[0],i[1],i[3])
#book.csv
book_no, title, author,price
b1,Treasure Island,Robinson,$100
b2,Gullivers Travels,Steve Smith,$200
b3,World of Demons,D Stevenson,$500
