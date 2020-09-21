def dist(x1, y1, x2=0, y2=0):
    return (((x2-x1)**2) + ((y2-y1)**2)) ** (1 / 2)

nTests = int(input())
#print("There will be:", nTests, "tests")

for i in range(nTests):
    bx, by = [float(x) for x in input().split()]
    #print("book position:", bx, by)
    nCandles = int(input())
    #print("number of candles:", nCandles)
    found = False
    for j in range(nCandles):
        cx, cy = [float(x) for x in input().split()]
        #print("candle position:", cx, cy)
        if dist(bx, by, cx, cy) < 8.0:
            print("light a candle")
            found = True
            break
    if not found:
        print("curse the darkness")