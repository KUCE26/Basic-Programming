def our_min(nums):
    result = nums[0]
    for n in nums:
        if n < result:
            result = n
    return result


def our_sum(nums):
    total = 0
    for n in nums:
        total += n
    return total


# 아래 코드는 수정하지 마세요.
nums = list(map(int, input().split()))
total = our_sum(nums)
q, r = divmod(total, len(nums))
print(f"최솟값: {our_min(nums)}")
print(f"합계: {total}")
print(f"몫: {q}, 나머지: {r}")
