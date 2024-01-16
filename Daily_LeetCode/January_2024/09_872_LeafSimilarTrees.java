import java.util.ArrayList;
import java.util.List;

import Extra_Classes.TreeNode;

class Solution {
    List<Integer> secArb1 = new ArrayList<>();
    int puntArb2 = 0;
    boolean res = true;

    private void dfs1(TreeNode root) {
        if (root != null) {
            dfs1(root.left);
            if (root.left == null && root.right == null) secArb1.add(root.val);
            dfs1(root.right);
        }
    }

    private void dfs2(TreeNode root) {
        if (root != null) {
            dfs2(root.left);
            if (root.left == null && root.right == null) {
                if (puntArb2 >= secArb1.size() || secArb1.get(puntArb2) != root.val) {
                    res = false;
                } else {
                    ++puntArb2;
                }
            }
            dfs2(root.right);

        }
    }

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        dfs1(root1);
        dfs2(root2);
        return res && puntArb2 == secArb1.size();
    }
}
