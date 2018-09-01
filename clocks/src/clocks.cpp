//============================================================================
// Name        : clocks.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Clocks{

public:
    vector<int> clocks(vector<int> setup, vector<string> moveset){
        vector<int> sacrafice;
        return recur(setup, moveset, sacrafice, 0);
    }

private:
    vector<int> recur(vector<int> setup, vector<string> moveset, vector<int> used, int index) {
    	vector<int> res;
        if (check(setup)) {
            return used;
        }
        if (index >= (int)moveset.size()) {
            return res;
        }

        for (int i = 0; i < 4; i++) {
            if (i != 0) {
				setup = apply(setup, moveset[index]);
				used.push_back(index);
            }

            res = recur(setup, moveset, used, index + 1);

            if (res.size() > 0) {
                return res;
            }
        }
        return res;
    }

    vector<int> apply(vector<int> setup, string changing){
        for(int i = 0; i < (int)changing.size(); i++){
            setup[changing[i] - 'A'] = (setup[changing[i] - 'A'] + 3) % 12; // move to mod
        }

        return setup;
    }

    bool check(vector<int> setup){
        for(int i = 0; i < (int)setup.size(); i++){
            if(setup[i] != 0){
                return false;
            }
        }
        return true;
    }

};

int main(int argc, char** argv) {

    vector<int> vec;
    int tmp;
    for(int i = 0; i < 9; i++){
    	cin >> tmp;
    	vec.push_back(tmp);
    }

    string array[] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
    vector<string> moveset (array, array + sizeof(array) / sizeof(string));

    Clocks* cuckoo = new Clocks();
    vector<int> res = cuckoo->clocks(vec, moveset);

    for(int i = 0; i < res.size(); i++){
        cout << res[i]+1 << " ";
    }

    cout << endl;
    return 0;
}
