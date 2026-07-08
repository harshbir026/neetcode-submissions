/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == nullptr){
                s+="#,";
            }else{
                s = s + to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return nullptr;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        queue<TreeNode*> q;
        TreeNode* newNode = new TreeNode(stoi(str));
        q.push(newNode);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str!="#"){
                node->left = new TreeNode( stoi(str));
                q.push(node->left);
            }
            getline(s,str,',');
            if(str!="#"){
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return newNode;
    }
};
