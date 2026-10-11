class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // map each course to its prereq list
        vector<vector<int>> preMap(numCourses);
        for (auto& p : prerequisites) {
            int crs = p[0], pre = p[1];
            preMap[crs].push_back(pre);
        }

        
        unordered_set<int> visitSet;

        function<bool(int)> dfs = [&](int crs) -> bool {
            if (visitSet.count(crs)) return false;
            if (preMap[crs].empty()) return true;   

            visitSet.insert(crs);
            for (int pre : preMap[crs]) {
                if (!dfs(pre)) return false;
            }
            visitSet.erase(crs);
            preMap[crs].clear(); 
            return true;
        };

        for (int crs = 0; crs < numCourses; crs++) {
            if (!dfs(crs)) return false;
        }
        return true;
    }
};
