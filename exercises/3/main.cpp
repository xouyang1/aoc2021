#include <iostream>
#include <filesystem>
#include <vector>
#include <limits>
#include <algorithm>

#include "bit_count_tree.h"
#include <file_text.h>

int ConvertBinaryStringToDecimal(const std::string& input)
{
    int decimal = 0; 
    for (auto i=0; i<input.length(); ++i)
    {
        if (input.at(i) == '1')
            decimal += pow(2, input.length()-1-i);
    }
    return decimal;
}

int CalculateLifeSupportRating(const std::vector<std::string>& inputs)
{
    BitCountTree tree{inputs};
    const std::string& most_common_bits = tree.SelectBitsByPosition([](int a, int b){ return a>b; });
    const std::string& least_common_bits = tree.SelectBitsByPosition([](int a, int b){ return a<=b; });
    int oxygen_generator_rating = ConvertBinaryStringToDecimal(most_common_bits);
    int co2_scrubber_rating = ConvertBinaryStringToDecimal(least_common_bits);

    std::cout << "oxygen = " << oxygen_generator_rating << std::endl;
    std::cout << "co2 = " << co2_scrubber_rating << std::endl;

    return oxygen_generator_rating * co2_scrubber_rating;
}

int main()
{
    const std::string& input_test_filename = std::filesystem::absolute(__FILE__).replace_filename("input_test.txt").string();
    const std::string& input_filename = std::filesystem::absolute(__FILE__).replace_filename("input.txt").string();
    const FileText<std::string> text_test(input_test_filename);
    const FileText<std::string> text(input_filename);

    // Part 2 - test run expecting 230 life support rating (23 oxygen generator rating x 10 CO2 scrobber rating)
    int life_support_test = CalculateLifeSupportRating(text_test.items());
    std::cout << "part 2 test: " << life_support_test << std::endl;
    int life_support = CalculateLifeSupportRating(text.items());
    std::cout << "part 2: " << life_support << std::endl; 
}