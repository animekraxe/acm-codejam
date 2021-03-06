#!/usr/bin/env python
# python2, please

import sys, collections

M = int(sys.stdin.readline().strip())

root = "Marcelo"

for i in range(M):
    n = int(sys.stdin.readline().strip())
    nbrs = collections.defaultdict(lambda: set())
    for j in range(n):
        a, b = sys.stdin.readline().split()
        nbrs[a].add(b)
        nbrs[b].add(a)

    suggestions = sorted([
        a for a in nbrs
        if a != root
        and a not in nbrs[root]
        and len(nbrs[a].intersection(nbrs[root])) >= 2])

    print len(suggestions)
    print "\n".join(suggestions)
