#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_COLS = 50;

bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

bool solve_maze(char maze[][MAX_COLS], int rows, int cols, int x, int y, vector<pair<int,int>>& path) {
    if (!isValid(x, y, rows, cols)) return false;
    if (maze[x][y] == '#' || maze[x][y] == '*') return false;
    if (maze[x][y] == 'E') {
        path.push_back({x, y});
        return true;
    }

    char original = maze[x][y];
    if (maze[x][y] != 'S') maze[x][y] = '*';

    path.push_back({x, y});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        if (solve_maze(maze, rows, cols, x + dx[i], y + dy[i], path)) {
            return true;
        }
    }

    path.pop_back();
    if (original != 'S') maze[x][y] = '.';

    return false;
}

int main() {
    int rows, cols;
    cout << "Enter maze dimensions (rows cols): ";
    cin >> rows >> cols;

    char maze[50][MAX_COLS];
    int startX = -1, startY = -1;
    int exitCount = 0, startCount = 0;

    string rowInput;

    for (int i = 0; i < rows; i++) {
        cout << "Row " << i+1 << ": ";
        cin >> rowInput;

        for (int j = 0; j < cols; j++) {
            maze[i][j] = rowInput[j];

            if (maze[i][j] == 'S') {
                startX = i;
                startY = j;
                startCount++;
            }
            if (maze[i][j] == 'E') {
                exitCount++;
            }
        }
    }

    if (startCount != 1 || exitCount != 1) {
        cout << "Invalid maze: must contain exactly one S and one E.\n";
        return 0;
    }

    vector<pair<int,int>> path;

    cout << "\nSolving maze...\n\n";

    if (solve_maze(maze, rows, cols, startX, startY, path)) {
        cout << "Solution found!\n";
        cout << "Path length: " << path.size() << endl << endl;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << maze[i][j];
            }
            cout << endl;
        }

        cout << "\nPath coordinates:\n";
        for (int i = 0; i < path.size(); i++) {
            cout << "(" << path[i].first << "," << path[i].second << ")";
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "No solution exists.\n\n";
        cout << "Explored maze:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << maze[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
