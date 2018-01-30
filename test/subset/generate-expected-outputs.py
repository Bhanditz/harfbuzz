#!/usr/bin/env python

# Pre-generates the expected output subset files (via fonttools) for
# specified subset test suite(s).

import os
import sys

from subprocess import check_call
from subset_test_suite import SubsetTestSuite


def usage():
	print "Usage: generate-expected-outputs.py <test suite file> ..."


def generate_expected_output(input_file, unicodes, output_path):
	check_call(["fonttools", "subset",
							input_file,
							"--unicodes=%s" % unicodes,
							"--output-file=%s" % output_path])


args = sys.argv[1:]
if not args:
	usage()

for path in args:
	with open(path, 'r') as f:
		test_suite = SubsetTestSuite(path, f.read())
		output_directory = test_suite.get_output_directory()

		print "Generating output files for %s" % output_directory
		for test in test_suite.tests():
			unicodes = test.unicodes()
			font_name = test.get_font_name()
			print "Creating subset %s/%s" % (output_directory, font_name)
			generate_expected_output(test.font_path, unicodes,
															 os.path.join(output_directory,
																						font_name))
