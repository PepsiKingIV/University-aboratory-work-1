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

int main()
{
    Input in = input_data();
    std::vector<size_t> bins(in.bin_count);
    double min = in.numbers[0];
    double max = in.numbers[0];
    for (double x : in.numbers)
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

    double bin_size = (max - min) / in.bin_count;

    for (size_t i = 0; i < in.numbers.size(); i++)
    {
        bool found = false;
        for (size_t j = 0; (j < in.bin_count - 1) && !found; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= in.numbers[i]) && (in.numbers[i] < hi))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[in.bin_count - 1]++;
        }
    }

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

        int fraction = bin * 100 / in.numbers.size();

        if (fraction < 100)
            std::cout << ' ';
        if (fraction < 10)
            std::cout << ' ';
        std::cout << fraction << "%|";

        for (size_t j = 0; j < height; j++)
        {
            std::cout << '*';
        }
        std::cout << std::endl;
    }

    return 0;
}