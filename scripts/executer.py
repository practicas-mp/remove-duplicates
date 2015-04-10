#!/usr/bin/python
import sys, os

program_name = sys.argv[1]
arguments = xrange(100, 30000, 500)

for argument in arguments:
	os.system("./" + program_name + " " + str(argument))