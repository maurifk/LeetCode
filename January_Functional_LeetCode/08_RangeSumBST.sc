class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
	var value: Int = _value
	var left: TreeNode = _left
	var right: TreeNode = _right
}

object Solution {
	def rangeSumBST(root: TreeNode, low: Int, high: Int): Int = {
		if (low <= root.value && root.value <= high) {

			root.value +
			(if (low != root.value && root.left != null)
				rangeSumBST(root.left, low, high)
			else 0) +
			(if (high != root.value && root.right != null)
				rangeSumBST(root.right, low, high)
			else 0)

		} else if (low > root.value) {

			if (root.right != null)
				rangeSumBST(root.right, low, high)
			else
				0

		} else {

			if (root.left != null)
				rangeSumBST(root.left, low, high)
			else
				0

		}
	}
}
