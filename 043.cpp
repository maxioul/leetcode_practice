class Solution {
public:
    string multiply(string num1, string num2) {
    int cross = 0, add = 0;
    vector<string>work;
    work.resize(num1.length());
    string output;
    for (int i = num1.length() - 1; i >= 0; i--) {
        for (int j = i; j < num1.length()-1; j++) {
            work[i].push_back('0');
        }
        for (int j = num2.length() - 1; j >= 0; j--) {
            cross = (num1[i] - '0') * (num2[j] - '0') + add;
            work[i].push_back(cross % 10 + '0');
            add = cross / 10;
        }
        if(add)work[i].push_back(add + '0');
        add = 0;
    }
    add = 0;
    for (int i = 0; i < work[0].length(); i++) {
        int sum = add;
        for (int j = 0; j < work.size(); j++) {
            if (i < work[j].length()) {
                sum += work[j][i] - '0';
            }
        }
        output.push_back(sum % 10 + '0');
        add = sum / 10;
    }
    while (add) {
        output.push_back(add % 10 + '0');
        add = add / 10;
    }
        while(output.back()=='0'&&output.length()>1)output.pop_back();
    reverse(output.begin(), output.end());
        
    return output;
}
};
