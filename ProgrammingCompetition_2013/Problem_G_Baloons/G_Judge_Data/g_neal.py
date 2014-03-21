#!/usr/bin/env python
# python 2 please

import sys, collections

def read_triple():
    return [int(x) for x in sys.stdin.readline().split()]

while True:
    N, A, B = read_triple()
    if N == A == B == 0: break
    teams = [read_triple() for i in range(N)]
    
    assert A+B >= sum(k for (k,dA,dB) in teams), "NOT ENOUGH BALLOONS"

    sunk_cost = sum(k*min(dA, dB) for (k, dA, dB) in teams)
    teams  = [(k, dA - min(dA, dB), dB - min(dA, dB)) for (k, dA, dB) in teams if k > 0]

    atA    = [(k, dB) for (k, dA, dB) in teams if dA == 0]
    atB    = [(k, dA) for (k, dA, dB) in teams if dA > 0]

    atA.sort(key = (lambda (k,dB): dB))
    atB.sort(key = (lambda (k,dA): dA))

    while atA and A > 0:
        (k, dB) = atA.pop()
        if k <= A:
            A -= k
        else:
            atA.append((k-A, dB))
            A = 0

    while atB and B > 0:
        (k, dA) = atB.pop()
        if k <= B:
            B -= k
        else:
            atB.append((k-B, dA))
            B = 0

    print sunk_cost + sum(k*d for (k,d) in atA + atB)
