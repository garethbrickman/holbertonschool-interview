#!/usr/bin/env python3
""" Solving n queens """

import sys

# error handling for argv[1]

if len(sys.argv) == 1 or len(sys.argv) > 2:
    print("Usage: nqueens N")
    sys.exit(1)
N = sys.argv[1]
try:
    N_int = int(N)
except ValueError:
    print("N must be a number")
    sys.exit(1)
if N_int < 4:
    print("N must be at least 4")
    sys.exit(1)

# nqueens method
