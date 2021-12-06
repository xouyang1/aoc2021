https://adventofcode.com/2021/day/3

Puzzle input: Diagnostic report of a list of binary numbers. 

1. Output: Power Consumption = gamma rate * epsilon rate. Answer in decimal. <br>
gamma rate := each bit is the most common bit in the corresponding position. <br>
epsilon rate := each bit is the least common bit in the corresponding position.

2. Output: Life Support Rating = oxygen generator rating * CO2 scrubber rating. <br>
  * oxygen generator rating: filter by moving left to right and removing all numbers without the most common value in that bit position for the remaining list (if 0 and 1 are equally common, keep 1) <br>
  * CO2 scrubber rating: least common (if 0 and 1 are equally common in a position, keep 0)
