#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

int part1(std::vector<std::string> ary){
	int sum = 0;
	std::regex num("([0-9]{1,3})");

	for (auto &item: ary){
		std::vector<int> op;
		for (auto itr = std::sregex_iterator(item.begin(), item.end(), num); itr != std::sregex_iterator(); itr++){
			op.push_back(std::stoi(itr->str()));
		}
		sum += op[0] * op[1];
	}

	return sum;
}


int main(){
	std::ifstream fin;
	std::regex ins("(mul\\([0-9]{1,3},[0-9]{1,3}\\)|do\\(\\)|don't\\(\\))"); 
	std::string input;
	std::vector<std::string> matched, matched_2, queue;
	int ans2 = 0, last = 0;
	bool flag = true;

	fin.open("12-03.in");
	
	while (std::getline(fin, input)){
		for (auto itr = std::sregex_iterator(input.begin(), input.end(), ins); itr != std::sregex_iterator(); itr++){
			if (itr->str() != "do()" and itr->str() != "don't()"){
				matched.push_back(itr->str());
			}
			matched_2.push_back(itr->str());
		}
	}

	fin.close();

	for (int i = 0; i < matched_2.size(); i++){
		if (matched_2[i] == "don't()"){
			flag = false;
		}
		else if (matched_2[i] == "do()"){
			flag = true;
		}
		else if (flag){
			queue.push_back(matched_2[i]);
		}
	}

	std::cout << "Part1: " << part1(matched) << std::endl;
	std::cout << "Part2: " << part1(queue) << std::endl;
}
