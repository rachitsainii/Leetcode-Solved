class Solution {
public:

    bool isSet(int &x, int bit){
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit){
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit){
        return x &= ~(1 << bit);
    }

    int countSetBits(int n){
        int count = 0;
        while(n){
            count += n & 1;
            n >>= 1;
        }

        return count;
    }


    int minimizeXor(int num1, int num2) {
        int x = num1;
       int count_1 = countSetBits(num1);
       int count_2 = countSetBits(num2);
        int bit = 0; // Position of bit.
       if(count_1 < count_2){
        while(count_1 < count_2){
            if(!isSet(x, bit)){
                setBit(x, bit);
                count_1++;
            }
            bit++;
        }
       } else if(count_1 > count_2){
        while(count_1 > count_2){
            if(isSet(x, bit)){
                unsetBit(x, bit);
                count_1--;
            }
            bit++;
        }
       }

       return x;

    }
};