#include <iostream>
#include <vector>

using namespace std;
int test_numbers{0};
int array_size{0};
int a{0};


vector <int> quick_sort(vector <int> array){
    vector <int> left{};
    vector <int> right{};
    vector <int> middle{};
    if(array.size()<=1){
        return array;
    }
    int opora=array.at(array.size()/2);
    for(int i:array){
        if(i>opora){
            right.push_back(i);
        }
        else if(i<opora){
            left.push_back(i);
        }
        else if(i==opora){
            middle.push_back(i);
        }

    }
    left=quick_sort(left);
    right=quick_sort(right);
    vector<int>result{};
    for(int i:left){
        result.push_back(i);
    }
    for(int i:middle){
        result.push_back(i);
    }
    for(int i:right){
        result.push_back(i);
    }
    return result;
}
int main(){
    vector <int> diff_answer{};
    cin>>test_numbers;
    for(int i=0;i<test_numbers;i++){
        cin>>array_size;
        vector <int>arraychik{};
        for(int j=0;j<array_size;j++){
            cin>>a;
            arraychik.push_back(a);
        }
        vector <int> sorted_array=quick_sort(arraychik);
        int diff{0};
        int a{0};
        int b{0};
        for(int x=0;x<sorted_array.size();x+=2){
            a=sorted_array.at(x);
            b=sorted_array.at(x+1);
            if((b-a)>diff){
                diff=(b-a);
            }
        }
        diff_answer.push_back(diff);

    }
    for(int x:diff_answer){
        cout<<x<<"\n";
    }
     
}