#!/usr/bin/env python

import re
import sys

if __name__ == '__main__':
    nTests = int(sys.stdin.readline().strip())

    word_sep = re.compile(r'\w+')
    for i in xrange(nTests):
        print len(set(
            x.group(0) for x in word_sep.finditer(sys.stdin.readline().strip())
        ))
