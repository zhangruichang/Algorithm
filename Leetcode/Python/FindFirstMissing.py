__author__ = 'richard'
class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def firstMissingPositive(self, nums):
        n=len(nums)
        i=0
        while i < n:
            if (nums[i]-i) == 1:
                i = i + 1
            elif 0 <= (nums[i]-1) and (nums[i]-1) < n and nums[nums[i]-1] != nums[i]:
                #self.swap(nums[i], nums[nums[i]-1])
                index=nums[i]-1
                nums[i], nums[index] = nums[index] ,nums[i]
                #nums[i] = nums[index]
                #nums[index] = tmp
            else:
                i = i + 1
        for i in range(n):
            if nums[i]!=(i+1):
                return i+1
        return n+1

S=Solution()
nums=[2, 1]
print S.firstMissingPositive(nums)