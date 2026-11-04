class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        char[] ch = s.toCharArray();
        long shiftSum =0;
        for(int i = shifts.length-1; i >=0 ; i--){
            shiftSum  += shifts[i];
            ch[i] = (char)('a' + (ch[i] -'a' + shiftSum) % 26);
        }
        return new String(ch);
    }
}
