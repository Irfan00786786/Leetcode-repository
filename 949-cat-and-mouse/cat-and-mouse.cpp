class Solution {
public:

    int catMouseGame(vector<vector<int>>& graph) {

        const int DRAW = 0;
        const int MOUSE = 1;
        const int CAT = 2;

        int n = graph.size();
        vector<vector<vector<int>>> result(
            n, vector<vector<int>>(n, vector<int>(2, DRAW))
        );

        vector<vector<vector<int>>> degree(
            n, vector<vector<int>>(n, vector<int>(2, 0))
        );
        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {

                degree[m][c][0] = graph[m].size();

                for (int next : graph[c]) {
                    if (next != 0) {
                        degree[m][c][1]++;
                    }
                }
            }
        }

        queue<array<int, 3>> q;

        for (int c = 1; c < n; c++) {
            for (int turn = 0; turn < 2; turn++) {
                result[0][c][turn] = MOUSE;
                q.push({0, c, turn});
            }
        }

        for (int m = 1; m < n; m++) {
            for (int turn = 0; turn < 2; turn++) {
                result[m][m][turn] = CAT;
                q.push({m, m, turn});
            }
        }

        while (!q.empty()) {

            auto [m, c, turn] = q.front();
            q.pop();

            int currentResult = result[m][c][turn];
            if (turn == 0) {

                for (int prevC : graph[c]) {
                    if (prevC == 0)
                        continue;

                    if (result[m][prevC][1] != DRAW)
                        continue;
                    if (currentResult == CAT) {
                        result[m][prevC][1] = CAT;
                        q.push({m, prevC, 1});
                    }

                    else {
                        degree[m][prevC][1]--;

                        if (degree[m][prevC][1] == 0) {
                            result[m][prevC][1] = MOUSE;
                            q.push({m, prevC, 1});
                        }
                    }
                }
            }
            else {

                for (int prevM : graph[m]) {
                    if (result[prevM][c][0] != DRAW)
                        continue;

                    if (currentResult == MOUSE) {
                        result[prevM][c][0] = MOUSE;
                        q.push({prevM, c, 0});
                    }

                    else {
                        degree[prevM][c][0]--;
                        if (degree[prevM][c][0] == 0) {
                            result[prevM][c][0] = CAT;
                            q.push({prevM, c, 0});
                        }
                    }
                }
            }
        }
        return result[1][2][0];
    }
};