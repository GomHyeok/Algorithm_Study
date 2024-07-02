#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int answer = 0;
    int tileLength = 0;
    map<string, int> board;
    map<char, int> tile;
    vector<string> a;

    void dfs(map<char, int> tiles, int length, string now) {
        if(tileLength <= length) return;
        for(auto iter : tiles) {
            if(iter.second > 0) {
                if(board[now+iter.first]) continue;
                answer++;
                a.push_back(now + iter.first);
                tiles[iter.first]--;
                dfs(tiles, length+1, now+iter.first);
                tiles[iter.first]++;
            }
        }
        return;
    }

    int numTilePossibilities(string tiles) {

        tileLength = tiles.size();

        for(int i=0; i<tiles.size(); i++) {
            tile[tiles[i]]++;
        }

        dfs(tile, 0, "");

        // for(int i=0; i<a.size(); i++) {
        //     cout<<a[i]<<endl;
        // }

        return answer;
    }
};

int main() {
    string st = "AAB";

    Solution s;

    cout<<s.numTilePossibilities(st)<<endl;
}