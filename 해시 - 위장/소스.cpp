#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map <string, int> hash;
    for (int i = 0; i < clothes.size(); i++)
        hash[clothes[i][1]]++;

    unordered_map<string, int>::iterator iter;
    for (iter = hash.begin(); iter != hash.end(); iter++) {
        answer *= (iter->second + 1);
    }

    answer--;

    return answer;
}

void main() {
    vector<vector<string>> clothes = { {"yellowhat", "headgear"},{"bluesunglasses", "eyewear"},{"green_turban", "headgear"}};
    //vector<vector<string>> clothes = { {"crowmask", "face"} ,{"bluesunglasses", "face"},{"smoky_makeup", "face"} };
    int answer = solution(clothes);
    cout << "위장 개수 : " << answer;
}