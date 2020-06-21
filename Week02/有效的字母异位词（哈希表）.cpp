class Solution{
public:
    bool isAnagram(string s, string t){
        if(s.size() != t.size())
            return false;
        unordered_map<int,int> umap;
        for(char ch:s){
            ++umap[ch];
        }
        for(char ch:t){
            if(umap[ch]<=0){
                return false;
            }else{
                --umap[ch];
            }
        }
        return true;
    }
};