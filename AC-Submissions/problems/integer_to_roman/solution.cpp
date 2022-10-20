class Solution {
public:
    vector<pair<int, string>> Map={
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"},
        {40, "XL"}, {10, "X"},  {9, "IX"}, {5, "V"}, {4, "IV"}, {3, "III"}, {2, "II"},{1, "I"} 
    };
    string intToRoman(int num) {
        string res;
        for (auto i : Map) {
            while (num >= i.first) {
                res += i.second, num -= i.first;
            }
        }
        return res;
    }
};


