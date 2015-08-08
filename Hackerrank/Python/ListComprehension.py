__author__ = 'richard'
x = input()
y = input()
z = input()
n = input()
Ans = list()
for i in range(x+1):
    for j in range(y+1):
        for k in range(z+1):
            if i+j+k!=n:
                Ans.append([i, j, k])
print Ans
