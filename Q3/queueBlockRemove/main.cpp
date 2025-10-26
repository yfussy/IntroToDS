#include "queue.h"
#include "student.h"
#include <iostream>

using std::cin;
using std::cout;

int main() {
    std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    std::string s;
    CP::queue<int>q;
    CP::queue<std::string>q2;
    int type;
    cin >> type;
    long long qy=0;
    while(true) {
        qy++;
        cin >> s;
        if(s[0] == 's') {
            if(type==1)
            cout << q.size() << '\n';
            else
            cout << q2.size() << '\n';
        }
        else if(s[0] == 'u') {
            int X;
            std::string P;
            if(type==1) {
                cin >> X;
                q.push(X);
            }
            else {
                cin >> P;
                q2.push(P);
            }
        }
        else if(s[0] == 'o') {
            if(type==1)
            q.pop();
            else
            q2.pop();
        }
        else if(s[0] == 'f') {
            if(type==1)
            cout << q.front() << '\n';
            else
            cout << q2.front() << '\n';
        }
        else if(s[0] == 'B') {
            int X, Y;
            cin >> X >> Y;
            if(type==1)
            q.block_remove(X, Y);
            else
            q2.block_remove(X, Y);
        }
        else if(s[0] == 'q') {
            break;
        }
        else if(s[0] == 'b') {
            if(type==1)
            cout << q.back() << '\n';
            else
            cout << q2.back() << '\n';
        }
        else if(s[0] == 'x') {
            int N,X;
            std::string P;
            if(type==1) {
                cin >> N >> X;
                for(int i = 0;i < N;i++) {
                    q.push(X+i);
                }
            }
            else {
                P.clear();
                cin >> N >> P;
                for(long long i = 0;i < N;i++) {
                    std::string P2 = P;
                    for(long long j = 0;j < P.size();j++) {
                        long long tar = (j+qy+i)%26;
                        P2[j] += tar;
                        while(P2[j] > 'Z' && P2[j] < 'a')
                        P2[j] -= 26;
                        while(P2[j] > 'z')
                        P2[j] -= 26;
                        while(P2[j] < 'A')
                        P2[j] += 26;
                    }
                    q2.push(P2);
                }
            }
        }
    }
    cout << "Key :" << "anfrdejohoedinbd" << '\n';
}