#include "algo1.h"
#include <fstream>
#include <ctime>

int main (int argc, char *argv[]) {
	//the occurences of pattern in text
	list <int> appearences;

	//word is the pattern searched
	string word;
    
	//text is where we search for for the pattern
    string text;
    if (argc != 3) {
    	cout<<"Wrong number of arguments\n";
    	return -1;
    }
    
    //read test date from stdin
    ifstream readFile (argv[1]);
    getline(readFile, text);
    getline(readFile, word);
    readFile.close();

    //solve the problem by calling the corresponding function from algo.h
    clock_t time_req;
    time_req = clock();
    Knuth_Morris_Pratt(word, text, appearences);
    time_req = clock() - time_req;
	cout << "Algorithm execution time: " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
    
    //output result to stdout
    ofstream writeFile (argv[2]);
    if (appearences.size() == 0) {
    	writeFile<<"No match";
    }
    else
    {
    	list <int> :: iterator it;
    	for (it = appearences.begin(); it != appearences.end(); ++ it) {
    		writeFile<<*it<<"\n";
    	}
    }
    writeFile.close();

    return 0;
}