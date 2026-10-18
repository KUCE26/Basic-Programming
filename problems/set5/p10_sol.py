def apply(func, nums):
    result = []
    for x in nums:
        result.append(func(x))
    return result


# lambda를 완성하세요.
double = lambda x: x * 2
mod3 = lambda x: x % 3


# 아래 코드는 수정하지 마세요.
nums = list(map(int, input().split()))
print(apply(double, nums))
print(apply(mod3, nums))
