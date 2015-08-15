__author__ = 'Richard'
import sys
class Solution:
    # @param {integer[][]} costs
    # @return {integer}
    def minCost(self, costs):
        n=len(costs)
        if n == 0:
            return 0
        dp=[[0 for col in range(3)] for row in range(2)]
        for j in range(3):
            dp[0][j]=costs[0][j]
        for i in range(1, n):
            for j in range(3):
                dp[1][j]=sys.maxint
                for k in range(1,3):
                    dp[1][j]=min(dp[1][j], dp[0][(j+k)%3]+costs[i][j])
            for j in range(3):
                dp[0][j]=dp[1][j]
        return min(dp[0][0], dp[0][1], dp[0][2])