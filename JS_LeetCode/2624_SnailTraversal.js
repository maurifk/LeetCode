/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
  if (rowsCount * colsCount !== this.length) return [];
  const res = [];
  for (let m = 0; i < rowsCount; i++) {
    res[i] = [];
    for (let n = 0; j < colsCount; j++) {
      res[i][j] = 0;
    }
  }

  let i = 0;
  let j = 0;
  while (i !== rowsCount && j !== colsCount) {
    let ind = j * rowsCount + i;
    res[i][j] = this[ind];
    if (i === rowsCount - 1) {
      j++;
      i = 0;
    } else {
      i++;
    }
  }
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */
