# Hospital Recommendation App
As a student of IIT Madras, you are part of a project to develop a hospital recommendation application for Chennai. The app is designed to assist residents in quickly finding the nearest hospital during medical emergencies. Due to ongoing infrastructure projects, road repairs, and other obstacles, some paths are blocked, making it important to navigate efficiently.

The city is represented as a grid comprising $n$ rows and $m$ columns, where each cell represents a specific area. Rows are indexed by $i$, $0 \le i <n$, and columns are indexed by $j$, $0 \le j < m$; thus the top-left cell is $(0,0)$. Some areas are accessible (represented by `.`), while others are blocked (represented by `#`). Multiple hospitals are spread throughout the city, and they are all marked as `H` in the grid. Your current location can be fetched via GPS and is represented as `X` in the grid.

Note that a cell can have up to 8 adjacent cells. You can move between any adjacent accessible areas, and going from one location to an adjacent location takes **5 minutes**. Your task is to help the developers by writing an algorithm that determines the nearest hospital from your current location `X` and calculates the minimum time required to reach it.

If it is possible to reach one or more hospitals, the algorithm should output the minimum time required to reach the hospital and the location of the nearest hospital by its indices in the form $(i,j)$. If multiple hospitals are equidistant, break ties in favour of the smallest row value and then in favour of the smallest column value; see sample testcases for clarity. If no hospital can be reached, return `-1`.

## Input Format
- The first line contains two integers `n` and `m`, representing the number of rows and columns in the grid.

- The next `n` lines each contain `m` characters separated by spaces, representing the grid layout. Each character in the grid can be one of the following:
  - `.`: an accessible area.
  - `#`: a blocked area.
  - `H`: a hospital.
  - `X`: your current location, fetched via GPS.

## Output Format
- If it is possible to reach one or more hospitals:
	- The first line should contain the minimum time (in minutes) required to reach the nearest hospital.

  - The second line should contain the indices of the nearest hospital as $(i,j)$. Break ties as explained earlier.

- If no hospital is reachable, print `-1`.

## Constraints
- 2 ≤ n, m ≤ 1000

## Sample Inputs and Outputs

### Sample Input 1
```
5 5
. . . . .
. . # . .
. H # . .
. . X . .
. H . . .
```
### Sample Output 1
```
5
(2,1)
```

### Explanation 1
In this test case, the user starts at location `(3,2)`, marked as `X` in the grid. The nearest hospital is located at `(2,1)`, marked as `H`, which can be reached in just 5 minutes, `(3,2) -> (2,1)`. There is another hospital at `(4,1)` that is also accessible and equidistant; however, the algorithm prioritizes the hospital that appears first in the grid from top to bottom and left to right. Hence, the output indicates a minimum time of **5 minutes** to reach the nearest hospital at coordinates `(2,1)`.

![image]()

### Sample Input 2
```
5 5
. . . . .
# # # . .
. H # . .
# # # . .
. . . . X
```

### Sample Output 2
```
-1
```

### Explanation 2
In this test case, the user starts at location `(4,4)`, marked as `X` in the grid. The nearest hospital is located at `(2,1)`, marked as `H`. However, there are blocked paths represented by `#` that prevent any movement towards the hospital, making it impossible for the user to reach it. Since no hospital can be accessed from the starting position, the output is `-1`, indicating that the user cannot reach any hospital during the emergency.

### Sample Input 3
```
10 10
. . . . . . . . . .
# # # . # . . . H .
. H # . # H . . . .
# # # . # # # # . .
. . . . . . . . . .
. . . # # # # # . .
# # # . # . . . . .
. X # . # . . # # #
. . # . . . . # H .
. . . . . . . # # #
```

### Sample Output 3
```
60
(1,8)
```

### Explanation 3
In this example, the user starts at location `(7,1)` and the nearest hospital is at `(1,8)`, which can be reached in 60 minutes. The user follows the path `(7,1) → (8,1) → (9,2) → (8,3) → (8,4) → (7,5) → (6,6) → (6,7) → (5,8) → (4,7) → (3,8) → (2,7) → (1,8)`. Each move between adjacent accessible cells takes 5 minutes, and since there are 12 moves, the total time is 60 minutes.

![image]()
