/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: isabell13
TASK: palsquare
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <fstream>

using namespace std;

string base10tobase(int square, int base, const string numbers[]){
	string answer = "";

	while(square >= base){
		int divide = square / base;
		int module = square % base;

		answer = numbers[module] + answer;
		square = divide;
	}

	answer = numbers[square] + answer;

	return answer;
}

bool checkPalindrome(string number){
	if(number[0] == 0 || (number[(int) number.size() - 1] == 0 && number[0] == 0)){
		return false;
	}

	for(int i = 0; i < (int) number.size() - ((int) number.size() / 2); i++){
		if(number[i] != number[(int) number.size() - 1 - i]){
			return false;
		}
	}

	return true;
}

int main() {
	ifstream fin ("palsquare.in");
	ofstream fout ("palsquare.out");
	int base;
	string numbers[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

	fin >> base;

	for(int n = 1; n < 301; n++){
		int square = n * n;
		string newSquare = base10tobase(square, base, numbers);
		string newN = base10tobase(n, base, numbers);

		if(checkPalindrome(newSquare)){
			fout << newN << " " << newSquare << endl;
		}
	}

	return 0;
}
