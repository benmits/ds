num = list(map(int, input("Enter a list: ").split()))
new = [i for i in num if i % 2 != 0]
print(new)
