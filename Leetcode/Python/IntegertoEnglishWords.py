__author__ = 'Richard'

class Solution(object):
    #23 -> twenty three
    #input str
    def two(self, num):
        if num == '00':
            return []
        one = ['Zero', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine']
        two = ['Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen'
               ,'Eighteen', 'Nineteen']
        shi = ['Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']
        if 1<= int(num) and int(num) < 10:
            return [one[int(num)]]
        elif int(num) < 20:
            return [two[int(num)-10]]
        elif int(num)%10 == 0:
            return [shi[int(num)/10-2]]
        else:
            return [shi[int(num)/10-2] , one[(int)(num[1])]]
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return 'Zero'
        strnum=str(num)
        n = len(strnum)
        l=['Thousand', 'Million', 'Billion']
        one = ['Zero', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine']
        ans = []
        i = 0
        while i < n:
            wei = (n-i-1) / 3 - 1
            mod = (n-i-1) % 3 + 1
            if  mod == 1:
                if (int)(strnum[i:i+1]) > 0:
                    ans.append(one[ (int)(strnum[i:i+1]) ])
                    if wei>=0:
                        ans.append(l[wei])# if wei>=0 else ''
                i += 1
            elif mod == 2:
                res = self.two(strnum[i:i+2])
                if res != []:
                    ans.extend(res)
                    #ans.append(res[1])
                    if wei>=0:
                        ans.append(l[wei])# if wei>=0 else ''
                i += 2
            else:
                if (int)(strnum[i:i+1]) > 0:
                    ans.append(one[(int)(strnum[i:i+1])])
                    ans.append('Hundred')
                res = self.two(strnum[i+1:i+3])
                if  res != []:
                    ans.extend(res)
                    #ans.append(res[1])
                if ((int)(strnum[i:i+1]) > 0 or res!= []) and wei>=0:
                    ans.append(l[wei]) #if wei>=0 else ''
                i+=3
        return ' '.join(ans)



S = Solution()
num = 1010101
print S.numberToWords(num)