/**
	* @param {any[]} arr
	* @param {number} depth
	* @return {any[]}
	*/

var flat = function (arr, n) {
	if(n==0) return arr;
	let result = [];
	const recorrer = (a, n) => {
	for(let i in a) {
		if(n>0 && Array.isArray(a[i]))
			recorrer(a[i], n-1)
		else
			result.push(a[i])
		}
	}
	recorrer(arr, n);
	return result;
};
