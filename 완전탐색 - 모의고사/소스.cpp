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

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> arr = { 0,0,0 };
    vector<int> v1 = { 1, 2, 3, 4, 5 };
    vector<int> v2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> v3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == v1[i % v1.size()]) arr[0]++;
        if (answers[i] == v2[i % v2.size()]) arr[1]++;
        if (answers[i] == v3[i % v3.size()]) arr[2]++;
    }

    int max = 0;
    for (int i = 0; i < arr.size(); i++) 
        if (arr[i] > max) max = arr[i];

    for (int i = 0; i < arr.size(); i++)
        if (max == arr[i]) answer.push_back(i + 1);

    return answer;
}

void main() {
    vector<int> answers = { 1,2,3,4,5 };

    vector<int> answer = solution(answers);
    for (int i = 0; i < answer.size(); i++)
        cout << "가장 많이 맞힌 수포자 : " << answer[i] << endl;
}