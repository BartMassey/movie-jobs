#!/usr/bin/python3
# Copyright (c) 2018 Bart Massey
# [This program is licensed under the "MIT License"]
# Please see the file LICENSE in the source
# distribution of this software for license terms.

# Generate all subsets of a given set.

def subsets(s):
    "Return a list of all subsets of a given set s."

    t = [set()]
    for e in s:
        v = list(t)
        for w in t:
            v.append({e} | w)
        t = v
    return t
