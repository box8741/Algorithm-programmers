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

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> v;
        int start = commands[i][0];
        int end = commands[i][1];
        int position = commands[i][2] - 1;

        for (int j = start - 1; j < end; j++) {
            v.push_back(array[j]);
        }

        sort(v.begin(), v.end());

        answer.push_back(v[position]);
    }

    return answer;
}

void main() {
    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };

    vector<int> answer = solution(array, commands);
    
    for (int i=0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}