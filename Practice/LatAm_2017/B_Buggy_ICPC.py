S = input()
for let in ('e', 'i', 'o', 'u'):
  S = S.replace(let, 'a')
n_v = S.count('a')
lo = 0
hi = len(S)-1
d = 1
while(n_v>1):
  if S[lo] != 'a':
    break
  while S[hi] != 'a':
    hi -= d
  lo, hi = hi, lo + d
  d *= -1
  n_v-=1
if n_v > 1 or (n_v == 1 and S[lo]!='a'):
  print(0)
elif n_v==0:
  print(1)
else:
  print(abs(lo-hi)+1)
