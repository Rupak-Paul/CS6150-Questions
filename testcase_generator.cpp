#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL));

    int n = rand() % 1001;
    int m = rand() % 1001;

    char gridMap[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            gridMap[i][j] = '.';
        }
    }

    int noOfObstracle = max(rand() % (m*n), int(m*n*0.7));
    for(int i = 0; i < noOfObstracle; i++) {
        int x = rand() % n;
        int y = rand() % m;
        gridMap[x][y] = '#';
    }

    int noOfHospital = rand() % int(m*n*0.001);
    for(int i = 0; i < noOfHospital; i++) {
        int x = rand() % n;
        int y = rand() % m;
        gridMap[x][y] = 'H';
    }

    gridMap[rand()%n][rand()%m] = 'X';

    cout << n << " " << m << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(j == m-1) cout << gridMap[i][j] << endl;
            else cout << gridMap[i][j] << " ";
        }
    }
}