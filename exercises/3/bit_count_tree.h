#pragma once

#include <vector>
#include <string>
#include <memory>

class BitCountNode;

class BitCountTree
{
    std::shared_ptr<BitCountNode> root;

  public:
    BitCountTree(const std::vector<std::string>& inputs);
    std::string SelectBitsByPosition(std::function<bool(int, int)> comp);
};

class BitCountNode
{
    int count;
    char bit;

  public:
    std::shared_ptr<BitCountNode> zero_bit;
    std::shared_ptr<BitCountNode> one_bit;

    BitCountNode(char bit='\0') : zero_bit(nullptr), one_bit(nullptr), count(0), bit(bit) {}
    int GetCount() { return count; }
    char GetBit() { return bit; }
    void IncrementCount() { count += 1; }
    std::shared_ptr<BitCountNode> ProcessBit(char bit);
};