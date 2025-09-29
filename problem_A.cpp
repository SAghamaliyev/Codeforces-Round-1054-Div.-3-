#include <iostream>
#include <vector>
using namespace std;

int main(){
    int number_tests{0};
    int array_size{0};
    int a{0};
    int answer{0};
    int controller_negative{0};

    
    vector <int>answer_list{};
    cin>>number_tests;
    for(int i=0;i<number_tests;i++){
        cin>>array_size;
        for(int j=0;j<array_size;j++){
            cin>>a;
            if(a==0){
                answer++;
            }
            else if(a==(-1)){
                controller_negative++;
            }
        }
        if(controller_negative%2!=0){
            answer+=2;
        }
        controller_negative=0;
        answer_list.push_back(answer);
        answer=0;
    }
    for(int i:answer_list){
        cout<<i<<"\n";
    }
}