#include <iostream>
#include <vector>
#include <algorithm> // sort()

using namespace std;

struct Meeting
{
    int start_time;
    int end_time;

    // Meeting(int s, int e) {
    //     s = start_time;
    //     e = end_time;
    // }
    Meeting(int s, int e) : start_time(s), end_time(e) {}
    // Meeting(int start_time, int end_time) : s(start_time), e(end_time){}
};

bool comparing_time(const Meeting &a, const Meeting &b)
{                                   // 두 개의 Meeting 객체를 인자로 받으며, const 참조(const Meeting &a와 const Meeting &b)를 사용하여 객체를 복사하지 않고 비교
    return a.end_time < b.end_time; // 늦게 끝나는 것을 리턴함
}

vector<Meeting> greedy_meeting(vector<Meeting> &meetings)
{
    sort(meetings.begin(), meetings.end(), comparing_time); // end_time 값이 작은 Meeting 객체를 먼저 오게 하여 오름차순으로 정렬
    // 핵심알고리즘 시작 //

    vector<Meeting> selected_meetings;

    if (meetings.empty())
    { // 비어있는 경우
        return selected_meetings;
    }
    // 안비어있다면
    selected_meetings.push_back(meetings[0]);

    int current_time = meetings[0].end_time;

    for (int i = 1; i < meetings.size(); ++i)
    {
        if (meetings[i].start_time >= current_time)
        { // 다음 미팅의 시작시간이 현재 시간보다 늦어야 시작 가능하겠지.
            selected_meetings.push_back(meetings[i]);
            current_time = meetings[i].end_time;
        }
    }
    return selected_meetings;
}

int main()
{
    int n; // n개 회의
    cin >> n;

    vector<Meeting> meetings;
    int start_time, end_time;
    for (int i = 0; i < n; i++)
    {
        cin >> start_time >> end_time;
        meetings.push_back(Meeting(start_time, end_time));
    }
    vector<Meeting> selected_meetings = greedy_meeting(meetings);

    cout << "Selected Meetings:" << endl;
    for (const Meeting &meeting : selected_meetings)
    {
        cout << "Start Time: " << meeting.start_time << ", End Time: " << meeting.end_time << endl;
    }
    return 0;
}
