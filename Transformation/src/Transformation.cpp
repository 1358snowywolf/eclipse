/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: isabell13
TASK: transform
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Transformations{
public:
	int move(vector<vector<char>> table, vector<vector<char>> final){
		auto backup = table;
		auto big_backup = table;

		clockwise90(table);
		if(table == final){
			return 1;
		}

		clockwise90(table);
		if(table == final){
			return 2;
		}

		clockwise90(table);
		if(table == final){
			return 3;
		}

		reflect(backup);
		if(backup == final){
			return 4;
		}

		clockwise90(backup);
		if(backup == final){
			return 5;
		}

		clockwise90(backup);
		if(backup == final){
			return 5;
		}

		clockwise90(backup);
		if(backup == final){
			return 5;
		}

		if(big_backup == final){
			return 6;
		}

		return 7;
	}

private:
	void clockwise90(vector<vector<char>>& table){
		int size = table.size();

		for(int i = 0; i < size / 2; i++){
			for(int j = i; j < size - i - 1; j++){
				int top_left = table[i][j];

				table[i][j] = table[size - 1 - j][i];
				table[size - 1 - j][i] = table[size - 1 - i][size - 1 - j];
				table[size - 1 - i][size - 1 - j] = table[j][size - 1 - i];
				table[j][size - 1 - i] = top_left;
			}
		}
	}

	void reflect(vector<vector<char>>& table){
		for(int i = 0; i < (int) table.size(); i++){
			vector<char> line = table[i];

			for(int d = 0; d < (int) line.size() - ((int) line.size() / 2); d++){
				swap(line[d], line[line.size() - 1 - d]);
			}

			table[i] = line;
		}
	}

};

int main() {
	ifstream fin ("transform.in");
	ofstream fout ("transform.out");

	int length;
	vector<vector<char>> table;
	vector<vector<char>> final;

	fin >> length;

	for(int i = 0; i < length; i++){
		vector<char> line;

		for(int d = 0; d < length; d++){
			char insert;
			fin >> insert;
			line.push_back(insert);
		}

		table.push_back(line);
	}

	for(int i = 0; i < length; i++){
		vector<char> line;

		for(int d = 0; d < length; d++){
			char insert;
			fin >> insert;
			line.push_back(insert);
		}

		final.push_back(line);
	}

	Transformations* transform = new Transformations();
	fout << transform->move(table, final) << endl;

	return 0;
}
