// LeetCode:https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=daily-question&envId=2025-01-18

// My Code:

 vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; 
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

        pq.push({0, 0, 0});
        ans[0][0] = 0;
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop(); 

            int currCost = curr[0];
            int i = curr[1];
            int j = curr[2];

            if(ans[i][j] < currCost) {
                continue;
            }

            for(int dir_i = 0; dir_i <= 3; dir_i++) {
                int i_ = i + dir[dir_i][0];
                int j_ = j + dir[dir_i][1];

                if(i_ >= 0 && j_ >= 0 && i_ < m && j_ < n) {
                    int gridDir = grid[i][j];
                    int dirCost = ((gridDir-1 != dir_i) ? 1 : 0);

                    int newCost = currCost + dirCost;

                    if(newCost < ans[i_][j_]) {
                        ans[i_][j_] = newCost;
                        pq.push({newCost, i_, j_});
                    }
                }
            }
        }
        return ans[m-1][n-1]; 
    }
