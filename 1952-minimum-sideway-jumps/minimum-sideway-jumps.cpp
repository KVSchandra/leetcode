class Solution {
public:
    int solve(int lane, int i, vector<int>& obstacles, vector<vector<int>>&dp) {
        if(i == obstacles.size()) return 0;
        if(dp[lane][i] != -1) return dp[lane][i];
        int pick1 = 1e9, pick2 = 1e9;
        if(obstacles[i] == lane) {
            for(int newLane = 1; newLane <= 3; ++newLane) {
                if(newLane != lane && (i == 0 || obstacles[i-1] != newLane)) {
                    pick1 = min(pick1, 1 + solve(newLane, i, obstacles, dp));
                }
            }
        } 
        else {
            pick2 = solve(lane, i + 1, obstacles, dp);
        }

        return dp[lane][i] = min(pick1, pick2);
    }

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, -1));
        return solve(2, 0, obstacles, dp); 
    }
};
