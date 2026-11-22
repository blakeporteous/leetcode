/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    vector<string> res;
    vector<string> vals;
    int i;

    void dfs_ser(TreeNode* node){
        if(!node){
            res.push_back("N");
            return;
        }
        res.push_back(to_string(node->val));
        dfs_ser(node->left);
        dfs_ser(node->right);

    }

    TreeNode* dfs_des(){
        if(vals[i] == "N"){
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfs_des();
        node->right = dfs_des();
        return node;
    }


public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        res.clear();
        dfs_ser(root);

        string out;
        for(int k = 0; k < res.size(); k++){
            if(k > 0) out += ",";
            out += res[k];
        }
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vals.clear();
        stringstream ss(data);
        string tok;

        while(getline(ss, tok, ',')) vals.push_back(tok);

        i = 0;
        return dfs_des();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
