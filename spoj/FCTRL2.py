#!/usr/bin/env python
# FCTRL2

cases = int(raw_input(''))
while cases:
    n = int(raw_input(''))
    fac = 1
    for i in range(2, n + 1):
        fac *= i
    cases -= 1
    print fac
