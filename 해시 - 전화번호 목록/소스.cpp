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
using namespace std;

bool solution(vector<string> v) {
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++) {
        int len = v[i - 1].length();
        if (v[i - 1] == v[i].substr(0, len)) {
            return false;
        }
    }
    return true;
}


void main() {
    vector<string> phone_book = { "123","456","789" };
    bool answer = solution(phone_book);
    cout << "전화번호 결과 : " << answer;
}