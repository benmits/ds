num = list(map(int, input("Enter a list: ").split()))
p = [x for x in num if x > 0]
print("Positive numbers:", p)

n = int(input("\nEnter N: "))
s = [i*i for i in range(1, n+1)]
print("Squares:", s)

word = input("\nEnter a word: ")
v = [i for i in word if i.lower() in 'aeiou']
print("Vowels:", v)

ord = [ord(ch) for ch in word]
print("Ordinal values:", ord)
