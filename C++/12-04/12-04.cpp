#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool checkLU(std::vector<std::vector<char>> table, int i, int j){
	if (table[i - 1][j - 1] == 'M'){
		if (table[i - 2][j - 2] == 'A'){
			return table[i - 3][j - 3] == 'S';
		}
	}
	return false;
}
bool checkU(std::vector<std::vector<char>> table, int i, int j){
	if (table[i - 1][j] == 'M'){
		if (table[i - 2][j] == 'A'){
			return table[i - 3][j] == 'S';
		}
	}
	return false;
}
bool checkRU(std::vector<std::vector<char>> table, int i, int j){
	if (table[i - 1][j + 1] == 'M'){
		if (table[i - 2][j + 2] == 'A'){
			return table[i - 3][j + 3] == 'S';
		}
	}
	return false;
}
bool checkL(std::vector<std::vector<char>> table, int i, int j){
	if (table[i][j - 1] == 'M'){
		if (table[i][j - 2] == 'A'){
			return table[i][j - 3] == 'S';
		}
	}
	return false;
}
bool checkR(std::vector<std::vector<char>> table, int i, int j){
	if (table[i][j + 1] == 'M'){
		if (table[i][j + 2] == 'A'){
			return table[i][j + 3] == 'S';
		}
	}
	return false;
}
bool checkLD(std::vector<std::vector<char>> table, int i, int j){
	if (table[i + 1][j - 1] == 'M'){
		if (table[i + 2][j - 2] == 'A'){
			return table[i + 3][j - 3] == 'S';
		}
	}
	return false;

}
bool checkD(std::vector<std::vector<char>> table, int i, int j){
	if (table[i + 1][j] == 'M'){
		if (table[i + 2][j] == 'A'){
			return table[i + 3][j] == 'S';
		}
	}
	return false;

}
bool checkRD(std::vector<std::vector<char>> table, int i, int j){
	if (table[i + 1][j + 1] == 'M'){
		if (table[i + 2][j + 2] == 'A'){
			return table[i + 3][j + 3] == 'S';
		}
	}
	return false;
}

bool check0(std::vector<std::vector<char>> table, int i, int j){
	if (table[i - 1][j - 1] == 'M' && table[i - 1][j + 1] == 'M'){
		if (table[i + 1][j - 1] == 'S' && table[i + 1][j + 1] == 'S'){
			return true;
		}
	}
	return false;
}
bool check90(std::vector<std::vector<char>> table, int i, int j){
	if (table[i - 1][j - 1] == 'M' && table[i + 1][j - 1] == 'M'){
		if (table[i - 1][j + 1] == 'S' && table[i + 1][j + 1] == 'S'){
			return true;
		}
	}
	return false;
}
bool check180(std::vector<std::vector<char>> table, int i, int j){
	if (table[i + 1][j - 1] == 'M' && table[i + 1][j + 1] == 'M'){
		if (table[i - 1][j - 1] == 'S' && table[i - 1][j + 1] == 'S'){
			return true;
		}
	}
	return false;
}
bool check270(std::vector<std::vector<char>> table, int i, int j){
	if (table[i - 1][j + 1] == 'M' && table[i + 1][j + 1] == 'M'){
		if (table[i - 1][j - 1] == 'S' && table[i + 1][j - 1] == 'S'){
			return true;
		}
	}
	return false;
}

int main(){
	std::vector<std::vector<char>> table;
	std::string dummy;
	std::ifstream fin;
	int ans_1 = 0;
	int ans_2 = 0;
	fin.open("12-04.in");
	while (std::getline(fin, dummy)){
		table.push_back(std::vector<char>());
		for (auto &letter: dummy){
			table.rbegin()->push_back(letter);
		}
	}
	fin.close();
	int m = table.size();
	int n = table[0].size();
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (table[i][j] == 'X'){
				if (i >= 3){
					if (j >= 3){
						ans_1 += checkLU(table, i, j);
					}
					if (j + 3 < n){
						ans_1 += checkRU(table, i, j);
					}
					ans_1 += checkU(table, i, j);
				}
				if (i + 3 < m){
					if (j >= 3){
						ans_1 += checkLD(table, i, j);
					}
					if (j + 3 < n){
						ans_1 += checkRD(table, i, j);
					}
					ans_1 += checkD(table, i, j);
				}
				if (j >= 3){
					ans_1 += checkL(table, i, j);
				}
				if (j + 3 < n){
					ans_1 += checkR(table, i, j);
				}
			}
			if (table[i][j] == 'A'){
				if (i >= 1 && i + 1 < m && j >= 1 && j + 1 < n){
					ans_2 += check0(table, i, j) ;
					ans_2 += check90(table, i, j); 
					ans_2 += check180(table, i, j);
					ans_2 += check270(table, i, j);
				}
			}
		}
	}

	std::cout << "Part 1: " << ans_1 << std::endl;
	std::cout << "Part 2: " << ans_2 << std::endl;

}
