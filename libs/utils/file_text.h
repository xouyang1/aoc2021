#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <fmt/format.h>

template<typename T>
class FileText
{
    std::vector<T> d_items;

  public:
    FileText(const std::string& filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
            throw std::runtime_error("Failed to open text file " + filename);
        
        T buffer;
        while (file >> buffer)
            d_items.push_back(buffer);

        file.close();
    }

    FileText(const std::string& filename, std::vector<T> (*process)(std::istream&))
    {
        std::ifstream file(filename);
        if (!file.is_open())
            throw std::runtime_error("Failed to open text file " + filename);
    
        d_items = (*process)(file);

        file.close();
    }

    size_t size() { return d_items.size(); }

    void print()
    {
        fmt::print("{}\n", fmt::join(d_items, "\n"));
    }

    const std::vector<T>& items() const
    {
        return d_items;
    }
};