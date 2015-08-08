__author__ = 'richard'
f=open('D:\MyPythonWorkspace\InputArray.txt','r')
for lines in f:
	S=set(lines.strip().split(' '))
f.close()
L=list(S)
L.sort()
f=open('D:\MyPythonWorkspace\OutputArray.txt','w')
f.write(str(L))