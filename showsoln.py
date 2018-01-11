#!/usr/bin/python3
# Copyright (c) 2018 Bart Massey
# [This program is licensed under the "MIT License"]
# Please see the file LICENSE in the source
# distribution of this software for license terms.


# Graphically display solutions to a "Movie Jobs" problem
# (Skiena, Algorithm Design Manual [2nd ed], Chapter 1).

from turtle import *
from sys import argv, stdin

def draw_scaled_interval(start, end, y):
    "Draw the given scaled interval at the given scaled y offset."

    penup()
    goto(start, y)
    pendown()
    dot(5 * pensize(), "black")
    goto(end, y)
    dot(5 * pensize(), "black")

def draw_interval(n, start, end, y):
    "Scale and draw the given interval and y."

    draw_scaled_interval(float(start) / float(n) / 4.0,
                         float(end) / float(n) / 4.0,
                         float(y + 1) / float(n + 2))

def draw_soln(inst, soln):
    "Draw the given instance and the solution overlay."

    indices = dict()
    n = len(inst)
    for i in range(len(inst)):
        indices[inst[i]] = i
        draw_interval(n, *inst[i], i)
    pencolor("red")
    for i in range(len(soln)):
        draw_interval(n, *soln[i], indices[soln[i]])

def read_intervals(f):
    "Return intervals read from the given file."

    intervals = []
    for line in f:
        start, end = line.split()
        intervals.append((int(start), int(end)))
    return intervals

# Do the processing.
if __name__ == "__main__":
    # Set up the display.
    setworldcoordinates(0, 0, 1, 1)

    # Read instance and solution from stdin.
    inst = read_intervals(open(argv[1], "r"))
    soln = read_intervals(open(argv[2], "r"))
    draw_soln(inst, soln)
    done()
