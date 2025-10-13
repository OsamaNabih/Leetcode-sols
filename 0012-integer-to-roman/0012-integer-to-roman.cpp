class Solution {
public:
    char getCurrLiteral(int tenPower, char digitChar) {
        int digit = digitChar - '0';
        if (digit < 5) {
            switch (tenPower) {
            case 0:
                return 'I';
            case 1:
                return 'X';
            case 2:
                return 'C';
            case 3:
                return 'M';
            }
        }
        switch (tenPower) {
            case 0:
                return 'V';
            case 1:
                return 'L';
            case 2:
                return 'D';
        }
        return '!';
    }
    string intToRoman(int num) {
        string numString = to_string(num);
        int i = 0;
        string ans = "";
        int tenPower;
        char currLiteral;
        while (i < numString.size()) {
            tenPower = numString.size() - 1 - i;
            if (numString[i] == '4') {
                ans += string(1, getCurrLiteral(tenPower, '1'));
                ans += string(1, getCurrLiteral(tenPower, '5'));
                i++;
            } else if (numString[i] == '9') {
                ans += string(1, getCurrLiteral(tenPower, '1'));
                ans += string(1, getCurrLiteral(tenPower + 1, '1'));
                i++;
            } else if (numString[i] >= '5') {
                ans += string(1, getCurrLiteral(tenPower, '5'));
                numString[i] -= 5;
            }    
            else {
                while(numString[i] != '0') {
                    ans += string(1, getCurrLiteral(tenPower, numString[i]));
                    numString[i] -= 1;
                }
                i++;
            }
        }
        return ans;
    }
};