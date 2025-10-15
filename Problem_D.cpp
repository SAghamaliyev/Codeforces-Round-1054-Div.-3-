#include <iostream>
#include <vector>
using namespace std;

long long int Teymur_lion(vector <long long int> combi){
    if(combi.size()==1||combi.size()==0){
        return 0;
    }
    long long int middle=combi.size()/2;
    long long int answer=0;
    long long int temp=0;

    for(long long int i=(middle);i>0;i--){
        answer+=(combi.at(i)-combi.at(i-1)-1+temp);
        temp+=combi.at(i)-combi.at(i-1)-1;
    }
    temp=0;

    for(long long int i=(middle);i<(combi.size()-1);i++){
        answer+=(combi.at(i+1)-combi.at(i)-1+temp);
        temp+=combi.at(i+1)-combi.at(i)-1;
    }
    return answer;
}

int main(){
    long long int n_tests,n_letters;
    long long int answer,answer2;
    long long int a_numbers=0,b_numbers=0;
    char letter,main_purp;
    vector<char> combi{};
    vector<long long int> patyiminutka{};
    vector<long long int> answers{};

    cin>>n_tests;
    for(long long int i=0;i<n_tests;i++){
        cin>>n_letters;
        for(long long int j=0;j<n_letters;j++){
            cin>>letter;
            combi.push_back(letter);
        }

        for(long long int x=0;x<(combi.size());x++){
            if(combi.at(x)=='a'){
                patyiminutka.push_back(x);
            }
        }
        answer=Teymur_lion(patyiminutka);
        patyiminutka.clear();
        patyiminutka.shrink_to_fit();

        for(long long int x=0;x<(combi.size());x++){
            if(combi.at(x)=='b'){
                patyiminutka.push_back(x);
            }
        }
        answer2=Teymur_lion(patyiminutka);
        if(answer<0){
            answer*=(-1);
        }
        if(answer2<0){
            answer2*=(-1);
        }
        if(answer>answer2){
            answer=answer2;
        }
        answers.push_back(answer);
    
        answer=0;
        answer2=0;
        patyiminutka.clear();
        patyiminutka.shrink_to_fit();
        combi.clear();
        combi.shrink_to_fit();
    }
    for(int x:answers){
        cout<<x<<"\n";
    }
}
