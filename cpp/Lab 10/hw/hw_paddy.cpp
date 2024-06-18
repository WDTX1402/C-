#include <iostream>
#include <ctime>
#include <cstdlib>
#include <array>
#include <vector>
using namespace std;

const size_t ROWS = 15;
const size_t COLUMNS = 15;

int main() {
    srand(time(nullptr));
    array<array<char, COLUMNS>, ROWS> maze{};

    // Initialize maze with walls
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (i == 0 || i == ROWS - 1) {
                maze[i][j] = '#'; 
            } else if (j == 0 || j == COLUMNS - 1) {
                maze[i][j] = '#'; 
            } else {
                maze[i][j] = ' '; 
            }
        }
    }

    int entryColumn = rand() % (COLUMNS - 2) + 1;
    int exitColumn = rand() % (COLUMNS - 2) + 1;
    maze[0][entryColumn] = '.';
    maze[ROWS - 1][exitColumn] = '.';

    for (int i = 1; i < ROWS - 1; ++i) {
        for (int j = 1; j < COLUMNS - 1; ++j) {
            if (maze[i][j] != '.') {
                maze[i][j] = (rand() % 3) ? '#' : ' '; 
            }
        }
    }


    

//     int first_dot_index;
//     int last_dot_index;
//    for(int i = 1; i < ROWS; i += 2) {
//         for(int j = 0; j < COLUMNS; j++) {
//             if(maze[i][j] == '.') {
//                 first_dot_index = j;
//                 break;
//             }
//         }
//         for(int k = COLUMNS; k > 0; k--) {
//             if(maze[i][k] == '.') {
//                 last_dot_index = k;
//                 break;
//             }
//         }
//         // Connect the dot between first and last dot
//         for(int l = first_dot_index + 1; l < last_dot_index; l++) {
//             maze[i][l] = '.';
//         }
//     } // // Generate random pathways
//     for (int i = 1; i < ROWS - 1; i++) {
//         for (int j = 1; j < COLUMNS - 1; j++) {
//             if ((i % 2 == 0) && (rand() % 2 == 0)) {
//                 maze[i][j] = '.';
//             }
//         }
//     }

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

   

    // Connect pathways vertically
    for (int j = 1; j < COLUMNS - 1; j++) {
        vector<int> dots;
        for (int i = 1; i < ROWS - 1; i++) {
            if (maze[i][j] == '.') {
                dots.push_back(i);
            }
        }
        for (size_t k = 1; k < dots.size(); k++) {
            int gap = dots[k] - dots[k - 1];
            if (gap > 1) {
                for (int m = dots[k - 1] + 1; m < dots[k]; m++) {
                    maze[m][j] = '.';
                }
            }
        }
    }

    //Add random spaces
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLUMNS - 1; j++) {
            if (maze[i + 1][j] != '.' && maze[i - 1][j] != '.' && rand() % 2 == 0 && maze[i][j] != '.') {
                maze[i][j] = ' ';
            }
        }
    }

    

    // Display the maze
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }

    return 0;
}