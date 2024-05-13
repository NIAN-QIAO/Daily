//
// Created by PC on 2024/4/26.
//
#include "unordered_map"
#include "iostream"
#include "vector"
#include "algorithm"
#include "compare"
#include "format"

using namespace std;

class SnapshotArray {
    int cur_snap_id = 0;
    unordered_map<int, vector<pair<int, int>>> history;
public:

    SnapshotArray(int) {

    }

    void set(int index, int val) {
        history[index].emplace_back(cur_snap_id, val);
    }

    int snap() {
        return cur_snap_id++;
    }

    int get(int index, int snap_id) {
        auto &h = history[index];
//        找快照编号<=snap_id 的最后一次修改记录
//等价于找快照便哈》=snap_id + 1的第一个修改记录，他的上一个就是答案
        int j = ranges::lower_bound(h, make_pair(snap_id + 1, 0)) - h.begin() - 1;
        return j >= 0 ? h[j].second : 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */