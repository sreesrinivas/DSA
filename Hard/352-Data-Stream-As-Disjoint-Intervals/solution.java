import java.util.*;

class Pair implements Comparable<Pair>{
    int x, y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object o) {
        if(o == this) return true;
        if(!(o instanceof Pair)) return false;
        Pair pr = (Pair) o;
        return pr.x == x && pr.y == y;
    }

    @Override
    public int hashCode() {
        int result = x;
        return result * 31 + y;
    }

    @Override
    public int compareTo(Pair p) {
        if(this.x < p.x) return -1;
        else if(this.x > p.x) return 1;
        else{
            if(this.y == p.y) return 0;
            else if(this.y < p.y) return -1;
            else return 1;
        }
    }
}

class SummaryRanges {
    TreeSet<Pair> ranges;

    public SummaryRanges() {
        // maintain a sortedset of pairs
        ranges = new TreeSet<>();
    }
    
    public void addNum(int value) {
        // find lower and higher pairs and try to merge them
        Pair current = new Pair(value, value);
        int currLow = value, currHigh = value;
        Pair lower = ranges.lower(current);
        Pair higher = ranges.higher(current);
        boolean deleteLower = false, deleteUpper = false;
        if(lower != null && lower.y >= value - 1 && lower.x < value) {
            currLow = lower.x;
            currHigh = Math.max(lower.y, value);
            deleteLower = true;
        }
        if(higher != null && higher.x <= value + 1 && higher.y > value) {
            currHigh = higher.y;
            currLow = Math.min(currLow, higher.x);
            currLow = Math.min(currLow, value);
            deleteUpper = true;
        }
        // ranges.add(new Pair(value, value));
        if(deleteLower) ranges.remove(lower);
        if(deleteUpper) ranges.remove(higher);
        ranges.add(new Pair(currLow, currHigh));
    }
    
    public int[][] getIntervals() {
        // iterate over sorted set
        int[][] ans = new int[ranges.size()][2];
        int i = 0;
        for(Pair p: ranges) {
            ans[i][0] = p.x;
            ans[i++][1] = p.y;
        }
        return ans;
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(value);
 * int[][] param_2 = obj.getIntervals();
 */
