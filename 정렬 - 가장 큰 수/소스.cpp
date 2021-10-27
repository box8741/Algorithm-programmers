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

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for (int i = 0; i < numbers.size(); i++)
        v.push_back(to_string(numbers[i]));
    
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++) 
        answer += v[i];
    
    if (answer.at(0) == '0') answer = "0";
    return answer;
}

void main() {
    //vector<int> numbers = { 0,0,0 };
    vector<int> numbers = { 3, 30, 34, 5, 9 };

    string answer = solution(numbers);
    cout << "가장 큰 수 : " << answer << endl;
}