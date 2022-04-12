#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool isFind(vector<pair<string, int>> arr, string str)
{
    for (const auto i : arr)
        if (i.first == str)
            return true;
    return false;
}

int changeNum(vector<pair<string, int>> arr, string str)
{
    for (const auto i : arr)
        if (i.first == str)
            return i.second;
}

int solution(string s)
{
    string answer = "";
    vector<pair<string, int>> t = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    string sumStr;
    for (const auto c : s)
    {
        if (int('0') <= int(c) && int(c) <= int('9'))
        {
            answer += c;
            continue;
        }
        sumStr += c;
        if (isFind(t, sumStr))
        {
            int num = changeNum(t, sumStr);
            answer += to_string(num);
            sumStr = "";
        }
    }

    return stoi(answer);
}

int main()
{
    string s = "one4seveneight";
    int result = solution(s);
    cout << result << endl;
    return 0;
}