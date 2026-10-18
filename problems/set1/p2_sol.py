height = float(input())
weight = float(input())
bmi = weight / (height / 100) ** 2
print(f"BMI: {bmi:.2f}")
