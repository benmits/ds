l=input("enter a list of colors:").split()
print("first list is",l)
n=len(l)
print("first and last color is:",l[0],l[n-1])
print("\n")
l2=input("enter a other list of colors:").split()
print("second list is:",l2)
print("\n")
print("colors of first_list not in second_list:")
for i in l:
    if i not in l2:
        print(i)
