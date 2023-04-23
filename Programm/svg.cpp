#include "svg.h"
void svg_text(double left, double baseline, std::string text);

void svg_begin(double width, double height)
{
    std::cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    std::cout << "<svg ";
    std::cout << "width='" << width << "' ";
    std::cout << "height='" << height << "' ";
    std::cout << "viewBox='0 0 " << width << " " << height << "' ";
    std::cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    std::cout << "</svg>\n";
}

void svg_text(double left, double baseline, std::string text)
{
    std::cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height, std::string stroke = "black", std::string fill = "black")
{
    std::cout << "<rect x='" << x << "' y='" << y << "' width='" << width
              << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << " '/>";
}

void show_histogram_svg(const std::vector<size_t> &bins)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;

    svg_begin(400, 300);
    double top = 0;

    size_t max_count = 0;
    for (auto bin : bins)
    {
        if (bin > max_count)
            max_count = bin;
    }
    const auto BLOCK_WIDTH = (IMAGE_WIDTH - TEXT_WIDTH * 2 - TEXT_LEFT) / max_count;
    const auto TEXT_RATIO_SHIFT = IMAGE_WIDTH - TEXT_WIDTH;
    auto summ = 0;
    for (size_t bin : bins)
    {
        summ += bin;
    }

    for (size_t bin : bins)
    {
        const double bin_width = BLOCK_WIDTH * bin;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, std::to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "blue", "#aaffaa");
        auto ratio = (bin * 100) / summ;
        if (bin == bins.back() && summ % 2 != 0)
        {
            ratio ++;
        }
        svg_text(TEXT_RATIO_SHIFT, top + TEXT_BASELINE, (std::to_string(ratio) + "%"));
        top += BIN_HEIGHT;
    }
    // svg_text(20, 20, std::to_string(bins[0]));
    // svg_rect(50, 0, bins[0] * 10, 30);
    svg_end();
}