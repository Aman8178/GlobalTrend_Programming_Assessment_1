#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        maxGain(root, max_sum);
        return max_sum;
    }
private:
    int maxGain(TreeNode* node, int &max_sum) {
        if (node == NULL) {
            return 0;
        }
        int left_gain = max(maxGain(node->left, max_sum), 0);
        int right_gain = max(maxGain(node->right, max_sum), 0);
        int price_newpath = node->val + left_gain + right_gain;
        max_sum = max(max_sum, price_newpath);
        return node->val + max(left_gain, right_gain);
    }
};
TreeNode* buildTree(vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int main() {
    vector<int> nodes;
    int n;
    cout << "Enter the number of nodes: ";
    cin>>n;
    while (n--) 
    {
        int t;
        cin>>t;
        nodes.push_back(t);
    }
    
    TreeNode* root = buildTree(nodes);
    
    Solution sol;
    cout << "Maximum path sum: " << sol.maxPathSum(root) << endl;
    
    return 0;
}
