class Solution {
private:
    int expand(const string& s, int l, int r){
            int c = 0;
            while(l >= 0 && r < (int)s.size() && s[l] == s[r]){
                c++;
                l--;
                r++;
            }
            return c;
    }
public:
    int countSubstrings(string s) {
        int count = 0;
        
        for(int i = 0; i < s.size(); i++){
            count += expand(s, i, i);
            count += expand(s, i, i + 1);
        }
        return count;
    }
};
