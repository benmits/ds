num = list(map(int, input("Enter list of integers:").split()))
print("list is:",num)
for i in range(0,len(num)):
    if num[i]>100:
        num[i]="over"
print("updated list is:",num)
