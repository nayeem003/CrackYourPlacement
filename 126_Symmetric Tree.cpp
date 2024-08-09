        //      1
      //      /   \
    //       2     2
   //       / \   / \
  //       3   4 4   3

// Root Node: The root is 1, and we start by enqueuing its left child (2) and right child (2).
// First Iterative Check: We dequeue two nodes at a time, first left and right.
// This compares the left subtree of the left child (3 from the left 2) with the right subtree of the right child (3 from the right 2).
// Since both are 3, they are mirrors of each other at this node.
// Second Iterative Check: Next, we enqueue and then dequeue the next pair of nodes to compare.
// This compares the right subtree of the left child (4 from the left 2) with the left subtree of the right child (4 from the right 2).
// Since both are 4, they are also mirrors of each other at this node.

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true; // An empty tree is symmetric
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()){
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            if(left == NULL  && right == NULL) continue; // Both are NULL, symmetric at this level
            if(left ==NULL  or  right==NULL) return false; // One is NULL and the other is not, not symmetric
            if(left->val != right->val) return false; // Values differ, not symmetric
            // Enqueue children in the order to compare them as mirror images
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true; // tree is symmetric
    }
};
