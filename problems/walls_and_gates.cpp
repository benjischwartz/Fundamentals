#include <queue>
#include <vector>
void wallsAndGates(std::vector<std::vector<int>>& rooms) {
    int m = rooms.size();
    int n = rooms[0].size();
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (rooms[i][j] == 0) {
                q.push(std::pair{i, j});
            }
        }
    }

    while (!q.empty()) {
        auto x = q.front().first;
        auto y = q.front().second;
        visited[x][y] = true;
        q.pop();
        // update left
        if (x > 0 && !visited[x - 1][y] && rooms[x - 1][y] == INT_MAX) {
            rooms[x - 1][y] = 1 + rooms[x][y];
            q.push(std::pair{x - 1, y});
        }
        // update right
        if (x < m - 1 && !visited[x + 1][y] && rooms[x + 1][y] == INT_MAX) {
            rooms[x + 1][y] = 1 + rooms[x][y];
            q.push(std::pair{x + 1, y});
        }
        // update up
        if (y > 0 && !visited[x][y - 1] && rooms[x][y - 1] == INT_MAX) {
            rooms[x][y - 1] = 1 + rooms[x][y];
            q.push(std::pair{x, y - 1});
        }
        // update down
        if (y < n - 1 && !visited[x][y + 1] && rooms[x][y + 1] == INT_MAX) {
            rooms[x][y + 1] = 1 + rooms[x][y];
            q.push(std::pair{x, y + 1});
        }
    }
}
