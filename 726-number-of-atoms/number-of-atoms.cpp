class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<pair<string, int>> st;
        int i, j, k;

        for (i = 0; i < n; ++i) {
            char ch = formula[i];

            if (isupper(ch)) {
                string element = "";
                element += ch;

                for (j = i + 1; j < n; ++j) {
                    ch = formula[j];
                    if (!islower(ch)) break;
                    element += ch;
                }

                string sdigit = "";
                for (k = j; k < n; ++k) {
                    ch = formula[k];
                    if (!isdigit(ch)) break;
                    sdigit += ch;
                }

                if (sdigit == "") sdigit = "1";
                int number = stoi(sdigit);
                st.push({element, number});
                i = k - 1;
            }
            else if (ch == '(') {
                st.push({"(", -1});
            }
            else if (ch == ')') {
                string sdigit = "";
                for (j = i + 1; j < n; ++j) {
                    ch = formula[j];
                    if (!isdigit(ch)) break;
                    sdigit += ch;
                }

                if (sdigit == "") sdigit = "1";
                int number = stoi(sdigit);

                vector<pair<string, int>> temp;
                while (st.top().first != "(") {
                    auto p = st.top();
                    st.pop();
                    temp.push_back({p.first, p.second * number});
                }
                st.pop();

                for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
                    st.push(*it);
                }

                i = j - 1;
            }
        }

        map<string, int> mp;
        while (!st.empty()) {
            auto p = st.top();
            st.pop();
            mp[p.first] += p.second;
        }

        string ans = "";
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans += it->first;
            if (it->second > 1) ans += to_string(it->second);
        }

        return ans;
    }
};