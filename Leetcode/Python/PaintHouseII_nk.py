__author__ = 'Richard'
class Solution:
    def minCostII(self, costs):
        if not costs:
            return 0
        k = len(costs[0])
        if k == 1:
            return costs[0][0]
        prev = [0] * k
        for now in costs:
            left = prev[:1] * k
            right = prev[-1:] * k
            for i in xrange(1, k):
                left[i] = min(left[i-1], prev[i])
                right[~i] = min(right[-i], prev[~i])
            prev = now[:]
            prev[0] += right[1]
            prev[-1] += left[-2]
            for i in xrange(1, k-1):
                prev[i] += min(left[i-1], right[i+1])
        return min(prev)