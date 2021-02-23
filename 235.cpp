/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

示例 1:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。
示例 2:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 
说明:
所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉搜索树中。
*/
/*
解释：

二叉搜索树有很良好的性质：
左子树节点值 < 根节点值；
右子树节点值 > 根节点值；
每个节点都有1，2的性质；

现在我们做一些设定：
node1和node2是二叉搜索树中的两个节点；
root是二叉搜索树的根节点。
function(root) = (root->val - node1->val)×(root->val - node2->val)

根据这些性质我们知道：
如果node1和node2在root的左侧，那么function(root)>0，root->val-node1->val>0;
如果node1和node2在root的右侧，那么function(root)>0，root->val-node1->val<0;
如果node1和node2在root的两侧，那么function(root)<0;

具体算法流程：
如果node1和node2在root的左侧，root=root->left；
如果node1和node2在root的右侧，root=root->right；
如果node1和node2在root的两侧，返回root；

时间复杂度：O(logN)
空间复杂度：O(1)
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while((root->val-p->val)*(root->val-q->val)>0)
            if(root->val-p->val>0) root=root->left;
            else root=root->right;
        return root;
    }
};
