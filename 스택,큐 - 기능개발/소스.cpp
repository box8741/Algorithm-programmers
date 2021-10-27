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

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> s;
    int sum = 0;

    for (int i = 0; i < progresses.size(); i++) {
        int day;
        if ((100 - progresses[i]) % speeds[i] != 0) day = ((100 - progresses[i]) / speeds[i])+1;
        else day = (100 - progresses[i]) / speeds[i];
        
        if (s.empty()) s.push(day);

        if (s.back() >= day) sum++;
        else {
            s.push(day);
            answer.push_back(sum);
            sum = 1;
        }
    }

    if (sum != 0) answer.push_back(sum);

    return answer;
}

void main() {
    vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds = { 1, 1, 1, 1, 1, 1 };

    vector<int> answer = solution(progresses, speeds);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}