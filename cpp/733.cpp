class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int original = image[sr][sc];

        if (original == color)
            return image;

        dfs(image, sr, sc, original, color);

        return image;
    }

    void dfs(vector<vector<int>>& image, int r, int c, int original, int color) { 
        
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size()) {
            return;
        }

        if (image[r][c] != original)
            return;

        image[r][c] = color;

        dfs(image, r - 1, c, original, color);
        dfs(image, r + 1, c, original, color);
        dfs(image, r, c - 1, original, color);
        dfs(image, r, c + 1, original, color);
    }
};
