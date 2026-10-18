def total(*prices):
    result = 0
    for p in prices:
        result += p
    return result


# lambda를 완성하세요.
avg = lambda s, n: s / n


# 아래 코드는 수정하지 마세요.
nums = list(map(int, input().split()))
s = total(*nums)
print(s)
print(f"{avg(s, len(nums)):.1f}")
