class Solution {
private:
    string replace(string str, string from, string to) {
        size_t pos = 0;
        while ((pos = str.find(from, pos)) != string::npos) {
            str.replace(pos, from.length(), to);
            pos += to.length();
        }
        return str;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    string fractionAddition(string expression) {
        expression = replace(expression, "-", "+-");
        stringstream ss(expression);
        string fraction;
        int numerator = 0, denominator = 1;
        
        while (getline(ss, fraction, '+')) {
            if (!fraction.empty()) {
                int num, den;
                sscanf(fraction.c_str(), "%d/%d", &num, &den);
                
                numerator = numerator * den + num * denominator;
                denominator *= den;
                
                int gcd_val = gcd(abs(numerator), abs(denominator));
                numerator /= gcd_val;
                denominator /= gcd_val;
            }
        }
        
        return to_string(numerator) + "/" + to_string(denominator);
    }
};