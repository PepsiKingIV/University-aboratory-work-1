#include <iostream>
#include <vector>

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

void find_minmax(const std::vector<double> &numbers, double &min, double &max)
{
    min = numbers[0];
    max = numbers[0];
    for (double x : numbers)
    {
        if (x < min)
        {
            min = x;
        }
        else if (x > max)
        {
            max = x;
        }
    }
}

std::vector<size_t> make_histogram(const std::vector<double> &numbers, const size_t &bin_count)
{
    double min, max;
    find_minmax(numbers, min, max);

    std::vector<size_t> bins(bin_count);
    double bin_size = (max - min) / bin_count;

    for (size_t i = 0; i < numbers.size(); i++)
    {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] <= hi))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[bin_count - 1]++;
        }
    }
    return bins;
}

void show_histogram_text(const std::vector<size_t> &bins, const std::vector<double> &numbers)
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 5;
    size_t max_count = 0;
    for (auto bin : bins)
    {
        if (bin > max_count)
            max_count = bin;
    }

    for (auto bin : bins)
    {
        size_t height;
        if (max_count <= 76)
        {
            height = bin;
        }
        else
        {
            height = MAX_ASTERISK * (static_cast<double>(bin) / max_count);
        }

        int fraction = bin * 100 / numbers.size();

        if (fraction < 100)
            std::cout << ' ';
        if (fraction < 10)
            std::cout << ' ';
        std::cout << fraction << "|";

        for (size_t j = 0; j < height; j++)
        {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

int main()
{
    Input in = input_data();
    auto bins = make_histogram(in.numbers, in.bin_count);
    show_histogram_text(bins, in.numbers);
    return 0;
}