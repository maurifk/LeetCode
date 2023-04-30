/**
 * @param {Function} fn
 */
function memoize(fn) {
  const yaCalc = {};
  return function(...args) {
    const clave = args.join(',');
    if (yaCalc[clave] !== undefined) {
      return yaCalc[clave];
    }

    yaCalc[clave] = fn(...args);
    return yaCalc[clave];
  }
}

/**
* let callCount = 0;
* const memoizedFn = memoize(function (a, b) {
*	 callCount += 1;
*   return a + b;
* })
* memoizedFn(2, 3) // 5
* memoizedFn(2, 3) // 5
* console.log(callCount) // 1
*/
