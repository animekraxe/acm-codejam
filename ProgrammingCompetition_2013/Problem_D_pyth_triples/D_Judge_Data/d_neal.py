#!/usr/bin/env python
# python2 please

import sys, math

first = True

while True:
    n = int(sys.stdin.readline().strip())
    if n == 0: break
    if not first: print
    first = False
    given = frozenset([int(sys.stdin.readline().strip()) for i in range(n)])
    sqrts = {i**2 : i for i in given}
    squares = frozenset(sqrts.keys())
    triples = sorted(frozenset(tuple(sorted((x,y,x+y)))
                               for x in squares
                               for y in squares
                               if x+y in squares
        ))
    for triple in triples:
        triple = [sqrts[x] for x in triple]
        assert all(x in given for x in triple)
        assert triple[0]**2 + triple[1]**2 == triple[2]**2
        print " ".join(str(x) for x in triple)
