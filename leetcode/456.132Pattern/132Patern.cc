//https://leetcode.com/problems/132-pattern/#/description
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool find132pattern(vector<int>& nums) {
	if (nums.size() == 0)
		return false;

	int min_i = INT_MAX;
	for (int j = 0; j < nums.size() - 1; j++) {
		min_i = min(min_i, nums[j]);
		for (int k = j + 1; k < nums.size(); k++) {
			if (nums[k] < nums[j] && min_i < nums[k]) {
				cout << min_i << "," << nums[j] << "," << nums[k] << endl;
				return true;
			}
		}
	}
	return false;
}

int main() {
	vector<int> vec = { 1,0,1,-4,-3 };
	find132pattern(vec);
	int in;
	cin >> in;
}