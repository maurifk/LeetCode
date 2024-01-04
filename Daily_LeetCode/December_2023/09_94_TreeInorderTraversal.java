import java.util.LinkedList;
import java.util.List;
import java.util.Stack;
import Extra_Classes.TreeNode;


class Solution {
    // Recursive solution
    public List<Integer> inorderTraversalRec(TreeNode root) {
        if (root == null)
            return new LinkedList<Integer>();
        List<Integer> res = inorderTraversalRec(root.left);
        res.add(root.val);
        res.addAll(inorderTraversalRec(root.right));
        return res;
    }

    // Iterative solution
    public List<Integer> inorderTraversal(TreeNode root) {
        if (root == null)
            return new LinkedList<Integer>();

        Stack<TreeNode> stack = new Stack<TreeNode>();
        List<Integer> res = new LinkedList<Integer>();

        TreeNode curr = root;
        while (true) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }

            if (stack.isEmpty())
                break;

            curr = stack.pop();
            res.add(curr.val);
            curr = curr.right;
        }

        return res;
    }
}
