#include "StringSearching.h"
std::vector<int> get_suffshift(const std::string & pattern) {
	int m = pattern.size();
	std::vector<int> suffshift(m + 1, m);
	std::vector<int> z(m, 0);
	for (int j = 1, maxZidx = 0, maxZ = 0; j < m; ++j) {
		if (j <= maxZ) {
			z.at(j) = std::min(maxZ - j + 1, z.at(j - maxZidx));
		}
		while (j + z.at(j) < m && pattern[m - 1 - z.at(j)] == pattern[m - 1 - (j + z.at(j))]) {
			z.at(j)++;
		}
		if (j + z.at(j) - 1 > maxZ) {
			maxZidx = j;
			maxZ = j + z.at(j) - 1;
		}
	}
	for (int j = m - 1; j > 0; j--) {
		suffshift.at(m - z.at(j)) = j;
	}
	for (int j = 1, r = 0; j <= m - 1; j++) {
		if (j + z.at(j) == m) {
			for (; r <= j; r++) {
				if (suffshift.at(r) == m) {
					suffshift.at(r) = j;
				}
			}
		}
	}
	return suffshift;
}

void get_indexes_of_matches(std::string str, const std::string & pattern, std::vector<size_t> & indexes) {
	std::vector<int> suffshift = get_suffshift(pattern);
	size_t m = pattern.size();
	size_t n = str.size();
	int j, bound = 0; //either bound = 0 or bound = m - suffshift[0]
	for (size_t i = 0; i <= n - m; i += suffshift[j + 1]) {
		for (j = m - 1; j >= bound && pattern[j] == str[i + j]; j--);
		if (j < bound) {
			indexes.push_back(i);
			bound = m - suffshift[0];
			j = -1;//set j as if we read the whole pattern s, not just to the border bound
		}
		else {
			bound = 0;
		}
	}
}
