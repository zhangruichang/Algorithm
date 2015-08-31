__author__ = 'zhangruichang'
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: a list of 1 length strings (List[str])
        :rtype: nothing
        """
        #if len(s) == 0:
        #    return '';
        s.reverse()
        start,n= 0, len(s)
        for i in range(len(s)):
            if s[i]==' ':
                s[start:i]=s[start:i][::-1]
                start = i+1
        s[start:n]=s[start:n][::-1]

S = Solution()
s = 'I am Zhang Ruichang'
s = [i for i in s]
print s
S.reverseWords(s)
print s
