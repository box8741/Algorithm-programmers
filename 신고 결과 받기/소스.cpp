#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int findIndex(vector<pair<string, int>> arr, string target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].first == target)
            return i;
    }
    return -1;
}

vector<string> split(string str)
{
    istringstream ss(str);
    vector<string> arr;
    string str_buf;
    while (getline(ss, str_buf, ' '))
    {
        arr.push_back(str_buf);
    }
    return arr;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    vector<pair<string, int>> idNum;
    vector<pair<string, int>> accReport;
    vector<string> ban;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    for (int i = 0; i < id_list.size(); i++)
        idNum.push_back(make_pair(id_list[i], 0));

    for (int i = 0; i < report.size(); i++)
    {
        string t = split(report[i])[1];
        int num = findIndex(accReport, t);
        if (num >= 0)
            accReport[num].second++;
        else
            accReport.push_back(make_pair(t, 1));
    }

    for (int i = 0; i < accReport.size(); i++)
    {
        if (accReport[i].second >= k)
            ban.push_back(accReport[i].first);
    }

    for (int i = 0; i < report.size(); i++)
    {
        string t = split(report[i])[1];
        int num = findIndex(idNum, split(report[i])[0]);
        if (find(ban.begin(), ban.end(), t) != ban.end())
        {
            idNum[num].second++;
        }
    }

    for (int i = 0; i < idNum.size(); i++)
        answer.push_back(idNum[i].second);

    return answer;
}

int main()
{
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
    int k = 2;
    vector<int> answer = solution(id_list, report, k);
    for (const auto t : answer)
        cout << t << ", ";
    return 0;
}