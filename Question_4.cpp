#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    string serialize(TreeNode* root) 
    {
        if (!root) return "";

        queue<TreeNode*> q;
        q.push(root);
        stringstream ss;
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                ss << node->val << ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "null,";
            }
        }
        
        string result = ss.str();
        result.pop_back(); 
        return result;
    }
    TreeNode* deserialize(const string& data) {
        if (data.empty()) return nullptr;
        
        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    TreeNode* leftNode = new TreeNode(stoi(item));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }
            
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    TreeNode* rightNode = new TreeNode(stoi(item));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        
        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
}

int main() {
    Codec ser, deser;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serialized = ser.serialize(root);
    cout << "Serialized: " << serialized <<endl;

    TreeNode* deserialized = deser.deserialize(serialized);
    cout << "Deserialized: ";
    printTree(deserialized);
    cout << endl;

    return 0;
}
