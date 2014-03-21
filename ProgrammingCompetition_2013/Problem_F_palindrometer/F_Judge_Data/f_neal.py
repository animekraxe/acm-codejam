#!/usr/bin/env python
# python 2

import sys

def value(digits):
    return int("".join(str(d) for d in digits))

while True:
    digits = [int(d) for d in sys.stdin.readline().strip()]
    if digits == [0]: break
    mid = len(digits)/2
    left  = digits[:-mid]
    right = digits[-mid:]
    new_right = list(reversed(left[:mid]))
    
    if new_right < right:
        # increment left
        for i in range(len(left)-1, -1, -1):
            if left[i] == 9:
                left[i] = 0
            else:
                left[i] += 1
                break
        new_right = list(reversed(left[:mid]))

    palindrome = left + new_right
        
    print value(palindrome) - value(digits)
