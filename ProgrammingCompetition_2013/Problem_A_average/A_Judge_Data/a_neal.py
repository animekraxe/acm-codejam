#!/usr/bin/env python
# (requires python 2)

import sys

first = True

while True:
    n = int(sys.stdin.readline().strip())
    if n == 0:
        break
    if not first: print
    first = False
    ints = [int(sys.stdin.readline().strip()) for i in range(n)]
    for i in range(4,n+1):
        print int(sum(ints[i-4:i])/4)
