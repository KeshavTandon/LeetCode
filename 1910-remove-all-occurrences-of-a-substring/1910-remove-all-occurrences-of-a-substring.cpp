class Solution {
public:
    void removeSubstring(string &s,string &part)
    {
        int position=s.find(part);
        if(position!=string::npos)
        {
            //part has been found
            string left_part=s.substr(0,position);
            string right_part=s.substr(position+part.size(),s.size());
            s=left_part+right_part;
            removeSubstring(s,part);
        }
        else{
            //no substring is found so return 
            return;
        }
    }
    
    string removeOccurrences(string s, string part) {
        removeSubstring(s,part);
        return s;
    }
};