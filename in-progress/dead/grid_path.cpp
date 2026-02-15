#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int generate(vector<vector<bool>>& path, string& description, int x, int y, int counter) {
    int n = (int) path.size();
    auto inBounds = [&](int a, int b) {return a >= 0 && b >= 0 && a < n && b < n;};
    if (x == n-1 && y == 0) {
        if (counter == n*n) return 1;
        else return 0;
    }
    // right, left, down, up
    const vector<int> moveX {0, 0, -1, 1};
    const vector<int> moveY {1, -1, 0, 0};
    const vector<char> letter = {'R', 'L', 'U', 'D'};

    int count = 0;
    for (int i = 0; i < 4; i++) {
        // if doesn't match description
        if (description[counter-1] != '?' && description[counter-1] != letter[i]) {
            // cout << description[counter-1] << " " << letter[i] << endl;
            continue;
        }

        int nx = moveX[i] + x;
        int ny = moveY[i] + y;
        if (!inBounds(nx, ny)) continue;
        if (path[nx][ny] == 1) continue;
        
        // forward again
        int fx = nx + moveX[i];
        int fy = ny + moveY[i];
        // if forward is blocked
        if (!inBounds(fx, fy) || path[fx][fy] == 1) {
            int numSpaces = 0;
            for (int sign = -1; sign <= 1; sign += 2) {
                // perpendicular
                int px = nx + moveX[(i+2) % 4] * sign;
                int py = ny + moveY[(i+2) % 4] * sign;
                if (!inBounds(px, py)) continue;
                if (path[px][py] == 0)
                    numSpaces++;
            }
            // prune
            if (numSpaces == 2) continue;
            /*for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++)
                    cout << path[r][c] << " ";
                cout << "\n";
            }
            cout << "(" << nx << ", " << ny << ")\n\n";*/
        }

        // backtracking
        path[nx][ny] = 1;
        count += generate(path, description, nx, ny, counter+1);
        path[nx][ny] = 0;
    }
    return count;
}
int numPaths(int n, string& description) {
    vector<vector<bool>> paths (n, vector<bool> (n));
    paths[0][0] = 1;
    return generate(paths, description, 0, 0, 1);
}

int main() {
    string s;
    cin >> s;
    cout << numPaths(7, s) << endl;
}
