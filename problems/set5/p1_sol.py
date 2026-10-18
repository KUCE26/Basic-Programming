pizza = int(input())
slices = int(input())
people = int(input())

total = pizza * slices
print(f"한 사람당 조각 수: {total // people}")
print(f"남는 조각 수: {total % people}")
