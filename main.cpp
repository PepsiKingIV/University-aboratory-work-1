#include <iostream>
#include <vector>
#include "histogram.h"
#include "text.h"

struct Input
{
    std::vector<double> numbers;
    size_t bin_count;
};

Input input_data()
{
    size_t number_count;
    std::cerr << "Enter number count: ";
    std::cin >> number_count;
    Input in;
    in.numbers.resize(number_count);

    for (size_t i = 0; i < number_count; i++)
    {
        std::cin >> in.numbers[i];
    }

    std::cerr << "Enter bin count: ";
    std::cin >> in.bin_count;
    return in;
}


int main()
{
    Input in = input_data();
    auto bins = make_histogram(in.numbers, in.bin_count);
    show_histogram_text(bins, in.numbers);
    return 0;
}