a={"Anu" : 85, "Ravi" : 90, "Minu" : 75, "Sara" : 88, "Tom" : 94 }
print("Dictionary is: ",a)
print("Sara\'s Marks is: ",a["Sara"])
a["Kiran"] = 80
a["Minu"] = 82
print("Updated Dictionary is: ",a)
a.pop("Tom")
print("Updated Dictionary is: ",a)
print("Keys are: ",a.keys())
print("Values are: ",a.values())
print("Sorted are ",sorted(a.values()))
print("Sorted keys are ",sorted(a.keys()))
high = max(a,key=a.get)
print("Student having highest marks: ",high)
b = {"Anusha": 85, "Navin": 70, "Libin": 75 }
a.update(b)
print('After merging: ',a)
