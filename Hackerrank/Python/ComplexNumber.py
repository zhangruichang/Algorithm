import math
class ComplexNumber:
    def __init__(self, real, imag):
        self.real=real
        self.imag=imag

    def __add__(self, C):
        Ans=ComplexNumber(0, 0)
        Ans.real=self.real+C.real
        Ans.imag=self.imag+C.imag
        return Ans

    def __sub__(self, C2):
        Ans=ComplexNumber(0, 0)
        Ans.real=self.real-C2.real
        Ans.imag=self.imag-C2.imag
        return Ans

    def __mul__(self, C):
        Ans=ComplexNumber(0, 0)
        Ans.real=self.real*C.real-self.imag*C.imag
        Ans.imag=self.real*C.imag+self.imag*C.real
        return Ans

    def __div__(self, C):
        #(a+bi)/(c+di)=(ec+fd)/(c^2+d^2) + (fc-ed)/(c^2+d^2)i
        Ans=ComplexNumber(0, 0)
        Ans.real=(self.real*C.real+self.imag*C.imag)/(C.real*C.real+C.imag*C.imag)
        Ans.imag=(self.imag*C.real-self.real*C.imag)/(C.real*C.real+C.imag*C.imag)
        return Ans

    def Mod(self):
        return math.sqrt(self.real*self.real+self.imag*self.imag)
        #print ('%.2f'% mod)

    def Show(self):
        if self.real!=0 and self.imag!=0:
            if self.imag>0:
                print ("%.2f" % self.real)+' + '+("%.2f" % self.imag)+'i'
            else:
                print ("%.2f" % self.real)+' - '+("%.2f" % -self.imag)+'i'
        elif self.real!=0:
            print ("%.2f" % self.real)
        elif self.imag!=0:
            #if self.imag>0:
            print ("%.2f" % self.imag)+'i'
        else:
            print ("%.2f" % 0)


a, b=[float(x) for x in raw_input().split()]
C1=ComplexNumber(a, b)
c, d=[float(x) for x in raw_input().split()]
C2=ComplexNumber(c, d)
(C1+C2).Show()
(C1-C2).Show()
(C1*C2).Show()
(C1/C2).Show()
print ("%.2f" % C1.Mod())
print ("%.2f" % C2.Mod())