//============================================================================
// Name        : LeetCode.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class ListNode{
	int val;
	ListNode* next;

	ListNode(int input){
		val = input;
		next = NULL;
	}
};

int climbStairs(int n){
	vector<int> steps (n, 0);
	steps[0] = 1;
	steps[1] = 2;
	steps[2] = 3;

	for(int i = 3; i < steps.size(); i++){
		steps[i] = steps[i - 1] + steps[i - 2];
	}

	return steps[steps.size() - 1];
};

ListNode* reverseList(ListNode* head) {
	if(!head || !head->next){
		return head;
	}
	else{
        ListNode* prev = NULL;
        while (head) {
            ListNode* node = head->next;
            head->next = prev;
            prev = head;
            head = node;
        }

        return prev;
	}
}

class Solution017 {
public:
    vector<string> letterCombinations(string digits) {

    }

private:
    vector<string> recursive(string digit, int position, unordered_map<int, vector<string>> ){

    }

    vector<string> words;
};

int main() {

	return 0;
}
