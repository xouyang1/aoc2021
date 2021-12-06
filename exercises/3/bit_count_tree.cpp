#include "bit_count_tree.h"

#include <algorithm>
#include <stdexcept>

BitCountTree::BitCountTree(const std::vector<std::string>& inputs) : root(nullptr)
{
    if (!inputs.empty())
        root = std::make_shared<BitCountNode>();
    std::shared_ptr<BitCountNode> current;

    for (const std::string& input : inputs)
    {
        current = root;
        std::for_each(
            input.cbegin(), input.cend(), 
            [&current](char bit){ current = current->ProcessBit(bit); });
    }
}

std::string BitCountTree::SelectBitsByPosition(std::function<bool(int, int)> comp)
{
    std::string bit_sequence{""};
    std::shared_ptr<BitCountNode> current = root;
    while (current)
    {
        bit_sequence.push_back(current->GetBit());

        if (!current->zero_bit)
            current = current->one_bit;
        else if (!current->one_bit)
            current = current->zero_bit;
        else
        {
            if (comp(current->zero_bit->GetCount(), current->one_bit->GetCount()))
                current = current->zero_bit;
            else
                current = current->one_bit;
        }
    }
    return bit_sequence;
}

std::shared_ptr<BitCountNode> BitCountNode::ProcessBit(char bit)
{
    if (bit == '1')
    {
        if (!one_bit)
            one_bit = std::make_unique<BitCountNode>('1');
        one_bit->IncrementCount();
        return one_bit;
    }
    else if (bit == '0')
    {
        if (!zero_bit)
            zero_bit = std::make_unique<BitCountNode>('0');
        zero_bit->IncrementCount();
        return zero_bit;
    }
    else
        throw std::invalid_argument("Invalid bit cannot be processed.");
}