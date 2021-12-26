class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        vector<string> res;
        string tmp;
        for(int i = 0; i < text.length(); ++i){
            if(text[i]==' '){
                ans.push_back(tmp);
                tmp = "";
                continue;
            }
            tmp = tmp + text[i];
            if(i == text.length()-1){
                ans.push_back(tmp);
            }
        }
        for(int i = 0; i < ans.size()-2; ++i){
            if(ans[i] == first && ans[i+1] == second){
                res.push_back(ans[i+2]);
            }
        }

        return res;
    }
};