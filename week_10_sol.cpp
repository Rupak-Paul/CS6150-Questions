#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    char gridMap[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> gridMap[i][j];
        }
    }

    pair<int, int> currentLocation;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(gridMap[i][j] == 'X') {
                currentLocation = {i, j};
                break;
            }
        }
    }

    vector<vector<int>> minDistanceFromX(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    
    minDistanceFromX[currentLocation.first][currentLocation.second] = 0;
    visited[currentLocation.first][currentLocation.second] = true;
    q.push(currentLocation);

    while(!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        pair<int, int> adj[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for(pair<int, int> v : adj) {
            v.first += u.first;
            v.second += u.second;
            
            if(v.first < 0 || v.first >= n || v.second < 0 || v.second >= m) continue; 
            if(visited[v.first][v.second] == true) continue;
            if(gridMap[v.first][v.second] == '#') continue;
            
            minDistanceFromX[v.first][v.second] = minDistanceFromX[u.first][u.second] + 1;
            visited[v.first][v.second] = true;
            if(gridMap[v.first][v.second] == '.') q.push(v);
        }
    }

    int distNearestHospital = INT_MAX;
    pair<int, int> locNearestHospital = {-1, -1};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(gridMap[i][j] == 'H' && minDistanceFromX[i][j] < distNearestHospital) {
                distNearestHospital = minDistanceFromX[i][j];
                locNearestHospital = {i, j};
            }
        }
    }

    if(distNearestHospital == INT_MAX) cout << "-1" << endl;
    else {
        cout << 5*distNearestHospital << endl;
        cout << "(" << locNearestHospital.first << "," << locNearestHospital.second << ")" << endl;
    }
}