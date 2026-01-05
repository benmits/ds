y1=int(input("Enter a current Year:"))
y2=int(input("Enter a final Year:"))
for i in range (y1,y2+1):
    if(i%100!=0 or i%400==0 ):
        if(i%4==0):
            print(i,"is Leap Year")
