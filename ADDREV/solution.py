#!/usr/bin/env python

import sys

def RevreseNumber(num):
    revNum = 0
    while (num > 0):
        revNum = revNum * 10 + num % 10
        num /= 10
    return revNum

if __name__ == '__main__':
    nTests = int(sys.stdin.readline().strip())
    res = 0
    for i in xrange(nTests):
        first, second = sys.stdin.readline().strip().split()
        print RevreseNumber(RevreseNumber(int(first)) + RevreseNumber(int(second)))
