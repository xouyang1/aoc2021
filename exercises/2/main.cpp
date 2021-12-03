#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <file_text.h>


class Movement; 

class Location
{
    int d_horizontal;
    int d_depth;
    int d_aim;

  public:
    Location() {}
    Location(int h, int d, int a): d_horizontal(h), d_depth(d), d_aim(a) {}
    int horizontal() const { return d_horizontal; }
    int depth() const { return d_depth; }
    int aim() const { return d_aim; }
    void UpdateMovementOffset(Movement&);
    void ApplyMovementOffset(const Movement&);
    int output() const { return d_horizontal * d_depth; }
};

using Direction = void(*)(Movement&, const Location&);

class Movement
{

    void InitializeDirectionMap();

  public:
    Location offset;
    Direction calculate_offset;
    int size;
};

class DirectionMap
{
  public:
    static void Forward(Movement& m, const Location& current) { m.offset = Location{m.size, m.size*current.aim(), 0}; }
    static void Down(Movement& m, const Location& current) { m.offset = Location{0, 0, m.size}; }
    static void Up(Movement& m, const Location& current) { m.offset = Location{0, 0, -m.size}; }
    
    const static std::map<const std::string, Direction> direction_map;
};

const std::map<const std::string, Direction> DirectionMap::direction_map = {
    {"forward", &Forward},
    {"down", &Down},
    {"up", &Up},
};

std::vector<Movement> AddMovement(std::istream& file)
{
    std::string direction_str;
    int size;
    std::vector<Movement> movements;

    while (file >> direction_str >> size)
    {
        Movement m{};
        m.calculate_offset = DirectionMap::direction_map.at(direction_str);
        m.size = size;
        movements.push_back(m);
    }
    return movements;
}

void Location::UpdateMovementOffset(Movement& move)
{
    move.calculate_offset(move, *this);
}

void Location::ApplyMovementOffset(const Movement& move)
{
    d_horizontal += move.offset.horizontal();
    d_depth += move.offset.depth();
    d_aim += move.offset.aim();
}

Location GetLocationAfterCourse(
    const std::vector<Movement>& course, 
    const Location& initial_location)
{
    Location current = initial_location;
    for (auto step : course)
    {
        current.UpdateMovementOffset(step);
        current.ApplyMovementOffset(step);
    }
    return current;
}

std::ostream& operator<<(std::ostream& os, const Location& loc)
{
    os << "(" << loc.horizontal() << ", " << loc.depth() << ")";
    return os;
}


int main()
{
    const std::string& input_test_filename = std::filesystem::absolute(__FILE__).replace_filename("input_test.txt").string();
    const std::string& input_filename = std::filesystem::absolute(__FILE__).replace_filename("input.txt").string();
    const FileText<Movement> text_test(input_test_filename, AddMovement);
    const FileText<Movement> text(input_filename, AddMovement);
    const Location& initial_loc{0, 0, 0};

    // Part 2 - test run expecting 900 (horizontal of 15, depth of 60)
    const Location& test_loc = GetLocationAfterCourse( text_test.items(), initial_loc );
    const Location& loc = GetLocationAfterCourse( text.items(), initial_loc );
    std::cout << "part 2 test: " << test_loc.output() << " from " << test_loc << std::endl; 
    std::cout << "part 2: " << loc.output() << " from " << loc << std::endl; 
}