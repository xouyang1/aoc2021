https://adventofcode.com/2021/day/1

Puzzle input: each line is a measurement of sea floor depth as the sweep looks further and further away from the submarine.

1. Count the number of times a depth measurement increases from the previous measurement (first not counted).

Example: 7 measurements larger than previous.
```
199 (N/A - no previous measurement)
200 (increased)
208 (increased)
210 (increased)
200 (decreased)
207 (increased)
240 (increased)
269 (increased)
260 (decreased)
263 (increased)
```

2. 3-measurement sliding window