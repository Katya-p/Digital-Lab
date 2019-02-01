#include "Run.h"

//read matrix
std::vector<std::string > read_matrix(size_t rows, size_t columns) {
	std::vector<std::string >  matrix;
	for (size_t i = 0; i != rows; i++) {
		std::string str;
		char tmp;
		for (size_t j = 0; j != columns; j++) {
			std::cin >> tmp;
			str.push_back(tmp);
		}
		matrix.push_back(str);
	}
	return matrix;
}

//draw matrix
void draw(const std::vector<std::string > & matrix, size_t rows_m, size_t columns_m) {
	for (size_t i = 0; i != rows_m; i++) {

		for (size_t j = 0; j != columns_m; j++) {
			std::cout << matrix.at(i).at(j) << ' ';
		}
		std::cout << std::endl;

	}
}

//changing 1 to 2 and 0 to * to mark a located pattern 
void change_matrix(std::vector<std::string> & matrix, size_t rows_m, size_t columns_m,
	const std::vector<std::string > & pattern, size_t rows_p, size_t columns_p) {
	std::vector<std::pair<size_t, size_t> > coords = get_location_of_the_matches(matrix, rows_m, columns_m, pattern, rows_p, columns_p);
	for (auto it : coords) {
		for (size_t i = 0; i != rows_p; i++) {
			for (size_t j = 0; j != columns_p; j++) {
				if (matrix.at(i + it.first).at(j + it.second) == '1') {
					matrix.at(i + it.first).at(j + it.second) = '2';
				}
				else if (matrix.at(i + it.first).at(j + it.second) == '0') {
					matrix.at(i + it.first).at(j + it.second) = '*';
				}
			}
		}
	}
}

void run() {
	size_t rows_p, columns_p;
	std::cin >> rows_p >> columns_p;
	std::vector<std::string >  pattern = read_matrix(rows_p, columns_p);
	size_t rows_m, columns_m;
	std::cin >> rows_m >> columns_m;
	std::vector<std::string > matrix = read_matrix(rows_m, columns_m);
	change_matrix(matrix, rows_m, columns_m, pattern, rows_p, columns_p);
	draw(matrix, rows_m, columns_m);
}