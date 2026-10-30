import java.util.SortedMap;
class Solution {
    public List<Integer> fallingSquares(int[][] positions) {
        List<Integer> res = new ArrayList<>();
        TreeMap<Integer, Integer> startHeight = new TreeMap<>();
        startHeight.put(0, 0); 
        int max = 0;
        for (int[] pos : positions) {
            int start = pos[0], end = start + pos[1];
            Integer from = startHeight.floorKey(start);
            int height = startHeight.subMap(from, end).values().stream().max(Integer::compare).get() + pos[1];
            max = Math.max(height, max);
            res.add(max);
            // remove interval within [start, end)
            int lastHeight = startHeight.floorEntry(end).getValue();
            startHeight.put(start, height);
            startHeight.put(end, lastHeight);
            startHeight.keySet().removeAll(new HashSet<>(startHeight.subMap(start, false, end, false).keySet()));
        }
        return res;
    }
}
