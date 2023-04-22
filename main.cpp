#include <iostream>
#include <vector>

int main()
{
    size_t number_count;
    std::cerr << "Enter number count: ";
    std::cin >> number_count;
    std::vector<double> numbers(number_count);

    for (size_t i = 0; i < number_count; i++)
    {
        std::cin >> numbers[i];
    }

    size_t bin_count;
    std::cerr << "Enter bin count: ";
    std::cin >> bin_count;
    std::vector<size_t> bins(bin_count);
    double min = numbers[0];
    double max = numbers[0];
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

    double bin_size = (max - min) / bin_count;

    for (size_t i = 0; i < number_count; i++)
    {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi))
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

        int fraction = bin * 100 / number_count;
        
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