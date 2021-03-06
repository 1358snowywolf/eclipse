/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: isabell13
TASK: combo
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

class Locks{
public:
	Locks(int max_lock){
		max_number = max_lock;
	}

	int possibilities(vector<int> john, vector<int> master){
		recursion(john, 0);
		recursion(master, 0);

//		for(auto itr : combinations){
//			cout << itr << endl;
//		}

		return combinations.size();
	}

private:
	void recursion(vector<int> key, int index){
		if(index == 3){
			string input = to_string(key[0]) + to_string(key[1]) + to_string(key[2]);

			combinations.insert(input);
		}
		else{
			for(int i = -2; i <= 2; i++){
				vector<int> copy = key;
				copy[index] += i;

				if(copy[index] <= 0){
					copy[index] += max_number;
				}
				if(copy[index] > max_number){
					copy[index] %= max_number;
				}

				// pay extra attention to 1 to n case,
				// it is different from 0 to n-1 case.
				copy[index] = (copy[index] == 0) ? max_number : copy[index];

				recursion(copy, index + 1);
			}
		}
	}

	unordered_set<string> combinations;
	int max_number;
};

int main() {
	ifstream fin ("combo.in");
	ofstream fout ("combo.out");
	int max_number;
	vector<int> john;
	vector<int> master;
	int input;

	fin >> max_number;

	for(int i = 0; i < 3; i++){
		fin >> input;
		john.push_back(input);
	}

	for(int i = 0; i < 3; i++){
		fin >> input;
		master.push_back(input);
	}

	Locks* lock = new Locks(max_number);
	fout << lock->possibilities(john, master) << endl;

	return 0;
}
