class calcolatore_frequenze{
    public:
    unordered_map<char,int>mappa;

    void leggi_testo(const string& s){
        for (int i=0;i<s.size();i++){
            mappa[s[i]]++;
        }
    }
    vector<char> top(int k) const{
        vector<char,int> v(mappa.begin(),mappa.end());
        auto lambda=[](const auto& a, const auto& b){return a.first>b.first;}
        sort(v.begin(),v.end(),lambda);

        vector<char>x;
        for (int i=0;i<k;i++){
            x.push_back(v[i].first);
        }
        return x;
    }
    virtual double frequenze(char c) const{
        for (auto it=mappa.begin();it!=mappa.end();it++){
            if (it->first==c){return it->second;}
        }
    }
};

class frequenze_relative: public calcolatore_frequenze{
    public:
    double frequenze(char c) const override{
        int num, somma=0;
        for (auto it=mappa.begin();it!=mappa.end();it++){
            somma+=it->second;
            if (it->first==c){int num=it->second;}
        }
        return num/somma;
    }

};