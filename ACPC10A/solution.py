#!/usr/bin/env python

import sys

if __name__ == '__main__':
    for line in sys.stdin:
        numA, numB, numC = map(int, line.rstrip().split())

        if numA == 0 and numB == 0 and numC == 0:
            break

        if (numB - numA == numC - numB):
            print "AP {}".format(2 * numC - numB)
        else:
            print "GP {}".format(numC ** 2 / numB)
