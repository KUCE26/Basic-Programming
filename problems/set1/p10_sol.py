def discount(price, rate=10):
    return price * (100 - rate) // 100


# 아래 코드는 수정하지 마세요.
nums = list(map(int, input().split()))
if len(nums) == 1:
    print(discount(nums[0]))
else:
    print(discount(nums[0], nums[1]))
