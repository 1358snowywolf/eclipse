//============================================================================
// Name        : Lamp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

class Lamp{
public:
	vector<vector<int>> onOff(vector<int> lamps, vector<int> on, vector<int> off){
		recursion(lamps, on, off, 0, 0);
		return answer;
	}

private:
	void button1(vector<int>& lamps){
		for(int i = 0; i < lamps.size(); i++){
			lamps[i] = (lamps[i] == 0) ? 1 : 0;
		}
	}

	void button2(vector<int>& lamps){
		for(int i = 0; i < lamps.size(); i++){
			if(i % 2 == 1){
				lamps[i] = (lamps[i] == 0) ? 1 : 0;
			}
		}
	}

	void button3(vector<int>& lamps){
		for(int i = 0; i < lamps.size(); i++){
			if(i % 2 == 0){
				lamps[i] = (lamps[i] == 0) ? 1 : 0;
			}
		}
	}

	void button4(vector<int>& lamps){
		for(int i = 0; i < lamps.size(); i++){
			if(i % 3 == 2){
				lamps[i] = (lamps[i] == 0) ? 1 : 0;
			}
		}
	}

	bool check(vector<int> lamps, vector<int> on, vector<int> off){
		int fitOn = 0;
		int fitOff = 0;

		for(int i = 0; i < lamps.size(); i++){
			for(int d = 0; d < on.size(); d++){
				if(on[d] == off[i]){
					fitOn++;
					break;
				}
			}
			for(int d = 0; d < off.size(); d++){
				if(off[d] == off[i]){
					fitOff++;
					break;
				}
			}
		}

		if(fitOff == off.size() && fitOn == on.size()){
			return true;
		}
		else{
			return false;
		}
	}

	void choose(vector<int>& lamps, int index){
		if(index == 0){
			button1(lamps);
		}
		else if(index == 1){
			return button2(lamps);
		}
		else if(index == 2){
			return button3(lamps);
		}
		else{
			return button4(lamps);
		}
	}

	void recursion(vector<int> lamps, vector<int> on, vector<int> off, int index, int count){
		if(check(lamps, on, off)){
			answer.push_back(lamps);
		}
		else if(index == 4){
			return;
		}
		else{
			auto original = lamps;
			choose(lamps, index);

			recursion(lamps, on, off, index + 1, count + 1);
			recursion(original, on, off, index + 1, count);
		}
	}

	vector<vector<int>> answer;
};

int main() {
	int size;
	int max_presses;
	int current;
	vector<int> lamps;
	vector<int> on;
	vector<int> off;

	cin >> size;
	cin >> max_presses;
	cin >> current;

	for(int i = 0; i < size; i++){
		lamps.push_back(0);
	}

	while(current != -1){
		on.push_back(current);
		cin >> current;
	}

	cin >> current;

	while(current != -1){
		off.push_back(current);
		cin >> current;
	}

	Lamp* lights = new Lamp();
	vector<vector<int>> permutations = lights->onOff(lamps, on, off);

	if(permutations.size() == 0){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	for(int i = 0; i < permutations.size(); i++){
		vector<int> current = permutations[i];

		if(current.size() < max_presses){
			for(int d = 0; d < current.size(); i++){
				cout << current[i] << " ";
			}

			cout << endl;
		}
	}

	return 0;
}
