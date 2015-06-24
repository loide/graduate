#!/usr/bin/python
def findVowels():
	vowels = 'aeiouAEIOU'
	numberOfVowels = 0;
	s = raw_input('Insert a string: ');
	print s
	for v in s:
		if v in vowels:
			numberOfVowels = numberOfVowels + 1;
	print "Number of vowels: %d" % numberOfVowels
findVowels()
