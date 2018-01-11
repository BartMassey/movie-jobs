#!/usr/bin/python3
# Copyright (c) 2018 Bart Massey
# [This program is licensed under the "MIT License"]
# Please see the file LICENSE in the source
# distribution of this software for license terms.

# Generate a random "Movie Jobs" instance.

# Generated intervals are "half-open": they
# are considered to start at the start position
# and end just before the end position.

from random import randrange
from sys import argv

def geninst(n):
    "Generate an instance of size n."

    intervals = []
    for _ in range(n):
        width = randrange(1, n)
        start = randrange(4 * n - width)
        end = start + width
        intervals.append((start, end))
    return intervals

# Generate and display an instance.
if __name__ == "__main__":
    n = int(argv[1])
    inst = geninst(n)
    for i in inst:
        print(*i)

