def second_largest(nums):
    unique = sorted(set(nums))
    return unique[-2]


# 아래 코드는 수정하지 마세요.
nums = list(map(int, input().split()))
print(f"두 번째로 큰 값: {second_largest(nums)}")
