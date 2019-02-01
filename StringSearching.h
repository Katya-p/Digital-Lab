#ifndef STRSEARCH
#define STRSEARCH
#include <vector>
#include <string>
#include <algorithm>

//Boyer–Moore string-search algorithm with heuristics of matched suffix
//the calculation of the table of suffixes
std::vector<int> get_suffshift(const std::string & pattern);

//get indexes of the first
void get_indexes_of_matches(std::string str, const std::string & pattern, std::vector<size_t> & indexes);

#endif