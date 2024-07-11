#include <bits/stdc++.h>
using namespace std;

// Interval structure
struct Interval {
    int start, end, index;
    bool contains = false;
    bool isContained = false;
};

// Comparison function for sorting
bool compareIntervals(const Interval &a, const Interval &b) {
    if (a.start == b.start) return a.end > b.end;
    return a.start < b.start;
}

int main() {
    int n;
    cin >> n;
    vector<Interval> intervals(n);

    // Reading input intervals
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].start >> intervals[i].end;
        intervals[i].index = i;
    }

    // Sorting intervals
    sort(intervals.begin(), intervals.end(), compareIntervals);

    // Max-heap to keep track of the largest end point seen so far
    priority_queue<pair<int, int>> pq;

    // Check for contains
    for (int i = 0; i < n; ++i) {
        while (!pq.empty() && pq.top().second < intervals[i].start) {
            pq.pop();
        }
        if (!pq.empty() && pq.top().first >= intervals[i].end) {
            intervals[i].isContained = true;
        }
        pq.push({intervals[i].end, intervals[i].start});
    }

    // Clear the priority queue for reuse
    while (!pq.empty()) pq.pop();

    // Check for isContained
    for (int i = n - 1; i >= 0; --i) {
        while (!pq.empty() && pq.top().second > intervals[i].end) {
            pq.pop();
        }
        if (!pq.empty() && pq.top().first <= intervals[i].start) {
            intervals[i].contains = true;
        }
        pq.push({intervals[i].start, intervals[i].end});
    }

    // Output results
    vector<int> containsResults(n), isContainedResults(n);
    for (const auto &interval : intervals) {
        containsResults[interval.index] = interval.contains;
        isContainedResults[interval.index] = interval.isContained;
    }

    for (int res : containsResults) {
        cout << res << " ";
    }
    cout << endl;
    for (int res : isContainedResults) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
