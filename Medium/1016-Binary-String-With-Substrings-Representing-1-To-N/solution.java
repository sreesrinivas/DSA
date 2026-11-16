// O(S^3)
class Solution {
    public boolean queryString(String S, int N) {
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < S.length(); i++){
            for(int j = i + 1; j <= S.length(); j++){
                int v = Integer.parseInt(S.substring(i, j), 2);
                
                if(v > 0 && v <= N){
                    set.add(v);
                } else {
                    break;
                }
            }
        }
        
        return set.size() == N;
    }
}
