#!/usr/bin/env python
# python2 please

import sys, os

while True:
    n = int(sys.stdin.readline().strip())
    if n == 0: break
    names = sorted([sys.stdin.readline().strip() for i in range(n)])
    mid = len(names)/2
    A, B = names[mid-1:mid+1]
    assert A != B, "HEY! CAN'T SEPARATE EQUAL NAMES"
    common = os.path.commonprefix([A, B])
    if A == common:
        print A
    else:
        # note: next letter in A cannot be "Z"
        print common + chr(ord(A[len(common)])+1)
