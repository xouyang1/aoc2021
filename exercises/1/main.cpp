#include <iostream>
#include <filesystem>
#include <vector>
#include <file_text.h>

int CountIncreases(const std::vector<int>& v)
{
    int prev;
    int count = -1; 

    for (auto i : v)
    {
        count += (i > prev);
        prev = i;
    }
    return count;
}

int CountSlidingWindowIncreases(const std::vector<int>& v, int window_size)
{
    int count = 0;
    for (auto it = v.begin(); it != v.end()-window_size; ++it)
    {
        int head = *it;
        int tail = *(it + window_size);
        count += (tail > head);
    }   
    return count;
}

int main()
{
    const std::string& input_test_filename = std::filesystem::absolute(__FILE__).replace_filename("input_test.txt").string();
    const std::string& input_filename = std::filesystem::absolute(__FILE__).replace_filename("input.txt").string();
    const FileText<int> text_test{input_test_filename};
    const FileText<int> text{input_filename};

    // Part 1 - test run expecting 7
    std::cout << "part 1 test: # of increases in depth = " << CountIncreases( text_test.items() ) << std::endl;
    std::cout << "part 1: # of increases in depth = " << CountIncreases( text.items() ) << std::endl;

    // Part 2 - test run expecting 5
    std::cout << "part 2 test: # of increases in depth = " << CountSlidingWindowIncreases( text_test.items(), 3 ) << std::endl;
    std::cout << "part 2: # of increases in depth = " << CountSlidingWindowIncreases( text.items(), 3 ) << std::endl;
}