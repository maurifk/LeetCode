/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(exp) {
	this.expected = exp;

	return {
		toBe: (val) => {
			if (val === this.expected) {
				return true;
			} else {
				throw new Error ("Not Equal");
			}
		},
		notToBe: (val) => {
			if (val !== this.expected) {
				return true;
			} else {
				throw new Error ("Equal");
			}
		}
	}
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
