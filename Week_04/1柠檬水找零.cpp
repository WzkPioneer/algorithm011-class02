class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int m5 = 0, m10 = 0;
        for (int i : bills) {
            switch(i) {
                case 5: {m5 ++; continue;} 
                case 10: {m10 ++, m5 --; break;}
                case 20: if (m10 > 0) m10 --, m5 --;
                         else m5 -= 3;
            }
            if (m5 < 0) return false;
        }
        return true;
    }
};

