# Chennai City Hospital Recommendation Application

As a resident of Chennai, you are part of a project to develop a hospital recommendation application for the city. The app is designed to assist residents in quickly finding the nearest hospital during medical emergencies. Due to ongoing infrastructure projects, road repairs, and other obstacles, some paths are blocked, making it important to navigate efficiently.

The city is represented as an `n x m` grid, where each cell represents a specific area. Some areas are accessible (represented by `.`), while others are blocked (represented by `#`). Multiple hospitals are spread throughout the city, and they are all marked as `H` in the grid. Your current location can be fetched via GPS and is represented as `X` in the grid.

You can move between accessible areas, and going from one location to an adjacent location takes approximately **2 minutes**. Your task is to help the developers by writing an algorithm that determines the nearest hospital from your current location `X`, and calculates the minimum time required to reach it. 

If it is possible to reach one or more hospitals, the algorithm should output the location of the nearest hospital as an `(X, Y)` coordinate and the minimum time taken to reach it. If multiple hospitals are equidistant, the hospital that appears first in the grid (top to bottom, left to right) should be prioritized. If no hospital can be reached, return `-1`.

## Input Format

- The first line contains two integers `n` and `m`, representing the number of rows and columns in the grid.

- The next `n` lines each contain `m` characters separated by spaces, representing the grid layout. Each character in the grid can be one of the following:
  - `.`: an accessible area.

   - `#`: a blocked area.

  - `H`: a hospital.

  - `X`: your current location, fetched via GPS.

## Output Format

- If it is possible to reach one or more hospitals, print the coordinates of the nearest hospital as `(X, Y)` followed by the minimum time (in minutes) to reach it, as space-separated values.

- If no hospital is reachable, print `-1`.

## Constraints
- 2 ≤ n, m ≤ 1000

- The number of hospitals `H` must be `<= 10`.

## Example

### Input
```
5 5
. . . . .
. . # . .
. H # . .
. . X . .
. H . . .
```

### Output
```
(4, 1) 6
```

### Explanation
In this example, the nearest hospital is located at position `(4, 1)`. It takes 6 minutes to reach this hospital from your current location, `X`, at position `(3, 3)`. Therefore, the algorithm outputs `(4, 1) 6.
