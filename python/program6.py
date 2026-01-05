l=list(map(int,input("enter a list1:").split()))
print("first list is",l)
print("\n")
l2=list(map(int,input("enter a list2:").split()))
print("second list is:",l2)
print("\n")
if len(l)==len(l2):
    print("lists are of same length")
else:
    print("lists are  of different length")
if sum(l)==sum(l2):
    print("lists are of same sum",sum(l),"and",sum(l2))
else:
    print("lists are not having same sum",sum(l),"and",sum(l2))
print("check for same elements in both lists..")
for i in l:
    if i in l2:
        print(i)
