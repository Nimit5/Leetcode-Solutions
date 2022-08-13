class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].length(), noOfWords = words.size();
        vector<int> result;
        map<string, int> wordMap;
        
        if (len * noOfWords > s.length())
            return result;
        
        for (string word : words)
            wordMap[word]++;
            
        for (int idx = 0; idx <= s.length() - (noOfWords * len); idx++) {
            map<string, int> wordsUsedMap;
            
            for (int chunkIdx = idx; chunkIdx < idx + (noOfWords * len); chunkIdx += len) {
                string cur = s.substr(chunkIdx, len);
                if(wordMap.find(cur) == wordMap.end())
                    break;

                wordsUsedMap[cur]++;
                
                if(wordsUsedMap[cur] > wordMap[cur])
                    break;
            }
            
            if (wordsUsedMap == wordMap)
                result.push_back(idx);
        }
        
        return result;
    }
};

/*
bar : 0 9 18 
foo : 3 6 15 
the : 12 
*/