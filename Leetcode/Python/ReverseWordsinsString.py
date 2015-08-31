__author__ = 'richard'
class Solution:
    # @param s, a string
    # @return a string
    def reverse_words(self, s):
        #print [word[::-1] for word in s[::-1].split()]
        return ' '.join([word[::-1] for word in s[::-1].split()])

    def reverseWords(self, s):
        s[:] = ' '.join(''.join(s).split()[::-1])

S = Solution()

s='I am Zhang Ruichang'
list_s = [i for i in s]
print list_s
S.reverseWords(list_s)
print list_s