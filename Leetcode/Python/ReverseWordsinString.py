__author__ = 'zhangruichang'
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: a list of 1 length strings (List[str])
        :rtype: nothing
        """
        s.reverse()
        start = 0
        for i in range(len(s)):
            if s[i] == ' ':
                s[start:i] = s[start:i][::-1]
                start = i+1

S = Solution()
s = 'I am Zhang Ruichang'
s = [i for i in s]
print s
S.reverseWords(s)
print s
