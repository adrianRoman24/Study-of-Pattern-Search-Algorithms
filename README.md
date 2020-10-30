Description of the project

	This is a study of the performance of the two algorithms for finding a pattern in a text.
	
	The rules for algo1 (Knuth-Morris-Pratt) can be found in Makefile
si algo2 (Rabin-Karp).

The executables that test the algorithms are test1 (for algo1) and test2 (for algo2). Although the efficiency of the Rabin-Karp algorithm is visible when we want to look for more patterns in a text, we have chosen for simplicity the same format of input and output data for the two algorithms.

The arguments of test1 and test2 are as follows: The first argument (args [1]) is the input file that contains the text in which the pattern is searched on the first line and the searched pattern on the second line. The output data is written to the output file,
given as the second argument (args [2]) and looks like this: the text "No match" if the pattern is not found in that text or clues where the pattern is found in that text on each line (ex: AA is found in BCAAD at index 2).

The tester (tester.sh) runs algorithms on the input data from the in folder, writes the output data to the out folder for each test and compares it with the reference file in the ref folder to check the correctness. The output files in the ref folder are correct because the files in were generated using the generator.cpp generator
(so I know how many times I inserted my word (pattern) in the text).

I chose to generate the input files somewhat "by hand" to choose some particular cases (worst case for example) and not some random strings for the two algorithms. I used, however, a
generator to be able to generate large tests. The generator also indicates the correctness of the ref files because the generator for each test specifies in the comments how many text-word matches there are. I chose a few matches (max 20) so that the output file can be easily tracked, but the text and pattern sizes are large.

Justification for the choice of tests:

* test0 and test1 - simple and easy to follow tests

* test2 and test3 - medium tests with a slightly longer pattern

* test4 and test5 - Tests in which the utility of the prefix-suffix vector (lps) is seen because the patten
was of form ABCXYZABC (prefix ABC = suffix ABC).

* test6 and test7 - worst case tests for both algorithms (the first n - 1 characters of the pattern match in the text, but the nth character does not match, so the n - 1 matches do not help us). In test6 there is only one match (chosen in the generator), and in test7 no
there is no match.

Summary: Makefile contains two build1 and build2 rules for each algorithm. Command
make generates object files and executable files for the two algorithms. The two executables have the format: ./test1 file_in file_out and ./test2 file_in file_out, where the file contains on the first line the text and on the second the searched word, and the output file
will contain on each line clues where the words are found in the text.

Remarks:

The tester.sh tester checks the correctness of the algorithms, but deletes all the generated files in order not to load the file. The make command will instead generate all object files
and executable.
Test 7 may take longer because there are larger files. After the execution of each program I fixed the execution time (only for the functions of the algorithm). It can be seen (especially in test 7) ​​that the Rabin-Karp algorithm (algo2) is slower than the Knuth-Morris-Pratt algorithm (algo1), which is correct because RK is useful when we want to look for more patterns (not only one) in a text.
Conclusion: It is confirmed that K-M-P is faster than R-K when looking for a single
word in a text.


References:

https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/