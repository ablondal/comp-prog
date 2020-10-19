nums, N = input().split()
N = int(N)
if (N%5 == 0 and nums[-1] not in ('?', '0', '5')):
  print("*")
elif (N%2 == 0 and nums[-1] not in ('?', '0', '2', '4', '6', '8')):
  print("*")
else:
  qs = []
  for i in range(len(nums)):
    if nums[len(nums)-i-1] == '?':
      qs.append(i);
  num = 10**(len(nums)-1) if nums[0] == '?' else 0
  nums = '0'.join(nums.split('?'))
  nums = int(nums)
  num = nums + num
  rem = num % N
  if rem == 0:
    print(num)
    exit(0)
  DP = [[(False, 0) for n in range(N)] for m in range(len(qs)+1)]
  DP[0][rem] = (True, 0)
  # print(DP)
  for i in range(1, len(qs)+1):
    for j in range(10):
      # print(i, j)
      rem = (10**qs[i-1] * j) % N
      for k in range(N):
        if DP[i-1][k][0] and not DP[i][(k+rem)%N][0]:
          DP[i][(k+rem)%N] = (True, j)
          if (k+rem)%N == 0:
            l = 0
            while i>0:
              B = 10**qs[i-1] * DP[i][l][1]
              num += B
              rem = (B) % N
              l = (l - rem) % N
              i-=1
            print(num)
            exit(0)
  
  print('*')