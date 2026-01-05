from operations import oper
x=int(input(“Enter the first number:”))
y=int(input(“Enter the second number:”))
print("Addition")
print("result is",oper.add(x,y))
print("Subtraction")
print("result is",oper.sub(x,y))
print("Multiplication")
print("result is",oper.prod(x,y))
print("Division")
print("result is",oper.div(x,y))

#oper.py
def add(a,b):
    return a+b
def sub(a,b):
    return a-b
def mult(a,b):
    return a*b
def div(a,b):
    return a/b
