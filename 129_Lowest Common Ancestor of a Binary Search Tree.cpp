/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root -> val > p -> val) && (root -> val > q -> val)) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        if ((root -> val < p -> val) && (root -> val < q -> val)) {
            return lowestCommonAncestor(root -> right, p, q);
        }
        return root;
    }
};

//  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
      
//         if((root->val<p->val )&& (root->val<q->val) )
//         {
//             lowestCommonAncestor(root->right,p,q);
//         }
//           if((root->val>p->val) && (root->val>q->val ))
//         {
//             lowestCommonAncestor(root->left,p,q);
//         }
//         return root;
        
//     }






// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */

// class Solution {
// public:
//     void helper(TreeNode* root,TreeNode*p,vector<TreeNode*>&vec){
       
//         if(root->val==p->val){
//             vec.push_back(root);
//             return;
//         }
//         if(root->val<p->val){
//             vec.push_back(root);
//              helper(root->right,p,vec );
//         }

//          if(root->val>p->val){
//             vec.push_back(root);
//              helper(root->left,p,vec );
//         }
        


//     }

//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode* >pvec;
//         vector<TreeNode* >qvec;
//         helper(root,p,pvec);
//         helper(root,q,qvec);
//         TreeNode* ans =NULL;

//         int size=0;
//         int i=0;
//         int j=0;
//        while(i<pvec.size() && j<qvec.size()){
//         if(pvec[i]->val==qvec[j]->val){
//             i++;
//             j++;
//         }
      

//        }

       
//         return  ans;
//     }
// };

// // pvec-> 6 2
// // qvec-> 6 2 4
