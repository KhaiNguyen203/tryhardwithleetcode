class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int dic[26];
            memset (dic, 0, sizeof(dic));
            int cnt=0;
            int pnt=0;
            int len = 0;
            if(s.size() != 0)
            for(int i=0; i<s.size(); i++){
                if(dic[s[i]-97] == 0){
                    cnt++;
                    len = max(cnt, len);
                    dic[s[i]-97] = 1;
                }
                else{
                    while(s[pnt] != s[i]){
                        dic[pnt] = 0;
                        cnt--;
                        pnt++;
                    }
                    pnt++;
                }
            }
            return len;
        }
    };