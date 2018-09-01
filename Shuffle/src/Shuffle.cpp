//============================================================================
// Name        : Shuffle.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Bovine{
public:
	vector<int> dance(vector<int> final, vector<int> shuffle){
		return recursive(final, shuffle, 0);
	}

private:
	vector<int> recursive(vector<int> b, vector<int> np, int index){
		if(index == 3){
			return b;
		}
		else{
			vector<int> a (np.size(), 0);

			for(int i = 0; i < (int) b.size(); i++){
				a[i] = b[np[i] - 1];
			}

			return recursive(a, np, index + 1);
		}
	}
};

int main() {
	ifstream fin ("shuffle.in");
	ofstream fout ("shuffle.out");

	int number_of_cows;
	fin >> number_of_cows;

	vector<int> shuffle;
	vector<int> final;

	for(int i = 0; i < number_of_cows; i++){
		int input;
		fin >> input;
		shuffle.push_back(input);
	}

	for(int i = 0; i < number_of_cows; i++){
		int input;
		fin >> input;
		final.push_back(input);
	}

	Bovine* dance = new Bovine();
	vector<int> original = dance->dance(final, shuffle);

	for(int i = 0; i < (int) original.size(); i++){
		fout << original[i] << endl;
	}

	return 0;
}
