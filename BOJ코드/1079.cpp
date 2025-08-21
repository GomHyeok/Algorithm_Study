#include <iostream>
#include <map>

using namespace std;

map<string, int> value;
map<string, int> multiply;

long long answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    value["black"] = 0;
    value["brown"] = 1;
    value["red"] = 2;
    value["orange"] = 3;
    value["yellow"] = 4;
    value["green"] = 5;
    value["blue"] = 6;
    value["violet"] = 7;
    value["grey"] = 8;
    value["white"] = 9;

    multiply["black"] = 1;
    multiply["brown"] = 10;
    multiply["red"] = 100;
    multiply["orange"] = 1000;
    multiply["yellow"] = 10000;
    multiply["green"] = 100000;
    multiply["blue"] = 1000000;
    multiply["violet"] = 10000000;
    multiply["grey"] = 100000000;
    multiply["white"] = 1000000000;

    string st;
    cin>>st;
    answer += value[st];

    answer *= 10;

    cin>>st;
    answer += value[st];

    cin>>st;
    answer *= multiply[st];
    
    cout<<answer<<endl;
}