#ifndef PATTERNSEARCH
#define PATTERNSEARCH
#include "StringSearching.h"

//an element of this vector is the coordinates of the upper left corner of the pattern found in the matrix
std::vector<std::pair<size_t, size_t> > get_location_of_the_matches(const std::vector<std::string> & matrix, size_t rows_m, size_t columns_m,
	const std::vector<std::string> & pattern, size_t rows_p, size_t columns_p);

#endif
