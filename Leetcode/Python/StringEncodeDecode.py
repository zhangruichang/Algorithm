class Codec:

    def encode(self, strs):
        """Encodes a list of strings to a single string.
        
        :type strs: List[str]
        :rtype: str
        """
        return ''.join(s.replace('|', '||') + ' | ' for s in strs)

    def decode(self, s):
        """Decodes a single string to a list of strings.
        
        :type s: str
        :rtype: List[str]
        """
        return [t.replace('||', '|') for t in s.split(' | ')[:-1]]

strs = ['abc', '|abc']
codec = Codec()
print codec.encode(strs)
s = 'abc | ||abc | '
print s[:-1]
print codec.decode(s)