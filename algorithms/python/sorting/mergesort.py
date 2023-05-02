from typing import List
'''
Merge Sort: a divide + conquer algorithm. This algorithm takes two subsets of an array and merges them into one sorted array.
    - 
'''

'''
Have we reached the end of any of the arrays?
    No:
        Compare current elements of both arrays 
        Copy smaller element into sorted array
        Move pointer of element containing smaller element
    Yes:
        Copy all remaining elements of non-empty array
'''
def mergeSort(nums: List[int]):
    # Have we reached the end?
    if len(nums) > 1:
        
        # Split the array into two halves.
        mid = len(nums)//2
        left = nums[:mid]
        right = nums[mid:]

        # Sort the two halves
        mergeSort(left)
        mergeSort(right)

        firstptr = secondptr = tmp = 0

        # Until we reach either end of either left or right, pick larger among
        # elements firstptr and secondptr and place them in the correct position at A[p..r]
        while firstptr < len(left) and secondptr < len(right):
            if left[firstptr] < right[secondptr]:
                nums[tmp] = left[firstptr]
                firstptr += 1
            else:
                nums[tmp] = right[secondptr]
                secondptr += 1
            tmp += 1

        # When we run out of elements in either left or right,
        # pick up the remaining elements and put in A[p..r]
        while firstptr < len(left):
            nums[tmp] = left[firstptr]
            firstptr += 1
            tmp += 1

        while secondptr < len(right):
            nums[tmp] = right[secondptr]
            secondptr += 1
            tmp += 1
    
arr = [6,5,7,10,0,-12,1,4]
print("Unsorted: ", arr)
mergeSort(arr)
print("Sorted: ", arr)
