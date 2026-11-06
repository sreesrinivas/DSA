class RLEIterator {

	int[] A;
	int curA = 0;
	public RLEIterator(int[] A) {
		this.A = A;
	}

	public int next(int n) {
		int num=0;
		while(n > 0) {
			if (curA >= A.length) return -1;
			n = n - A[curA];
			if (n <= 0) {
				num = A[curA+1];
				A[curA] = -n;
			} else {
				curA += 2;
			}
		}
		return num;
	}
}
