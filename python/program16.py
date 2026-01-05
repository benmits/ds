a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
c = int(input("Enter third number: "))
if a > b:
    biggest = a
else:
	biggest=b
    if  biggest < c:
        biggest = c
if a < b:
    smallest = a
else:
	smallest=b
    if  smallest > c:
  	    smallest = c
print("\nBiggest number:", biggest)
print("Smallest number:", smallest)
