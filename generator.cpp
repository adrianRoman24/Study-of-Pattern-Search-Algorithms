#include <string.h>
#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

char *gen_random(int len) {
	char *random = (char *)malloc(sizeof(char) * len);

    char alphabet[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz ";

    for (int i = 0; i < len; ++i) {
        random[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
    }

    random[len] = 0;
    return random;
}


void test0() {
	string text = "";
	string word = "AB";
	//match only the first 5 times
	int count = 0;
	for (int i = 0; i < 20; i ++) {
		if (count < 5) {
			text.append(word);
			count ++;
		}
		text.append(gen_random(2));
	}
	cout<<text<<"\n";
	cout<<word;
}

void test1() {
	string text = "";
	string word = "ABC";
	//match only when i % 5 == 0 => 4 matches
	for (int i = 0; i < 20; i ++) {
		if (i % 5 == 0) {
			text.append(word);
		}
		else
			text.append(gen_random(5));
	}
	cout<<text<<"\n";
	cout<<word;
}

void test2() {
	string text = "";
	string word = "ABCDEFGHIJKLM";
	//12 matches
	for (int i = 0; i < 12; i ++) {
		text.append(word);
		text.append(gen_random(20));
	}
	cout<<text<<"\n";
	cout<<word;
}

void test3() {
	string text = "";
	string word = "Aa1Bb2Cc3Dd4Ee5";
	//15 matches
	for (int i = 0; i < 15; i ++) {
		text.append(word);
		text.append(gen_random(20));
	}
	cout<<text<<"\n";
	cout<<word;
}

void test4() {
	string text = "";
	string word = "Potrivire sufix prefix zzzz ceva text irelevant zzzz Potrivire sufix prefix";
	//8 matches
	for (int i = 0; i < 8; i ++) {
		text.append(gen_random(100));
		text.append(word);
		for (int j = 0; j < 1000; j ++)
			text.append(gen_random(100));
	}
	cout<<text<<"\n";
	cout<<word;
}

void test5() {
	string text = "";
	string word = "This is a match between prefix and sufix aaa this is not a match anymore This is a match between prefix and sufix";
	//10 matches
	for (int i = 0; i < 10; i ++) {
		text.append(gen_random(100));
		text.append(word);
		for (int j = 0; j < 1000; j ++)
			text.append(gen_random(100));
	}
	cout<<text<<"\n";
	cout<<word;
}

void test6() {
	string text = "";
	string word = "Worst case possbible first n minus one characters match and the last n character does not match";
	//select first n - 1 characters
	string trash = word;
	trash[trash.length() - 1] = 0;
	//1 match only for i = 6789
	for (int i = 0; i < 100000; i ++) {
		if(i == 6789)
			text.append(word);
		text.append(trash);
		text.append(gen_random(1));
	}
	cout<<text<<"\n";
	cout<<word;
}

void test7() {
	string text = "";
	string word = "The whole alphabet biggest test 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz This test "
	"will have no match so the algorithms will work to find out just that there is no match";
	//select first n - 1 characters
	string trash = word;
	trash[trash.length() - 1] = 0;
	//no match
	for (int i = 0; i < 1000000; i ++) {
		text.append(trash);
		text.append(gen_random(1));
	}
	cout<<text<<"\n";
	cout<<word;
}
int main() {
	//test0();
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
}