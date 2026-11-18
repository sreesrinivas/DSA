/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {number}
 */
var numSubmatrixSumTarget = function(matrix, target) {

  const rows = matrix.length, cols = matrix[0].length;

  for (let row of matrix) {
    for (let i = 1; i < cols; ++i) {
      row[i] += row[i - 1];
    }
  }

  let count = 0, sum, counter;
  for (let c1 = 0; c1 < cols; ++c1) {
    for (let c2 = c1; c2 < cols; ++c2) {
      sum = 0;
      counter = new Map([[0, 1]]);
      for (let r = 0; r < rows; ++r) {
        sum += matrix[r][c2] - (c1 ? matrix[r][c1 - 1] : 0);
        if (counter.has(sum - target)) count += counter.get(sum - target);
        counter.set(sum, (counter.get(sum) || 0) + 1);
      }
    }
  }
  return count;
};
