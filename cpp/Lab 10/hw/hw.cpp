#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

const int ROWS = 15;
const int COLUMNS = 15;

void initialize_maze(vector<vector<char>>& maze) {
   for(int i = 0; i < ROWS; i++) {
        int random = (rand() % 13) + 1;
        for (int j = 0; j < COLUMNS; j++) {
            if (j == 0 || j == COLUMNS - 1) {
                maze[i][j] = '#';
            } else if (i % 2 == 0 && j == random) {
                maze[i][j] = '.';
                if(i - 1 > 0) {
                    maze[i - 1][j] = '.';
                }
            } else if (i % 2 != 0 && maze[i - 1][j] == '.') {
                maze[i][j] = '.';
            } else {
                maze[i][j] = '#';
            }
        }
    }
}

void gen_path(vector<vector<char>>& maze) {
    int x = 1;
    int y = 1;
    while (x < COLUMNS - 2 || y < ROWS - 2) {
        bool moveRight = (rand() % 2 == 0) && (x < COLUMNS - 2);
        bool moveDown = !moveRight && (y < ROWS - 2);

        if (moveRight) {
            x++;
        } else if (moveDown) {
            y++;
        } else {
            if (y < ROWS - 2) {
                y++;
            } else if (x < COLUMNS - 2) {
                x++;
            }
        }

        maze[y][x] = '.'; 
    }
}

void add_random_walls(vector<vector<char>>& maze) {
    for (int y = 1; y < ROWS - 1; y++) {
        for (int x = 1; x < COLUMNS - 1; x++) {
            if (maze[y][x] != '.') {
                maze[y][x] = (rand() % 3) ? '#' : ' '; 
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    vector<vector<char>> maze(ROWS, vector<char>(COLUMNS));

    initialize_maze(maze);
    gen_path(maze);
    add_random_walls(maze);

    for (const auto& row : maze) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }

    return 0;
}
