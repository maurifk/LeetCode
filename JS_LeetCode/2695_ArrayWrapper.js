/**
 * @param {number[]} nums
 */
var ArrayWrapper = function(nums) {
	this.numeros = nums || [];
};

ArrayWrapper.prototype.valueOf = function() {
	if (this.numeros.length === 0)
		return 0;

	return this.numeros.reduce((a,b) => a+b, 0);
}

ArrayWrapper.prototype.toString = function() {
	return "[" + this.numeros.toString() + "]";
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */
