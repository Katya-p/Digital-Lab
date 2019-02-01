#include "PatternSearching.h"

std::vector<std::pair<size_t, size_t> > get_location_of_the_matches(const std::vector<std::string> & matrix, size_t rows_m, size_t columns_m,
	const std::vector<std::string> & pattern, size_t rows_p, size_t columns_p) {
	std::vector<std::pair<size_t, size_t> > location_of_the_matches;
	//if pattern doesn't fit in the matrix, no matches found
	if ((rows_p > rows_m) || (columns_p > columns_m)) {
		return location_of_the_matches;
	}
	for (size_t i = 0; i != rows_m - rows_p + 1; i++) {
		std::vector<size_t> matches_in_current_line;
		//consider rows_p lines
		for (size_t k = 0; k < rows_p; k++) {
			get_indexes_of_matches(matrix.at(k + i), pattern.at(k), matches_in_current_line);
		}
		//if some index is included in matches_in_current_line rows_p times, this index corresponds the match 
		std::sort(matches_in_current_line.begin(), matches_in_current_line.end());
		size_t counter = 1;
		if (matches_in_current_line.size() != 0) {
			if (rows_p == 1) {
				for (size_t j = 0; j != matches_in_current_line.size(); j++) {
					location_of_the_matches.push_back({ i, matches_in_current_line.at(j) });
				}
			}
			else {
				for (size_t j = 0; j != matches_in_current_line.size() - 1; j++) {
					if (matches_in_current_line.at(j) == matches_in_current_line.at(j + 1)) {
						counter++;
					}
					else {
						counter = 1;
					}
					if (counter == rows_p) {
						location_of_the_matches.push_back({ i, matches_in_current_line.at(j) });
					}
				}
			}
		}
	}
	return location_of_the_matches;
}