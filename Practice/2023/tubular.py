import time
import sys
from collections import defaultdict
from bisect import bisect_right


def main():
    inp = open(0).read().split()
    n, l, v, q = map(int, inp[:4])

    times = [
        (int(inp[2*i+4]) if inp[2*i+5]=='LEFT' else
            (l-int(inp[2*i+4]))) for i in range(n)
    ]
    times.sort()

    qs = [
        str(n-bisect_right(times, v*int(inp[2*n+4+i])))
        for i in range(q)
    ]

    print("\n".join(qs))


if __name__ == "__main__":
    main()