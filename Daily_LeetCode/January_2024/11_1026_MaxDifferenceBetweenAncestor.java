import Extra_Classes.TreeNode;

class Solution {
	private int maxAncestorDiff(TreeNode root, int min, int max){
		if (root == null) {
			return max - min;
		}

		min = Math.min(min, root.val);
		max = Math.max(max, root.val);

		int leftDiff = maxAncestorDiff(root.left, min, max);
		int rightDiff = maxAncestorDiff(root.right, min, max);

		return Math.max(leftDiff, rightDiff);
	}

	public int maxAncestorDiff(TreeNode root) {
		return maxAncestorDiff(root, root.val, root.val);
	}
}
