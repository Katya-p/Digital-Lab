#ifndef RUN
#define RUN
#include "PatternSearching.h"
#include <iostream>

//read matrix
std::vector<std::string > read_matrix(size_t rows, size_t columns);

//draw matrix
void draw(const std::vector<std::string > & matrix, size_t rows_m, size_t columns_m);

//changing 1 to 2 and 0 to * to mark a located pattern 
void change_matrix(std::vector<std::string> & matrix, size_t rows_m, size_t columns_m,
	const std::vector<std::string > & pattern, size_t rows_p, size_t columns_p);

void run();

#endif