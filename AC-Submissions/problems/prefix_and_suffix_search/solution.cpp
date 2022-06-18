class WordFilter {
    unordered_map<string,int> dict;
public:
    WordFilter(vector<string>& words) {
        
        for(int index=0; index<words.size(); ++index){
            
            const string currWord = words[index];
            const int currWordLen = currWord.size();
            
            for(int i=1; i<=currWordLen; ++i){ // try all possible prefix
                
                string prefix = currWord.substr(0,i);
                
                for(int j=0; j<currWordLen; ++j){ // for every prefix generate all possible suffix
                    
                    string suffix = currWord.substr(j, currWordLen);
                    
                    string hash = prefix + "#" + suffix;
                    
                    dict[hash]= index+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        const string hash = prefix + "#" + suffix;
        return dict[hash] - 1;
    }
};