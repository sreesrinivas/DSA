for(int n : nums) {
           if(n <= min1) min1 = n;
           else if(n <= min2) min2 = n;
           else return true;
