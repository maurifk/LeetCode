import Extra_Classes.TreeNode;

class Solution {
    public String tree2str(TreeNode root) {
        if (root == null)
            return "";
        
        if (root.right != null) {
            return Integer.toString(root.val) + "(" + tree2str(root.left) + ")(" + tree2str(root.right) + ")";
        }
        
        if (root.left != null) {
            return Integer.toString(root.val) + "(" + tree2str(root.left) + ")";
        }

        return Integer.toString(root.val);
    }
}