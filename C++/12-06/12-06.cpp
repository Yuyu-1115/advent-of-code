#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>



char turnRight(char dir){
	if (dir == '^'){
		return '>';
	}
	else if (dir == '>') {
		return 'v';
	}
	else if (dir == 'v') {
		return '<';
	}
	else {
		return '^';
	}
}

bool checkPos(std::vector<std::vector<char>> map, std::pair<int, int> pos){
	return map[pos.first][pos.second] == '#';
}

bool checkLoop(char dir, char ori){
	return dir == ori;
}

int patrol(int x, int y, int xlim, int ylim, std::vector<std::vector<char>> map, std::vector<std::vector<char>> table){
	char dir = '^';
	int ans = 0;

	while (x >= 0 && y >= 0 && x < xlim && y < ylim){
		char &prev = map[x][y];

		if (dir == '^'){
			x--;
			if (x >= 0 && checkPos(map, {x, y})){
				x++;
				dir = turnRight(dir);
				if (checkLoop(dir, table[x][y])){
					return -1;
				}
				else {
					table[x][y] = dir;
				}
			}
			else {
				if (prev != 'X'){
					prev = 'X';
					ans++;
				}
			}
		}
		else if (dir == '>'){
			y++;
			if (y < ylim && checkPos(map, {x, y})){
				y--;
				dir = turnRight(dir);
				if (checkLoop(dir, table[x][y])){
					return -1;
				}
				else {
					table[x][y] = dir;
				}
			}
			else {
				if (prev != 'X'){
					prev = 'X';
					ans++;
				}
			}
		}
		else if (dir == 'v'){
			x++;
			if (x < xlim &&checkPos(map, {x, y})){
				x--;
				dir = turnRight(dir);
				if (checkLoop(dir, table[x][y])){
					return -1;
				}
				else {
					table[x][y] = dir;
				}
			}
			else {
				if (prev != 'X'){
					prev = 'X';
					ans++;
				}
			}
		}
		else {
			y--;
			if (y >= 0 && checkPos(map, {x, y})){
				y++;
				dir = turnRight(dir);
				if (checkLoop(dir, table[x][y])){
					return -1;
				}
				else {
					table[x][y] = dir;
				}
			}
			else {
				if (prev != 'X'){
					prev = 'X';
					ans++;
				}
			}
		}
		
	}
	return ans;
}


int main(){
	std::ifstream fin;
	std::vector<std::vector<char>> map, table, copy, walked;
	std::string dummy;
	int x, y;
	int init_x, init_y;
	int ylim, xlim;
	int ans_1 = 0;
	int ans_2 = 0;
	char dir = '^';

	fin.open("12-06.in");

	// deal with file input
	int i = 0, j = 0;
	while (std::getline(fin, dummy)){
		j = 0;
		map.push_back(std::vector<char>());
		for (auto ptr = dummy.begin(); ptr < dummy.end(); ptr++){
			if (*ptr == '\n') { break; }
			map.rbegin()->push_back(*ptr);
			if (*ptr == '^'){
				init_x = i;
				init_y = j;
			}
			j++;
		}
		i++;
	}
	ylim = map[0].size();
	xlim = map.size();

	
	walked = map;
	table = std::vector<std::vector<char>>(xlim, std::vector<char>(ylim, '0'));
	ans_1 = patrol(init_x, init_y, xlim, ylim, walked, table);
	std::cout << "Part 1: " << ans_1 << std::endl;

	for (int i = 0; i < xlim; i++){
		for (int j = 0; j < ylim; j++){
			table = std::vector<std::vector<char>>(xlim, std::vector<char>(ylim, '0'));
			copy = map;
			copy[i][j] = '#';
			if (patrol(init_x, init_y, xlim, ylim, copy, table) == -1){
				ans_2++;
			}
		}
	}
	

	fin.close();

	std::cout << "Part 2: " << ans_2 << std::endl;

	return 0;
}
