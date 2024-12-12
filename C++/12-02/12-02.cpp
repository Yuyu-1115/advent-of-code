#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int part1(std::vector<int> report){
	bool increasing;

	if (report[1] > report[0]){
		increasing = true;
	}
	else if (report[1] < report[0]){
		increasing = false;
	}
	else {
		return 0;
	}

	for (int i = 1; i < report.size(); i++){
		if (increasing){
			if (report[i] > report[i - 1] ){
				if (report[i] - report[i - 1] > 3){
					return 0;	
				}
			}
			else {
				return 0;
			}
		}
		else {
			if (report[i] < report[i - 1]){
				if (report[i - 1] - report[i] > 3){
					return 0;
				}
			}
			else {
				return 0;
			}
		}
	}

	return 1;
}

int part2(std::vector<int> report){
	for (int r = 0; r < report.size() ; r++){
		std::vector<int> temp = report;
		temp.erase(temp.begin() + r);
		if (part1(temp) == 1){
			return 1;
		}
	}
	return 0;
}

int main(){

	int safe = 0, safe_2 = 0;
	int count = 0;
	std::string line, dummy;

	std::ifstream fin;

	fin.open("12-02.in");
	while (std::getline(fin, line)){
		std::vector<int> report;
		std::istringstream in;
		in.str(line);
		count++;
		while (std::getline(in, dummy, ' ')){
			report.push_back(stoi(dummy));
		}
		std::cout << "Case " << count << " ";
		if (part1(report) == 1){
			safe++;
			safe_2++;
			std::cout << "Safe" << std::endl;
		}
		else if (part2(report) == 1){
			safe_2++;
			std::cout << "Safe" << std::endl;
		}
		else {
			std::cout << "Unsafe" << std::endl;
		}
	}

	fin.close();

	std::cout << safe << " " << safe_2;
	

}
