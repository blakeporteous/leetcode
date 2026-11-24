class Solution {

  private:
  
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> visit;  // false = finished, true = on current path
    string res;
  
    bool dfs(char c) {
      
      if(visit.count(c)) return visit[c];
  
      visit[c] = true;
      for(char nei : adj[c]){
          if ( dfs(nei) ) return true;
      }
  
      visit[c] = false;
      res.push_back(c);
      return false;
    }

public:
    string alienOrder(vector<string>& words) {
      
      for(const string& word : words){
          for(char c : word){
              adj[c];
          }
      }

      for(int i = 0; i + 1 < words.size(); i++){
          const string& w1 = words[i];
          const string& w2 = words[i+1];
          int minLen = min(w1.size(), w2.size());
          
          if(w1.size() > w2.size() && w1.compare(0, minLen, w2, 0, minLen) == 0){
              return "";
          }
        
          for(int j = 0; j < minLen; j++){
              if(w1[j] != w2[j]){
                  adj[w1[j]].insert(w2[j]);
                  break;
              }
          }
      }

      for(auto& [c, _] : adj){
        if ( dfs(c) ) return "";
      }

      reverse(res.begin(), res.end());
      return res;
      
    }
};
