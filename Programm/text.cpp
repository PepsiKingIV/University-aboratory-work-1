#include "text.h"

void show_histogram_text(const std::vector<size_t> &bins, const std::vector<double> &numbers)
{

    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 8;
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
        std::cout << bin << "|";

        for (size_t j = 0; j < height; j++)
        {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}
