#!/usr/bin/env python

import sys
import math

N = int(sys.stdin.readlines()[0])
res = 0
for i in xrange(1, int(math.sqrt(N)) + 1):
    res += N / i - i + 1
print res
