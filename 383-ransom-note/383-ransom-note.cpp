class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26]={0};
        //Increase count of alphabet in magazine
        for(int i=0;i<magazine.size();i++)
            arr[magazine[i]-'a']++;
        
        //Decrease count of alphabet in ransomNote
        for(int i=0;i<ransomNote.size();i++)
            arr[ransomNote[i]-'a']--;
        
        //If count less than zero for any alphabet, it is not possible to construct             ransomNote
        for(int i=0;i<26;i++)
            if(arr[i]<0)
                return false;
        
        return true;
    }
};