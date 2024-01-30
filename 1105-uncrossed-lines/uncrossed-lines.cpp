class Solution {
public:
    int solve(int i, int j, vector<int>&nums1, vector<int>&nums2, vector<vector<int>>&dp){
        if(i == nums1.size() || j == nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int pick = INT_MIN;
        if(nums1[i] == nums2[j]) pick = 1 + solve(i+1, j+1, nums1, nums2, dp);
        int notPick = 0 + max(solve(i+1, j, nums1, nums2, dp), solve(i, j+1, nums1, nums2, dp));
        return dp[i][j] = max(pick, notPick);
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(), vector<int>(nums2.size(), -1));
        return solve(0, 0, nums1, nums2, dp);
    }
};