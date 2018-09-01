/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: isabell13
TASK: crypt1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>

using namespace std;

class Multiplication{
public:
	int possibilities(unordered_set<int> numbers){
		int first = 0;
		int second = 0;
		recursion(first, second, 0, numbers);

		return work.size();
	}

private:
	void recursion(int first, int second, int level, unordered_set<int> numbers){
		if(level == 5){
			if(check(first, second, numbers)){
				string product = to_string(first) + to_string(second);
				work.insert(product);
			}
		}
		else{
			if(level < 3){
				first *= 10;

				for(auto itr : numbers){
					recursion(first + itr, second, level + 1, numbers);
				}
			}
			else{
				second *= 10;

				for(auto itr : numbers){
					recursion(first, second + itr, level + 1, numbers);
				}
			}
		}
	}

	bool check(int first, int second, unordered_set<int> numbers){
		int ones = second % 10;
		int tens = second / 10;

		int firstResult = ones * first;
		int secondResult = tens * first;

		if(!helper(firstResult, numbers, 3) || !helper(secondResult, numbers, 3)){
			return false;
		}

		int finalResult = first * second;

		return helper(finalResult, numbers, 4);
	}

	bool helper(int result, unordered_set<int> numbers, int size){
		int digits = 0;

		int max = (size == 3) ? 999 : 9999;
		if (result > max) {
			return false;
		}

		while(result > 0){
			int number = result % 10;
			digits++;

			if(numbers.find(number) == numbers.end()){
				return false;
			}

			result /= 10;
		}

		return true;
	}

	unordered_set<string> work;
};

int main() {
	ifstream fin ("crypt1.in");
	ofstream fout ("crypt1.out");
	unordered_set<int> numbers;
	int N;

	fin >> N;

	if(N == 0){
		fout << 0 << endl;
		return 0;
	}

	for(int i = 0; i < N; i++){
		int input;
		fin >> input;
		numbers.insert(input);
	}

	Multiplication* mul = new Multiplication();
	fout << mul->possibilities(numbers) << endl;

	return 0;
}
