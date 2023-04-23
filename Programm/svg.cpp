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

void show_histogram_svg(const std::vector<size_t> &bins)
{
    svg_begin(400, 300);
    svg_text(20, 20, std::to_string(bins[0]));
    svg_end();
}