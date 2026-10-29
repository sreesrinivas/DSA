class MapSum {
public:
    class Trie{
        public:
        int end;
        Trie* child[26];
        Trie(){
            for(int i=0;i<26;i++)child[i]=NULL;
            end=0;
        }
    };
    unordered_map<string,int>m;
    Trie* root;
    
    MapSum() {
        root=new Trie();
    }
    
    void insert(string key, int val) {
        int prev=m[key];
        m[key]=val;
        val-=prev;
        Trie* t=root;
        for(auto &x:key){
            if(t->child[x-'a']==NULL)t->child[x-'a']=new Trie();
            t=t->child[x-'a'];
            t->end+=val;
        }
    }
    
    int sum(string prefix) {
        Trie* t=root;
        for(auto &x:prefix){
            if(t->child[x-'a']==NULL)return 0;
            t=t->child[x-'a'];
        }
        return t->end;
    }
};
