import sys
from math import gcd

def gcdext(a, b): 
    if a == 0:
        return b,0,1
    gcd,x1,y1 = gcdext(b%a, a)
    x = y1 - (b//a) * x1
    y = x1
    return gcd,x,y

def crt(m1, r1, m2, r2):
    m = m1*m2;
    _, M1, _ = gcdext(m1, m2)
    _, M2, _ = gcdext(m2, m1)
    x1 = (r1 * M2 * m2);
    x2 = (r2 * M1 * m1);
    return (x1+x2)%m;

n, m = map(int, input().split())

if n==1 and m==1:
    print(1)
elif m==1 or n==1:
    print(2)
elif gcd(n,m)>1:
    print((n*m)//gcd(n,m))
else:
    # print(crt(m,1,n,0), crt(m,0,n,1))
    print(min(n*m,crt(m,1,n,0),crt(m,0,n,1)))

