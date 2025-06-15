using namespace std;


class statistiche{
    public:
    virtual double compute(const vector<int>& v) = 0;
};

class media: public statistiche{
    public:
    double compute(const vector<int>& v) override{
        double somma=0;
        for (int i=0;i<v.size();i++){
            somma+=v[i];}}
        return somma/v.size();
};

class moda: public statistiche{
    public:

    double compute(const vector<int>& v) override{
        
        int max_occorrenze=0;
        for (int i=0;i<v.size();i++){
            int occorrenze=1;
            for (int j=0;j<v.size();j++){
                if (i!=j && v[i]==v[j]){
                    occorrenze++;}
            }
            if (occorrenze>=max_occorrenze){
                max_occorrenze=occorrenze;
                int num_finale=v[i];}      
    }
    return num_finale;}
};

class mediana: public statistiche{
    public:
    double compute(const vector<int>& v) override{
        sort(v.begin(),v.end());

        int len=(v.size())/2;
        if (v.size()%2!=0){
            return v[len];}
        
        return (v[len]+v[len-1])/2.0;
    }
};


int main(){

    vector<int> v={1,2,3,4,5,2,3,2};

    vector<statistiche*> s;
    s.push_back(new(media()));
    s.push_back(new(moda()));
    s.push_back(new(mediana()));

    for (int i=0;i<s.size();i++){
        s[i]->compute(v);
    }




    return 0;
}