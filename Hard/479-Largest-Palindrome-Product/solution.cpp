int largestPalindrome(int n) {
    if (n == 1) {
        return 9;
    }
    int maxFactor = pow(10, n) - 1; // max n digit number
    int minFactor = maxFactor / 10; // min n digit number - 1
    long maxProduct = (long) maxFactor * (long) maxFactor;
    int firstHalf = maxProduct / pow(10, n);
    while (firstHalf > minFactor) {
        long palindrome = createPalindrome(firstHalf);
        for (int i = maxFactor; palindrome / i <= maxFactor && (long)i * (long)i >= palindrome; --i) {
            if (palindrome % i == 0) {
                return palindrome % 1337;
            }
        }
        --firstHalf;
    }
    return -1;
}

long createPalindrome(long firstHalf) {
    std::string str = std::to_string(firstHalf);
    str += str;
    std::reverse(str.begin() + str.length() / 2, str.end());
    return stol(str);
}
