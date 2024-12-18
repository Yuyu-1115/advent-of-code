#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

int main(){
	std::unordered_map<int, std::unordered_set<int>> order;
	std::string dummy;
	std::ifstream fin;
	int a, b;
	int ans_1 = 0;
	int ans_2 = 0;
	fin.open("12-05.in");


	while (std::getline(fin, dummy) && dummy.size() > 1){
		std::istringstream sin;
		sin.str(dummy);
		std::getline(sin, dummy, '|');
		a = std::stoi(dummy);
		std::getline(sin, dummy);
		b = std::stoi(dummy);
		order[a].insert(b);
	}

	auto comp = [order](int const &a, int const &b){
			return order.at(a).find(b) != order.at(a).end();
	};

	while (std::getline(fin, dummy)){
		std::vector<int> ary;
		std::istringstream sin;
		sin.str(dummy);
		while (std::getline(sin, dummy, ',')){
			ary.push_back(std::stoi(dummy));
		}
		std::vector<int> sorted = ary;
		std::sort(sorted.begin(), sorted.end(), comp);
		if (ary == sorted){
			ans_1 += sorted[(sorted.size() + 1) / 2 - 1];
		}
		else {
			ans_2 += sorted[(sorted.size() + 1) / 2 - 1];
		}

	}

	fin.close();

	std::cout << "Part 1: " << ans_1 << std::endl;
	std::cout << "Part 2: " << ans_2 << std::endl;

	return 0;
}
