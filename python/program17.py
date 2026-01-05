def fibonacci(n):
 	f1 = 0
    f2 = 1
    print("Fibonacci series:", f1, f2, end=" ")
    for i in range(3, n+1):
        f3 = f1 + f2
        print(f3, end=" ")
       	f1 = f2
        f2 = f3
n = int(input("Enter the limit: "))
if n == 1:
    print("Fibonacci series: 0")
elif n == 2:
    print("Fibonacci series: 0 1")
else:
    fibonacci(n)
