// #include <iostream>
// #include <filesystem>
// #include <vector>
// #include <file_text.h>

// std::vector<int> GetCountsByPosition(const std::vector<std::string>& inputs)
// {
//     const int size = inputs.at(0).length();
//     std::vector<int> counts(size);
//     int digit = 0;
//     for (auto input : inputs)
//     {
//         for (auto i=0; i<input.length(); ++i)
//         {
//             digit = input.at(i) - '0';
//             if (digit == 0 || digit ==1)
//                 counts[i] += digit; 
//             else
//                 throw std::logic_error("input bit is not valid (not 0 or 1)");
//         }
//     }
//     return counts; 
// }

// int IdentifyMostCommonBitsByPosition(const std::vector<int>& counts, int total_count)
// {
//     int most_common_bits_in_decimal = 0;
//     int mask = 0;

//     for (auto i=0; i < counts.size(); ++i)
//     {
//         mask = 1 << (counts.size()-1-i);
//         if (counts[i]*2 >= total_count)
//             most_common_bits_in_decimal |= mask;
//     }
//     return most_common_bits_in_decimal;
// }

// int IdentifyLeastCommonBitsByPosition(int most_common_bits_in_decimal, int num_positions)
// {
//     return pow(2, num_positions) - 1 - most_common_bits_in_decimal;
// }

// int CalculatePowerConsumption(const std::vector<std::string>& inputs)
// {
//     std::vector<int> counts(GetCountsByPosition(inputs));
//     int gamma = IdentifyMostCommonBitsByPosition(counts, inputs.size());
//     int epsilon = IdentifyLeastCommonBitsByPosition(gamma, counts.size());
//     return gamma * epsilon;
// }

// int main()
// {
//     const std::string& input_test_filename = std::filesystem::absolute(__FILE__).replace_filename("input_test.txt").string();
//     const std::string& input_filename = std::filesystem::absolute(__FILE__).replace_filename("input.txt").string();
//     const FileText<std::string> text_test(input_test_filename);
//     const FileText<std::string> text(input_filename);

//     // Part 1 - test run expecting 198 power consumption (22 gamma rate x 9 epsilon rate)
//     int power_test = CalculatePowerConsumption(text_test.items());
//     std::cout << "part 1 test: " << power_test << std::endl;     
//     int power = CalculatePowerConsumption(text.items());
//     std::cout << "part 1: " << power << std::endl; 
// }