/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
  let fib = [0,1];
  yield 0;
  yield 1;
  while(true){
      let res = fib[fib.length - 1] + fib[fib.length - 2];
      fib.push(res);
      yield res;
  }
};

/**
* const gen = fibGenerator();
* gen.next().value; // 0
* gen.next().value; // 1
*/
