#!/bin/bash

EXE1=test1
EXE2=test2
num_tests=8;
algo1_tests=0;
algo2_tests=0;

#compile
make build1 >> /dev/null

#test first algorithm
echo -e "\n================== Knuth-Morris-Pratt ==================\n"

for (( i=0; i < $num_tests; i++ ))
do
	./test1 ./in/test$i.in ./out/test$i.out
	diff ./out/test$i.out ./ref/ref$i.out >> /dev/null
	if [ $? -eq 0 ]; then
		echo -e "Test "$i": ............................... OK"
		algo1_tests=$((algo1_tests+1));
	else
		echo -e "Test "$i": ............................... FAIL"
	fi
done

echo -e "\n==============================================\n"
echo -e ""$algo1_tests"/"$num_tests" tests passed\n";

#compile
make build2 >> /dev/null

#test second algorithm
echo -e "\n================== Rabin-Karp ==================\n"

for (( i=0; i < $num_tests; i++ ))
do
	./test2 ./in/test$i.in ./out/test$i.out
	diff ./out/test$i.out ./ref/ref$i.out >> /dev/null
	if [ $? -eq 0 ]; then
		echo -e "Test "$i": ............................... OK"
		algo2_tests=$((algo2_tests+1));
	else
		echo -e "Test "$i": ............................... FAIL"
	fi
done

echo -e "\n==============================================\n"
echo -e ""$algo2_tests"/"$num_tests" tests passed\n";

rm test1
rm test2
rm *.o
