from typing import List

'''
Bubble sort: order via repeatedly swapping adjacent elements
- Iterate through nums
- Iterate again to compare every pair of elements in the outer loop
- if they aren't swapped, return nothing
'''


def bubble(nums: List[int]) -> None:
    for i in range(len(nums)-1):
        for j in range(len(nums)-i-1):
            if (nums[j+1] < nums[j]):
                nums[j], nums[j+1] = nums[j+1], nums[j]


x = [100, 5, 300, 256, 1000, 10001, -3]
bubble(x)
print(x)
