int bound = matrix.length < k ? matrix.length : k;
for(int j = 0; j < bound; j++)  {
    pq.offer(new Tuple(0, j, matrix[0][j]));
}
