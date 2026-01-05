a = input("Enter a line of text: ").split()
for i in set(a):
    print (i,"count is",a.count(i))
