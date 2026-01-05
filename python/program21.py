s = input("Enter a string: ")
if s.endswith("ing"):
    s = s + "ly"
else:
    s = s + "ing"
print("Modified string:", s)
