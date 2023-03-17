class Trie {
public:
Trie* children[26];
bool iswordend;
    Trie() 
    {
       for(int i=0;i<26;i++)
       {
           children[i]=nullptr;
       } 
       iswordend=false;
    }
    
    void insert(string word) 
    {
        Trie* curr=this;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(curr->children[ch-'a']==nullptr)
            {
                curr->children[ch-'a']=new Trie();
            }
            curr=curr->children[ch-'a'];
        }
        curr->iswordend=true;
    }
    
    bool search(string word) 
    {
        Trie* curr=this;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(curr->children[ch-'a']==nullptr)
            {
                return false;
            }
            curr=curr->children[ch-'a'];
        }
        if(curr->iswordend==true)
        {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) 
    {
        Trie* curr=this;
        for(int i=0;i<prefix.length();i++)
        {
            char ch=prefix[i];
            if(curr->children[ch-'a']==nullptr)
            {
                return false;
            }
            curr=curr->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
