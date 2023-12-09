import java.util.LinkedList;
import java.util.List;
import Extra_Classes.TreeNode;

class Solution {
    // Recursive solution
    public List<Integer> inorderTraversal(TreeNode root) {
        if (root == null)
            return new LinkedList<Integer>();
        List<Integer> res = inorderTraversal(root.left);
        res.add(root.val);
        res.addAll(inorderTraversal(root.right));
        return res;
    }

}
