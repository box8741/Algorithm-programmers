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

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<>());

    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i+1) {
            answer += 1;
        }
    }

    return answer;
}

void main() {
    vector<int> numbers = { 3, 0, 6, 1, 5 };

    int answer = solution(numbers);
    cout << "H-Index : " << answer << endl;
}