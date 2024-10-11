# Hospital Recommendation Application

As a student at IIT Madras, you are part of a project to develop a hospital recommendation application for the campus. The app is designed to assist students, faculty, and staff in quickly finding the nearest hospital during medical emergencies. Due to ongoing infrastructure repairs, construction, and landscaping projects, some pathways on campus are blocked, making it important to navigate efficiently.

The campus is represented as an `n x m` grid, where each cell represents a specific area. Some areas are accessible (represented by `.`), while others are blocked due to construction or safety reasons (represented by `#`). There are two hospitals on campus, marked as `H1` and `H2` in the grid. Your current location on campus can be fetched using GPS and represented as `X` in the grid.

You can move between accessible areas, Going from one location to an adjacent location takes approximately **2 minutes**. Your task is to help the developers by writing an algorithm that determines which hospital, `H1` or `H2`, is closer from your current location `X`, and calculates the minimum time required to reach it.

If it is possible to reach one or both hospitals, the algorithm should output the name of the closest hospital (`H1` or `H2`) and the minimum time taken to reach it. If both hospitals are equidistant, prioritize `H1`. If neither hospital can be reached, return `-1`.

## Input Format

- The first line contains two integers `n` and `m`, representing the number of rows and columns in the grid.

- The next `n` lines each contain `m` strings separated by spaces, representing the grid layout. Each strings in the grid can be one of the following:
  - `.`: an accessible area.

  - `#`: a blocked area.

  - `H1`: the location of the first hospital.

  - `H2`: the location of the second hospital.

  - `X`: your current location, fetched via GPS.

## Output Format

- If it is possible to reach one or both hospitals, print the name of the nearest hospital (`H1` or `H2`) followed by the minimum time (in minutes) to reach it, as two space-separated values.

- If both hospitals are unreachable, print `-1`.

## Constraints
- 1 ≤ n, m ≤ 1000

## Example

### Input
```
5 5
. . . . .
. . # . .
. H1 # . .
. . X . .
. H2 . . .
```

### Output
```
H2 6
```

### Explanation
In this example, the nearest hospital is `H2`, located at position (4, 1). It takes 6 minutes to reach `H2` from your current location, `X`, at position (3, 3). Therefore, the algorithm outputs `H2 6`.
