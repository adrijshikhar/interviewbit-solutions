#include <bits/stdc++.h>
using namespace std;

vector<string> fizzBuzz(int A) {
    vector<string> result;
    for(int i=1; i<=A; i++){
        if(i % 3 == 0 && i % 5 == 0 ){
            result.push_back("FizzBuzz");
        } else if(i % 3 == 0){
            result.push_back("Fizz");
        } else if(i % 5 == 0){
            result.push_back("Buzz");
        } else {
            result.push_back(to_string(i));
        }
    }
    return result;
}

int main() {
    int A = 10;
    vector<string> res;
    res = fizzBuzz(A);
    for (auto i: res) {
        cout<<endl;
        for (auto j: i) {
            cout<<j<<" ";
        }
    }
}