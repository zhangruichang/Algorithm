__author__ = 'richard'
n=input()
L=[]
for i in range(n):
    name = raw_input()
    score = input()
    L.append([name, score])
L.sort(None, key=lambda student: (student[1], student[0]))

#print L
i=0
j=0
while i<range(len(L)-1):
    if L[i][1]!=L[i+1][1]:
        j=i+1
        break
    i=i+1
print L[j][0]
j=j+1
while L[j][1]==L[i+1][1]:
    print L[j][0]
    j=j+1
