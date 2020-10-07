
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const string INPUT_FILE="input.txt";
const string OUTPUT_FILE="output.txt";
const int SUCCESS = 0;
const int COULD_NOT_OPEN_FILE = -1;
const char CHAR_TO_SEARCH_FOR = ' ';

struct person{
	string first;
	string last;
};

bool compare_first(const person &a,const person &b){
	return a.first>=b.first;
}

bool compare_last(const person &a,const person &b){
	return a.last>=b.last;
}

int main() {
	vector<person> people;

	//lets open a file
	ifstream myfile;

	myfile.open(INPUT_FILE);
	if(!myfile.is_open())
		return COULD_NOT_OPEN_FILE;

	//stuff to parse the file contents with
	std::string line;
	std::string token;

	person mp;

	//read the file (parsing out tokens between ,'s
	while (!myfile.eof()) {

		//get a line from the file
		getline(myfile, line);

		//pass it to a stream object to parse
		stringstream iss(line);

		//lets separate out first and last names
		getline(iss, mp.first, CHAR_TO_SEARCH_FOR);
		getline(iss, mp.last, CHAR_TO_SEARCH_FOR);

		people.push_back(mp);
	}

	myfile.close();

	//sort it
	sort(people.begin(), people.end(),compare_first);

	//write it out
	//lets open a file
	ofstream my_ofile;

	my_ofile.open(OUTPUT_FILE);
	if(!my_ofile.is_open())
		return COULD_NOT_OPEN_FILE;

	for(int i=0; i<people.size(); i++)
		my_ofile<<people[i].first<<","<<people[i].last<<endl;

	return SUCCESS;

}
