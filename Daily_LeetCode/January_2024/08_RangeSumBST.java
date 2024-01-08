import Extra_Classes.TreeNode;

// Extremely inneficient, just for testing
/*
class Solution {
    public int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null) return 0;

        int res = 0;

        if (high >= root.val && root.val >= low) {
            res += root.val;
        }

        res += rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high);

        return res;
    }
}
*/
class Solution {
    public int rangeSumBST(TreeNode root, int low, int high) {
        if (low <= root.val && root.val <= high) {
			int res = root.val;

			if (low != root.val && root.left != null) {
				res += rangeSumBST(root.left, low, high);
			}

			if (high != root.val && root.right != null) {
				res += rangeSumBST(root.right, low, high);
			}

			return res;
		} else if (low > root.val) {
			if (root.right != null) {
				return rangeSumBST(root.right, low, high);
			} else {
				return 0;
			}
		} else {
			if (root.left != null) {
				return rangeSumBST(root.left, low, high);
			} else {
				return 0;
			}
		}
    }
}
