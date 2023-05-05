/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
  let i = m + n - 1;
  let uno = m - 1;
  let dos = n - 1;
  while (uno >= 0 || dos >= 0) {
    if (uno >= 0 && dos >= 0) {
      if (nums1[uno] > nums2[dos]) {
        nums1[i--] = nums1[uno--];
      } else {
        nums1[i--] = nums2[dos--];
      }
    } else if (uno >= 0) {
      nums1[i--] = nums1[uno--];
    } else {
      nums1[i--] = nums2[dos--];
    }
  }
};
