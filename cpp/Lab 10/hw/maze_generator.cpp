// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>

// using namespace std;

// const size_t rows = 15;
// const size_t columns = 15;

// void generateAndPrintMaze() {
//     srand(time(nullptr)); // Seed for random number generation
//     vector<vector<char>> maze(rows, vector<char>(columns, '#')); // Initialize maze with walls

//     // Starting point
//     size_t currentRow = 0;
//     size_t currentColumn = 1;
//     maze[currentRow][currentColumn] = '.';

//     // Randomly create a path to the exit
//     while (currentRow < rows - 1) {
//         vector<pair<int, int>> possibleMoves;

//         // Check if we can move right
//         if (currentColumn < columns - 2) possibleMoves.push_back({0, 1});

//         // Check if we can move down
//         if (currentRow < rows - 2) possibleMoves.push_back({1, 0});

//         // Choose a random direction to move
//         if (!possibleMoves.empty()) {
//             int moveIndex = rand() % possibleMoves.size();
//             currentRow += possibleMoves[moveIndex].first;
//             currentColumn += possibleMoves[moveIndex].second;
//             maze[currentRow][currentColumn] = '.';
//         }

//         // If stuck (at the last column), move down
//         if (currentColumn >= columns - 2 && currentRow < rows - 1) {
//             currentRow++;
//             maze[currentRow][currentColumn] = '.';
//         }
//     }

//     // Ensure exit path
//     maze[rows - 1][columns - 2] = '.';
//     maze[rows - 1][columns - 1] = '#'; // Make sure the exit is clear

//     // Print the maze
//     for (const auto &row : maze) {
//         for (char cell : row) {
//             cout << cell;
//         }
//         cout << endl;
//     }
// }

// int main() {
//     generateAndPrintMaze();
//     return 0;
// }
// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// using namespace std;

// int getRandomNumber() {
//     return rand() % 15 + 1; 
// }

// class Maze{
// public:
//     void generate_maze() {
//         for (int i = 1 ; i <= 15; i++){
//             for (int j = 1 ; j <= 15; j++){
//                 if(j == getRandomNumber()) {
//                     cout << " ";
//                 } else {
//                     cout << "#";
//                 }
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     srand(static_cast<unsigned int>(time(nullptr)));

//     Maze myMaze;
//     myMaze.generate_maze();

//     return 0;
// }


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

const int ROWS = 15;
const int COLUMNS = 15;

void initialize_maze(vector<vector<char>>& maze) {
    for (int y = 0; y < ROWS; ++y) {
        for (int x = 0; x < COLUMNS; ++x) {
            if (y == 0 || y == ROWS - 1 || x == 0 || x == COLUMNS - 1) {
                maze[y][x] = '#'; // Set borders
            } else {
                maze[y][x] = ' '; // Initialize the rest of the maze as empty
            }
        }
    }
}

void gen_path(vector<vector<char>>& maze) {
    // Start just inside the top-left corner
    int x = 1, y = 1;
    maze[y][x] = '.';

    while (x < COLUMNS - 2 || y < ROWS - 2) {
        // Decide randomly to move right or down unless at the edge
        bool moveRight = (rand() % 2 == 0) && (x < COLUMNS - 2);
        bool moveDown = !moveRight && (y < ROWS - 2);

        if (moveRight) {
            x++;
        } else if (moveDown) {
            y++;
        } else {
            // If somehow stuck, force a move
            if (y < ROWS - 2) {
                y++;
            } else if (x < COLUMNS - 2) {
                x++;
            }
        }

        maze[y][x] = '.'; // Mark the path
    }
}

void add_random_walls(vector<vector<char>>& maze) {
    for (int y = 1; y < ROWS - 1; ++y) {
        for (int x = 1; x < COLUMNS - 1; ++x) {
            // Only add walls in spaces not marked as part of the path
            if (maze[y][x] != '.') {
                maze[y][x] = (rand() % 3) ? '#' : ' '; // Adjust randomness
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

    // Print the maze
    for (const auto& row : maze) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }

    return 0;
}