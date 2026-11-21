class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
        HashMap<Integer, Integer> hash_label = new HashMap<Integer, Integer>();

        // create a hashmap for maintaining the use_limit of each label group
		for (int i : labels) {
			hash_label.put(i, 0);
		}

		int size = values.length;
		int[][] val_lab = new int[size][2];

        // creating a 2D array which has values and labels corresponding to the values
		for (int i = 0; i < size; i++) {
			val_lab[i][0] = values[i];
			val_lab[i][1] = labels[i];
		}

        // sorting the array in descending order based on the values from column 0
		Arrays.sort(val_lab, new Comparator<int[]>() {
			public int compare(final int[] entry1, final int[] entry2) {

				if (entry1[0] < entry2[0])
					return 1;
				else
					return -1;
			}
		});
		int sum = 0;

		for (int i = 0; i < size; i++) {
			int val = val_lab[i][0];
			int lab = val_lab[i][1];
        // if label usage less than use_limit and subset size is less than num_wanted, include array item in the subset
			if (num_wanted > 0 && hash_label.get(lab) < use_limit) {

				sum += val;
				hash_label.put(lab, hash_label.get(lab) + 1);
				num_wanted--;
			}
		}

		return sum;
    }
}
