
s = input()
n = len(s)
s1 = s[:(n//3)]
s2 = s[(n//3):2*(n//3)]
s3 = s[2*(n//3):]
if (s1==s2): print (s1)
elif s1==s3: print (s1)
else: print (s2)