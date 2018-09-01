/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: isabell13
TASK: barn1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin ("barn1.in");
	ofstream fout ("barn1.out");
	vector<int> spaces;
	vector<int> stalls;
	int start;
	int end;
	int maxBoards;
	int stallNum;
	int cowNum;

	fin >> maxBoards;
	fin >> stallNum;
	fin >> cowNum;

	for(int i = 0; i < cowNum; i++){
		int input;
		fin >> input;
		stalls.push_back(input);
	}

	sort(stalls.begin(), stalls.end());

	for(int i = 0; i < cowNum; i++){
		if(i == 0){
			start = stalls[i];
			end = stalls[i + 1];
			i++;
		}
		else{
			end = stalls[i];
		}

		if(end - start > 1){
			spaces.push_back(end - start - 1);
		}

		start = end;
	}

	sort(spaces.begin(), spaces.end());
	int size = end - stalls[0] + 1;

	for(int i = 1; i < maxBoards; i++){
		size -= spaces[spaces.size() - i];

		if(size < cowNum){
			fout << cowNum << endl;
			return 0;
		}
	}

	fout << size << endl;

	return 0;
}
