class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& checked, int r, int c) {
        // 1. if r or c is out of bounds -> return
        if((r >= checked.size()) || (c >= checked[0].size())){
            return;
        }
        if((r < 0) || (c < 0)){
            return;
        }
        // 2. if grid[r][c] is water, or checked[r][c] is already 1 -> return
        if((grid[r][c] == '0') || checked[r][c] == 1){
            return;
        }
        // 3. mark checked[r][c]
        checked[r][c] = 1;
        // 4. call dfs on the four neighbours (up, down, left, right)
        dfs(grid, checked, r - 1, c);
        dfs(grid, checked, r + 1, c);
        dfs(grid, checked, r, c - 1);
        dfs(grid, checked, r, c + 1);

    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        vector<vector<int>> checked(grid.size(), vector<int>(grid[0].size(), 0));

        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if((grid[r][c] == '1') && (checked[r][c] == 0)){
                    islands += 1;
                    dfs(grid, checked, r, c);
                }
            }
        }

        // loop over every row r and column c
        //   if it's land and not checked yet:
        //     it's a new island -> count it, then dfs from there

        return islands;
    }
};
