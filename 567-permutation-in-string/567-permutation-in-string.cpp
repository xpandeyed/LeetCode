class Solution {
public:
bool checkInclusion(string s1, string s2)
{
    if (s2.size() < s1.size())
    {
        //cout << "Small" << endl;
        return false;
    }
    map<char, int> pat;
    map<char, int> str;
    for (int i = 0; i < s1.size(); ++i)
    {
        if (pat.find(s1[i]) == pat.end())
        {
            pat[s1[i]] = 1;
        }
        else
        {
            pat[s1[i]]++;
        }
        if (str.find(s2[i]) == str.end())
        {
            str[s2[i]] = 1;
        }
        else
        {
            str[s2[i]]++;
        }
    }
    if(s1.size()==s2.size()){
        for(auto x: pat){
            if(str.find(x.first)==str.end() || str[x.first]!=pat[x.first]){
                return false;
            }
        }
        return true;
    }
    int count = 0;
    for (int i = s1.size(); i < s2.size(); ++i)
    {
        // cout << "Pattern : " << endl;
        // for (auto y : pat)
        // {
        //     cout << y.first << " " << y.second << endl;
        // }
        // cout << "String : " << endl;
        // cout << str.size() << endl;
        // for (auto y : str)
        // {
        //     cout << y.first << " " << y.second << endl;
        // }
        // cout << endl << endl;
        count = 0;
        for (auto x : pat)
        {
            count+=x.second;
            if (str.find(x.first) == str.end() || str[x.first] != x.second)
            {
                break;
            }
            else
            {
                // cout <<"Count : " <<count<<endl;
                if (count == s1.size())
                {
                    return true;
                }
            }
            
        }
        str[s2[i - s1.size()]]--;
        if (str.find(s2[i]) == str.end())
        {
            str[s2[i]] = 1;
        }
        else
        {
            str[s2[i]]++;
        }
    }
    count = 0;
    for (auto x : pat)
    {
        count+=x.second;
        if (str.find(x.first) == str.end() || str[x.first] != x.second)
        {

            break;
        }
        else
        {

            if (count == s1.size())
            {
                return true;
            }
        }
        
    }
    return false;
}
};