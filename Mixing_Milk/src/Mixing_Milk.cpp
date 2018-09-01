/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: isabell13
TASK: milk
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
	ifstream fin ("milk.in");
	ofstream fout ("milk.out");
	int milk_needed = 0;
	int milk_suppliers = 0;
	map<int, int> used;

	fin >> milk_needed;
	fin >> milk_suppliers;

	if(milk_needed == 0){
		fout << 0 << endl;
		return 0;
	}

	for(int i = 0; i < milk_suppliers; i++){
		int price;
		int units;
		fin >> price;
		fin >> units;

		if(used.find(price) == used.end()){
			pair<int, int> input (price, units);

			used.insert(input);
		}
		else{
			used.at(price) += units;
		}
	}

	int money = 0;
	int milk = 0;

	for(auto index : used){
		int buying = 0;
		int price = index.first;
		int capacity = index.second;

		while(buying < capacity){
			if(milk == milk_needed){
				fout << money << endl;
				return 0;
			}

			milk++;
			money += price;
			buying++;
		}

		if(milk == milk_needed){
			fout << money << endl;
			return 0;
		}
	}

	return 0;
}
