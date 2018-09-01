//============================================================================
// Name        : Wall.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Wall{
public:
	void greatWallofChina(const vector<int>& phases, vector<int>& wall){
		for(int i = 0; i < (int)phases.size(); i++){
			mongols(phases, wall);
		}

		return;
	}

private:
	void mongols(const vector<int>& current, vector<int>& wall){
		bool type = (current[0] == 1) ? true : false; //true = add     false = remove
		int left = current[1];
		int right = current[2];
		int height = current[3];

		if(type){ //add
			for(int i = left; i < right + 1; i++){
				if(wall[i] < height){
					wall[i] = height;
				}
			}
		}
		else{   //remove
			for(int i = left; i < right + 1; i++){
				if(wall[i] > height){
					wall[i] = height;
				}
			}
		}

		return;
	}
};

int main() {
	int size;
	cin >> size;
	int numberofphases;
	cin >> numberofphases;

	vector<vector<int>> phases;
	vector<int> current;
	vector<int> wall;
	for(int i = 0; i < 10; i++){
		wall.push_back(0);
	}

	Wall* mexico = new Wall();
//	mexico->greatWallofChina(phases, wall);

	for(int i = 0; i < numberofphases; i++){
		for(int d = 0; d < 4; d++){
			int tmp;
			cin >> tmp;
			current.push_back(tmp);
		}
		mexico->greatWallofChina(current, wall);
		current.clear();


//
//		phases.push_back(current);
//		current.clear();
	}




//	int size = 10;
//
//	int arr1[] = {1, 1, 8, 4};
//	int arr2[] = {2, 4, 9, 1};
//	int arr3[] = {2, 3, 6, 5};
//	int arr4[] = {1, 0, 5, 3};
//	int arr5[] = {1, 2, 2, 5};
//	int arr6[] = {2, 6, 7, 0};
//
//	vector<int> vec1 (arr1, arr1 + 4);
//	vector<int> vec2 (arr2, arr2 + 4);
//	vector<int> vec3 (arr3, arr3 + 4);
//	vector<int> vec4 (arr4, arr4 + 4);
//	vector<int> vec5 (arr5, arr5 + 4);
//	vector<int> vec6 (arr6, arr6 + 4);
//
//	phases.push_back(vec1);
//	phases.push_back(vec2);
//	phases.push_back(vec3);
//	phases.push_back(vec4);
//	phases.push_back(vec5);
//	phases.push_back(vec6);




	for(int i = 0; i < size; i++){
		cout << wall[i] << endl;
	}


	return 0;
}
