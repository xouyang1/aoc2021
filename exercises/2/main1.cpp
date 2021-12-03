// #include <iostream>
// #include <filesystem>
// #include <vector>
// #include <map>
// #include <file_text.h>

// struct Movement; 

// class Location
// {
//     int d_horizontal;
//     int d_depth;

//   public:
//     Location(){}
//     Location(int h, int d): d_horizontal(h), d_depth(d) {}
//     int horizontal() const { return d_horizontal; }
//     int depth() const { return d_depth; }
//     void ApplyMovement(const Movement&);
//     int output() const { return d_horizontal * d_depth; }
//     friend std::ostream& operator<<(std::ostream& os, const Location& loc);
// };

// struct Movement
// {
//     static std::map<std::string, Location> direction_map; 
//     Location direction;
//     int size;
// };

// std::map<std::string, Location>Movement::direction_map = {
//     {"forward", Location{1, 0}},
//     {"down", Location{0, 1}},
//     {"up", Location{0, -1}},
// };

// void Location::ApplyMovement(const Movement& move)
// {
//     d_horizontal += move.direction.d_horizontal * move.size;
//     d_depth += move.direction.d_depth * move.size;
// }

// Location GetLocationAfterCourse(
//     const std::vector<Movement>& course, 
//     const Location& initial_location)
// {
//     Location current = initial_location;
//     for (auto step : course)
//         current.ApplyMovement(Movement(step));
//     return current;
// }

// std::ostream& operator<<(std::ostream& os, const Location& loc)
// {
//     os << "(" << loc.d_horizontal << ", " << loc.d_depth << ")";
//     return os;
// }

// std::vector<Movement> AddMovement(std::istream& file)
// {
//     std::string direction_str;
//     int size;
//     std::vector<Movement> movements;

//     while (file >> direction_str >> size)
//     {
//         Movement m{Movement::direction_map[direction_str], size};
//         movements.push_back(m);
//     }
//     return movements;
// }


// int main()
// {
//     const std::string& input_test_filename = std::filesystem::absolute(__FILE__).replace_filename("input_test.txt").string();
//     const std::string& input_filename = std::filesystem::absolute(__FILE__).replace_filename("input.txt").string();
//     const FileText<Movement> text_test(input_test_filename, AddMovement);
//     const FileText<Movement> text(input_filename, AddMovement);
//     const Location& initial_loc{0, 0};

//     // Part 1 - test run expecting 150 (horizontal of 15, depth of 10)
//     const Location& test_loc = GetLocationAfterCourse( text_test.items(), initial_loc );
//     const Location& loc = GetLocationAfterCourse( text.items(), initial_loc );
//     std::cout << "part 1 test: " << test_loc.output() << " from " << test_loc << std::endl; 
//     std::cout << "part 1: " << loc.output() << " from " << loc << std::endl; 
// }