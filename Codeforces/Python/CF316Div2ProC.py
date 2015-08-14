__author__ = 'zhangruichang'

n, m = [int(x) for x in raw_input().split()]
s = raw_input()

cnt = 0
ans = 0
for i in range(len(s)):
    if s[i] == '.':
        cnt = cnt + 1
    else:
        if cnt > 0:
            ans += (cnt - 1)
            cnt = 0
if cnt > 0:
    ans += (cnt - 1)
for i in range(m):
    line = raw_input().split()
    pos = int(line[0]) - 1
    ch = line[1]
    if ch == '.':
        if s[pos] == '.':
            pass
        else:
            if (pos == 0 or s[pos - 1] != '.') and (pos == n - 1 or s[pos + 1] != '.'):
                pass
            elif ((pos == 0 or s[pos - 1] != '.') and (pos == n - 1 or s[pos + 1] == '.')) or (
                    (pos == 0 or s[pos - 1] == '.') and (pos == n - 1 or s[pos + 1] != '.')):
                ans = ans + 1
            else:
                ans = ans + 2
    elif ch != '.':
        if s[pos] != '.':
            pass
        else:
            if (pos == 0 or s[pos - 1] != '.') and (pos == n - 1 or s[pos + 1] != '.'):
                pass
            elif ((pos == 0 or s[pos - 1] != '.') and (pos == n - 1 or s[pos + 1] == '.')) or (
                    (pos == 0 or s[pos - 1] == '.') and (pos == n - 1 or s[pos + 1] != '.')):
                ans = ans - 1
            else:
                ans= ans - 2
    #print ch[0]
    s = s[:pos] + ch + s[(pos+1):]
    #s[pos] = ch[0]
    print ans
