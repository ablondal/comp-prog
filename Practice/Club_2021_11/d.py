from math import sqrt
x1,y1 = map(int, input().split())
x2,y2 = map(int, input().split())
dist = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)
ans = dist*0.916297857297023
print(ans)