#!/bin/env python

import sys

if __name__ == '__main__':
    for f in sys.stdin:
        print(f"Next file: '{f.strip()}'")  # stripping newline symbol
