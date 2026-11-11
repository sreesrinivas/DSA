class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        HashMap<Character, Character> map = new HashMap<>();
        for(int i=0;i<26;++i){
            map.put(order.charAt(i), (char)('a'+i));
        }

        for(int i=0;i<words.length;++i){
            StringBuilder sb = new StringBuilder();
            for(int j=0;j<words[i].length();++j){
                sb.append(map.get(words[i].charAt(j)));
            }
            words[i] = sb.toString();
        }

        String[] wordsCopy = new String[words.length];
        for(int i=0;i<words.length;++i){
            wordsCopy[i] = words[i];
        }

        Arrays.sort(wordsCopy);
        for(int i=0;i<words.length;++i){
            if(!words[i].equals(wordsCopy[i]))
                return false;
        }

        return true;
    }
}
