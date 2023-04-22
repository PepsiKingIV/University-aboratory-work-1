#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>

std::vector<size_t> make_histogram(const std::vector<double> &numbers,const size_t& bin_count);
#endif