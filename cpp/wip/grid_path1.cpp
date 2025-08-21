#include <bits/stdc++.h>
#define size(x) ((int)x.size())

using namespace std;
using ll = long long;

int generate(vector<vector<int>>& path, int x, int y, int counter=1) {
    int n = size(path);
    if (x == n-1 && y == n-1) {
        if (counter == n*n) return 1;
        else return 0;
    }
    // up, down, left, right
    const vector<int> moveX {0, 0, -1, 1};
    const vector<int> moveY {1, -1, 0, 0};

    int count = 0;
    for (int i = 0; i < 4; i++) {
        int nx = moveX[i] + x;
        int ny = moveY[i] + y;
        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;
        if (path[nx][ny] == 0) {
            // forward again
            int fx = nx + moveX[i];
            int fy = ny + moveY[i];
            // if forward is blocked
            if (fx < 0 || fy < 0 || fx >= n || fy >= n || path[fx][fy] == 1) {
                int numSpaces = 0;
                for (int sign = -1; sign <= 1; sign += 2) {
                    // perpendicular
                    int px = nx + moveX[(i+2) % 4] * sign;
                    int py = ny + moveY[(i+2) % 4] * sign;
                    if (px < 0 || py < 0 || px >= n || py >= n)
                        continue;
                    if (path[px][py] == 0)
                        numSpaces++;
                }
                if (numSpaces == 2) {
                    // for (int r = 0; r < n; r++) {
                    //     for (int c = 0; c < n; c++)
                    //         cout << path[r][c] << " ";
                    //     cout << "\n";
                    // }
                    // cout << "(" << nx << ", " << ny << ")\n\n";
                    continue;
                }
            }

            // recursion
            path[nx][ny] = 1;
            count += generate(path, nx, ny, counter+1);
            path[nx][ny] = 0;
        }

        // prune first move
        if (counter == 1) break;
    }
    return count;
}
int numPaths(int n) {
    vector<vector<int>> paths (n, vector<int> (n));
    paths[0][0] = 1;
    return 2*generate(paths, 0, 0);
}

int main() {
    cout << numPaths(7) << endl;
}
