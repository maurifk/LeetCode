/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
  return arr.group((_a,i) => Math.floor(i/size));
};

console.log(chunk([1,2,3,1,23,1,2], 2));
