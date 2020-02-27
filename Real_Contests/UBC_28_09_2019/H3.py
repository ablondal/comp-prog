
from math import sqrt
C = int(input());
A = int(sqrt(C));
while True:
    if A*A % C == 0:
        break;
    A = A+1;

print(int(A*A/C));