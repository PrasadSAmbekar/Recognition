#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool isInterleave(string &s1 , string &s2 , string &s3, int index_1, int index_2, vector<vector<int>> &memory, bool curr_string){
        if (index_1 > s1.size() || index_2 > s2.size()){
            return false;
        }
        int index_3 = index_1 + index_2;
        if (index_1 == s1.size() && index_2 == s2.size() && index_3 == s3.size()){
            return true;
        }

        if (s3[index_3] != s1[index_1] && s3[index_3] != s2[index_2]){
            return false;
        }
        if (curr_string == 0){
            if (memory[index_1][index_2] != -1){
                if (memory[index_1][index_2] == 1){
                    return true;
                }
                else if (memory[index_1][index_2] == 0){
                    return false;
                }
            }
        }
        else {
            if (memory[index_2][index_1] != -1){
                if (memory[index_2][index_1] == 1){
                    return true;
                }
                else if (memory[index_2][index_1] == 0){
                    return false;
                }
            }

        }
        bool ans;
        if (s3[index_3] == s1[index_1] && s3[index_3] == s2[index_2]){
            // either take from current string or jump to next string and take from that
            bool take_from_curr = isInterleave(s1, s2, s3, index_1+1, index_2, memory, curr_string);
            bool take_from_other = isInterleave(s2, s1, s3, index_2+1, index_1, memory, !curr_string);
            ans = (take_from_curr || take_from_other);
        }
        else if (s3[index_3] == s1[index_1]){
            // take from current one only
            bool take_from_curr = isInterleave(s1, s2, s3, index_1+1, index_2, memory, curr_string);
            ans = take_from_curr;
        }
        else {
            // it means we have to jump to next string 
            bool take_from_other = isInterleave(s2, s1, s3, index_2+1, index_1, memory, !curr_string);
            ans = take_from_other;
        }

        if (curr_string == 0){
            if (ans == true){
                memory[index_1][index_2] = 1;
            }
            else {
                memory[index_1][index_2] = 0;
            }
        }
        else {
            if (ans == true){
                memory[index_2][index_1] = 1;
            }
            else {
                memory[index_2][index_1] = 0;
            }
        }
        return ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1 == ""){
            return s2 == s3;
        }
        else if (s2 == ""){
            return s1 == s3;
        }
        vector<vector<int>> memory(s1.size()+1 , vector<int>(s2.size()+1 , -1));
        return (isInterleave(s1, s2, s3, 0, 0, memory , 0));
    }
};


int main()
{
    Solution prob;
    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    if (prob.isInterleave(s1, s2, s3)){
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    
}





// "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"
// "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"
// "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"