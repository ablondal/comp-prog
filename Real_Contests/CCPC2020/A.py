n,m,k = [int(x) for x in input().split()]
print( "Alex" if (k%(n+m) < n) else "Barb" )