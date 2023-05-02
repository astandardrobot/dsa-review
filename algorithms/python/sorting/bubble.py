from typing import List

'''
Bubble sort: order via repeatedly swapping adjacent elements
- Iterate through nums
- Set a swapped flag to False
- Iterate again to compare every pair of elements in the outer loop
- if they aren't swapped, return nothing
'''

def bubble(nums: List[int]) -> None:
    for i in range(0, len(nums)-1):
        swapped = False
        for j in range(1, len(nums)-i-1):
            if(nums[j-1] > nums[j]):
                swapped = True
                nums[j], nums[j-1] = nums[j-1], nums[j]
            if not swapped:
                return
