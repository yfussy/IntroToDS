#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    std::stack<std::vector<std::queue<int>>> tempStack;
    while (!a.empty()) {    
        for (auto &q : a.top()) {
            std::queue<int> tempQueue;
            while(!q.empty()) {
                if (q.front() == from) {
                    tempQueue.push(to);
                } else {
                    tempQueue.push(q.front());
                }
                q.pop();
            }

            while(!tempQueue.empty()) {
                q.push(tempQueue.front());
                tempQueue.pop();
            }
        }
        tempStack.push(a.top());
        a.pop();
    }

    while (!tempStack.empty()) {
        a.push(tempStack.top());
        tempStack.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    for (auto &[_, pv] : a) {
        auto &[pq, num] = pv;
        if (num == from) num = to;
        std::priority_queue<int> tempPq;
        while (!pq.empty()) {
            if (pq.top() == from) {
                tempPq.push(to);
            } else {
                tempPq.push(pq.top());
            }
            pq.pop();
        }

        while (!tempPq.empty()) {
            pq.push(tempPq.top());
            tempPq.pop();
        }
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{   
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> result;

    for (auto pv : a) {
        for (auto &e : pv.first) {
            if (e == from) e = to;
        }

        std::map<int, std::pair<int, string>> newMap;
        for (auto &[k, v] : pv.second) {
            int newKey = (k == from? to : k);
            if (v.first == from) v.first = to;
            newMap[newKey] = v;
        }
        pv.second = std::move(newMap);
        result.insert(pv);

        
    }

    a.swap(result);
}

#endif
