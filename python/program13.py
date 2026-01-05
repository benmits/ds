s = input("Enter a string: ")
new = s[0] + s[1:].replace(s[0], '$')
print("Modified string:", new)
