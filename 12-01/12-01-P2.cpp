#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main(){
	std::vector<int> left;
	std::unordered_map<int, int> right;
	std::ifstream fin;
	std::string pre_processed;
	int index;
	int ans = 0;
	fin.open("Dec 1.in");
	while (std::getline(fin, pre_processed)){
		index = pre_processed.find(' ');
		left.push_back(
				std::stoi(
				pre_processed.substr(0, index))
				);
		right[std::stoi(
				pre_processed.substr(index + 1, pre_processed.size()))]++;
	}
	fin.close();
	std::sort(left.begin(), left.end());

	for (int i = 0; i < right.size(); i++){
		ans += left[i] * right[left[i]];
	}

	std::cout << ans;

	return 0;

}
