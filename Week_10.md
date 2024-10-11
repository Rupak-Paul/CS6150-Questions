
# Choosing the Quickest Route to a Hospital at IIT Madras

You are a student at IIT Madras, studying late at night in the CSE Department when one of your classmates suddenly faints. Realizing the seriousness of the situation, you need to rush to the nearest hospital to get medical assistance. Fortunately, you have access to the **campus map**, which shows open pathways and areas blocked due to ongoing **construction, maintenance work, and landscaping projects**.

The campus is modeled as an `n x m` grid, where each cell represents a specific area. Some areas are accessible (represented by `.`), while others are blocked off (represented by `#`). These blockages result from **infrastructure repairs, ongoing building work, or restricted zones** for safety reasons. You can move between adjacent accessible locations, and **going from one location to its adjacent location takes 2 minutes**.

There are **two hospitals** on campus, and you must decide which one you can reach faster. Your task is to find the **minimum time required** to reach the **nearest hospital** from your position in the CSE building. If both hospitals are unreachable, return `-1`. Additionally, you need to provide the coordinates of the hospital that can be reached faster along with the time taken.

## Input:

- The first line contains two integers `n` and `m` — the number of rows and columns in the campus grid.

- The next `n` lines each contain a string of `m` characters, where `.` represents an open path and `#` represents a blocked path.

- The following line contains six integers: `sx`, `sy`, `hx1`, `hy1`, `hx2`, `hy2` — the coordinates of your starting position `(sx, sy)` in the CSE building and the coordinates of the two hospitals `(hx1, hy1)` and `(hx2, hy2)`.

## Output:

- Output the minimum time (in minutes) required to reach the nearest hospital. If both hospitals are unreachable, print `-1`. If one or both hospitals are reachable, print the time taken and the coordinates of the nearest hospital in the format: `time hx, hy`.

## Constraints:
- `1 ≤ n, m ≤ 1000`

- `1 ≤ sx, sy, hx1, hy1, hx2, hy2 ≤ n, m`

- The start and hospital points are guaranteed to be nonblocked areas.

## Example:

### Input:
```
6 7
.......
.#..#..
.#..#..
.......
.####..
.......
1 1 6 3 6 7
```

### Output:
```
10 6 7
```

### Explanation:
In this example, you start at (1,1) in the CSE building. There are two hospitals, one at (6,3) and another at (6,7). After calculating the time, you find that the quickest route to the hospital at (6,7) takes 10 minutes, while the other hospital would take longer. Thus, the output includes both the time taken and the coordinates of the nearest hospital.
