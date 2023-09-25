#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 15;
vector<vector<char>> maze;
vector<vector<bool>> visited;
vector<vector<int>> distances;
pair<int, int> start, goal;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

/**
 * BFS（幅優先探索）を用いて、スタート地点からゴール地点までの最短経路を探索する関数
 * @return スタート地点からゴール地点までの最短距離。ゴールが到達不可能な場合は-1を返す。
 */
int bfs() {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    distances[start.first][start.second] = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = current.second + dx[i];
            int next_y = current.first + dy[i];

            if (next_x >= 0 && next_x < SIZE && next_y >= 0 && next_y < SIZE && maze[next_y][next_x] != '#' && !visited[next_y][next_x]) {
                visited[next_y][next_x] = true;
                distances[next_y][next_x] = distances[current.first][current.second] + 1;
                q.push({next_y, next_x});

                if (next_y == goal.first && next_x == goal.second) return distances[goal.first][goal.second];
            }
        }
    }
    return -1;  // 到達不可能
}

/**
 * メイン関数。
 * 迷路をランダムに生成し、スタート地点からゴール地点までの最短経路をBFSで探索する。
 * 最短経路が10以上の場合、迷路と最短経路を出力する。
 */
int main() {
    srand(time(0));
    while (true) {
        maze = vector<vector<char>>(SIZE, vector<char>(SIZE, '#'));
        visited = vector<vector<bool>>(SIZE, vector<bool>(SIZE, false));
        distances = vector<vector<int>>(SIZE, vector<int>(SIZE, -1));

        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                if (rand() % 2 == 0) maze[i][j] = '.';
            }
        }

        start = {rand() % (SIZE - 2) + 1, rand() % (SIZE - 2) + 1};
        goal = {rand() % (SIZE - 2) + 1, rand() % (SIZE - 2) + 1};
        while (start == goal) {
            goal = {rand() % (SIZE - 2) + 1, rand() % (SIZE - 2) + 1};
        }

        maze[start.first][start.second] = 'S';
        maze[goal.first][goal.second] = 'G';

        int moves = bfs();
        if (moves >= 10) {
            pair<int, int> current = goal;
            int counter = moves - 1;
            while (current != start && counter > 0) {
                for (int i = 0; i < 4; i++) {
                    int next_x = current.second + dx[i];
                    int next_y = current.first + dy[i];
                    if (next_x >= 0 && next_x < SIZE && next_y >= 0 && next_y < SIZE && distances[next_y][next_x] == counter) {
                        maze[next_y][next_x] = '0' + (counter % 10);
                        current = {next_y, next_x};
                        counter--;
                        break;
                    }
                }
            }

            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    cout << maze[i][j];
                }
                cout << endl;
            }
            break;
        }
    }
    return 0;
}
