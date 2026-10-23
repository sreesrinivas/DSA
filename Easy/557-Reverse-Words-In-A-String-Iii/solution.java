public class Solution {
    public string ReverseWords(string s) {
        char[] chars = s.ToCharArray();
        int start = 0;
        
        for (int i = 0; i < chars.Length; i++) {
            if (chars[i] == ' ' || i == chars.Length - 1) {
                int end = (i == chars.Length - 1 && chars[i] != ' ') ? i + 1 : i;
                while (start < end) {
                    char temp = chars[start];
                    chars[start] = chars[end - 1];
                    chars[end - 1] = temp;
                    start++;
                    end--;
                }
                start = i + 1;
            }
        }
        
        return new string(chars);
    }
}
