__author__ = 'Richard'
class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        split = path.split('/')
        ans=[]
        for e in split:
            if e=='.' or e=='':
                pass
            elif e == '..':
                if len(ans)>0:
                    ans.pop()
            else:
                ans.append(e)
        ttans = ''
        for e in ans:
            ttans += '/' + e
        return ttans if len(ttans)>0 else '/'

S=Solution()
path='/.'
print S.simplifyPath(path)
