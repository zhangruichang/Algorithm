__author__ = 'richard'
a=input()
List=[]
for i in range(a):
    com=raw_input().strip().split(' ')
    if com[0] == 'insert':
        List.insert(int(com[1]), int(com[2]))
    elif com[0] == 'print':
        print List
    elif com[0] == 'remove':
        List.remove(int(com[1]))
    elif com[0] == 'append':
        List.append(int(com[1]))
    elif com[0] == 'sort':
        List.sort()
    elif com[0] == 'reverse':
        List.reverse()
    elif com[0] == 'pop':
        List.pop()
    elif com[0] == 'index':
        List.index(int(com[1]))
    else:
        List.count(int(com[1]))


