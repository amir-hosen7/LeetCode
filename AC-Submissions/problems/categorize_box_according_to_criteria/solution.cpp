class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        int mx = max(length, max(width, height));
        long long volume = (long long) length * width;
        volume *= height;
        long long aa = 1000000000;
        if ((mx >= 10000 or volume >= aa) and mass >= 100) {
            return "Both";
        }
        else if((mx >= 10000 or volume >= 1000000000)) {
            return "Bulky";
        }
        else if(mass >= 100) {
            return "Heavy";
        }
        else{
            return "Neither";
        }
    }
};