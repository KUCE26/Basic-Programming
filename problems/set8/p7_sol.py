import re

p1 = r"\d"
p2 = r"\D"

m1 = re.findall(p1, "el_ice%20$19")
m2 = re.findall(p2, "el_ice%20$19")

print("m1 결과 : ", m1)
print("m2 결과 : ", m2)
