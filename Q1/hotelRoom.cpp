#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    long long n, m, p;
    const long long ROOF_FLOOR = -100000; // highest floor possible (reverse for lower_bound search (ascending order))
    cin >> n >> m;

    vector<long long> r(n+1); // starts at r[1] (r[0] = 0); stores rooms in each floor
    long long total = 0; // total rooms

    set<pair<long long, long long>> roomFloor; // (room, floor)
    
    for (long long i = 1; i <= n; i++) {
        cin >> r[i];
        total += r[i];
        roomFloor.insert({r[i], -i}); // -floor -> lower_bound finds for highest floor (lowest -floor)
    }

    for (long long i = 0; i < m; i++) {
        cin >> p;

        if (total < p) {
            cout << -1 << "\n";
            continue;
        }

        vector<pair<long long, long long>> reserve; // client reservation order

        while (p > 0) {
            auto it = roomFloor.lower_bound({p, ROOF_FLOOR}); // finds for the lowest available room for all p in one floor (consider highest floor when p tied)
            if (it != roomFloor.end()) { // there is possible value for all p to fit in one floor
                long long floor = -it->second; // get floor + correction from reveresed order

                roomFloor.erase(it); // temporary erase for editing

                reserve.push_back({floor, p}); // add reservation order
                r[floor] -= p; // remove available room in that floor
                total -= p; // remove total available room

                if (r[floor] > 0) { // if room still available in that floor, add back to set
                    roomFloor.insert({r[floor], -floor});
                }

                p = 0; // clears client reservation
            } else { // there is no possible floor with all p available rooms
                auto itLast = prev(roomFloor.end()); // select floor with most available room (positioned at the end of set (ordered_set))
                long long maxRooms = itLast->first; // get max available rooms

                auto itPick = roomFloor.lower_bound({maxRooms, ROOF_FLOOR}); // find the max room available on the highest floor

                // follows the same logic as the first condition
                long long freeRooms = itPick->first;
                long long floor = -itPick->second;

                roomFloor.erase(itPick);

                long long reserved = (freeRooms < p ? freeRooms : p); // reserves the whole floor, if p is more than the entire floor
                reserve.push_back({floor, reserved});
                r[floor] -= reserved;
                total -= reserved;

                if (r[floor] > 0) {
                    roomFloor.insert({r[floor], -floor});
                }

                p -= reserved; // deduct reserved room from total reservation
            }
        }

        sort(reserve.begin(), reserve.end());
        for (auto &x : reserve) {
            cout << x.first << " " << x.second << " ";
        }
        cout << "\n";
    }
}