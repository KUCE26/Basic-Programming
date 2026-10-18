import re

p1 = "apple"
p2 = "banana"

m1 = re.findall(p1, "I like apple and banana")
m2 = re.findall(p2, "I like apple and banana")

print("m1 결과 : ", m1)
print("m2 결과 : ", m2)

p3 = "apple|banana"

m3 = re.findall(p3, "I like apple and banana")

print("m3 결과 : ", m3)
