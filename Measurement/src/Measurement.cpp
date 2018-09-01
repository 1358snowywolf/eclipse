//============================================================================
// Name        : Measurement.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

class Milking{
public:
	int changing(map<int, pair<string, int>> schedule, unordered_map<int, unordered_set<string>> amount_name){
		int times_changed = 0;
		int global_max = 7;

		for(auto index : schedule){
			string changed_cow = schedule.at(index).first;

			for(auto index2 : amount_name){
				unordered_set<string> sets = amount_name.at(index2);

				if(sets.find(changed_cow) != amount_name.end()){
					int changed_litters = index2 - schedule.at(index).second;
					sets.erase(changed_cow);

					if(changed_litters == global_max){
						times_changed++;
					}

					if(amount_name.find(changed_litters) != amount_name.end()){
						amount_name.at(changed_litters).insert(changed_cow);
					}

					if(sets.empty()){
						if(amount_name.at(set) == global_max){
							int current_max = 0;

							for(auto index3 : amount_name){
								if(!amount_name.at(index3).empty()){
									current_max = max(current_max, index3);
								}
							}

							global_max = current_max;

							if(changed_litters != global_max){
								times_changed++;
							}
						}

					}
				}
			}
		}

		return times_changed;
	}
};

int main() {
	ifstream fin ("transform.in");
	ofstream fout ("transform.out");

	int times_recorded;
	map<int, pair<string, int>> schedule;
	unordered_map<int, unordered_set<string>> amount_name;
	unordered_set<int> seven;

	fin >> times_recorded;

	for(int i = 0; i < times_recorded; i++){
		int date;
		string name;
		int changed;

		fin >> date;
		fin >> name;
		fin >> changed;

		pair<string, int> string_int (name, changed);
		pair<int, pair<string, int>> input (date, string_int);
		schedule.insert(input);

		if(seven.find(name) == seven.end()){
			seven.insert(name);
		}
	}

	pair<int, unordered_set<string>> input (7, seven);
	amount_name.insert(input);

	fin >> times_recorded;

	Milking* milk = new Milking();
	fout << milk->changing(schedule, amount_name) << endl;

	return 0;
}
