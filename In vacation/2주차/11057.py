from math import factorial
a = 0
b = int(input())
a = 10 + b - 1
print((factorial(a)//(factorial(b)*factorial(a-b)))%10007)