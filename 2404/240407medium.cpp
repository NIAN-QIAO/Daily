//
// Created by PC on 2024/4/7.
//
//1600. 王位继承顺序
#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"
#include "set"
//unordered_map 前序遍历
using namespace std;

class ThroneInheritance {
public:
    unordered_map<string, vector<string>> Tree;
    set<string> dead;
    string root;

    ThroneInheritance(string kingName) {
        Tree[kingName] = vector<string>();
        root = kingName;
    }

    void birth(string parentName, string childName) {
        Tree[parentName].push_back(childName);
        Tree[childName] = vector<string>();
    }

    void death(string name) {
        dead.insert(name);
    }

    void pre_order(string &root, vector<string> &ans) {
        if (!dead.count(root)) ans.push_back(root);
        for (string child: Tree[root]) {
            pre_order(child, ans);
        }

    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        pre_order(root, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */