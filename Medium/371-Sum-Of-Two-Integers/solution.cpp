int getSum(int x, int y){
        unsigned carry ;
        while(y != 0){
            //generate carry
            carry = x & y;
            //xor x,y and assign the result into x
            x = x ^ y;
            //left shift carry and assign into y
            y = carry << 1;            
            
        }
        return x;
    }
