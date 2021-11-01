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
#include <stack>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int, bool>> v;
    for (int i = 0; i < priorities.size(); i++) 
        v.push_back(make_pair(priorities[i], location == i));
    
    for (int i = 0; i < v.size(); i++) {
        bool toBig = false;

        for (int j = i+1; j < v.size(); j++) 
            if (v[i].first < v[j].first)
                toBig = true;

        if (toBig) {
            v.push_back(v[i]);
            v.erase(v.begin() + i);
            i--;
        }
    }

    for (int i = 0; i < v.size(); i++)
        if (v[i].second) answer = i+1;

    return answer;
}

void main() {
    vector<int> priorities = { 2, 1, 3, 2 };
    int location = 2;

    int answer = solution(priorities, location);
    cout << "인쇄 요청한 문서 번째 : " << answer;
}