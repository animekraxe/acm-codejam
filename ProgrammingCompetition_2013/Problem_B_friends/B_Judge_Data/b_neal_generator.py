#!/usr/bin/env python
# python2, please

import sys, random

root = "Marcelo"

alphabet = "abcdefghijklmnopqrstuvwxy"
vowels = "aeiouy"

def random_name():
    name = [random.choice(alphabet) + random.choice(vowels)
            for i in range(5)]
    return "".join(name).capitalize()[:random.randint(4,10)]

def data_set(M):
    assert M <= 500, "MORE THAN 500 EDGES"
    N = int(M**0.75)

    names = [random_name() for i in range(N-1)]

    edges = []
    for i in range(int(N**0.5)):
        edges.append(sorted((root, random.choice(names))))

    while len(edges) < M:
        name1 = name2 = random.choice(names)
        while name1 == name2:
            name2 = random.choice(names)
        edges.append((name1, name2))
    return edges

M = 30
data_sets = []
while M <= 500:
    data_sets.append(data_set(M))
    M = int(M*1.05)
print (len(data_sets))
for d in data_sets:
    print (len(d))
    for (name1, name2) in d:
        print name1, name2
