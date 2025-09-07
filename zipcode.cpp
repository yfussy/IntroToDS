#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Letter{
public:
    string name; string address; string province; string district; int zip;
    bool operator < (const Letter& other) const {
        string fullAddress = address + district + province;
        string otherFullAddress = other.address + other.district + other.province;
        if (zip == other.zip) {
            if (fullAddress == otherFullAddress) {
                return name < other.name;
            }
            return fullAddress < otherFullAddress;
        }
        return zip < other.zip;
    }
};

class ZipInfo{
public:
    int zip;
    string province;
    string district;
};

void correctZipAndSortLetters(vector<ZipInfo>& zipinfo, vector<Letter>& letters) {
    map<pair<string, string>, int> hashZip;
    for (auto &z : zipinfo) {
        hashZip[{z.district, z.province}] = z.zip;
    }

    for (auto &l : letters) {
        int zip = hashZip[{l.district, l.province}];
        if (zip != l.zip) {
            l.zip = zip;
        }
    }


    
    sort(letters.begin(), letters.end());
}

int main() {
    int nzip;
    cin>>nzip;
    vector<ZipInfo> zipinfo;
    for (int i = 0; i < nzip; i++) {
        ZipInfo z;
        cin>>z.zip>>z.district>>z.province;
        zipinfo.push_back(z);
    }
    int n;
    cin>>n;
    vector<Letter> letters;
    for (int i = 0; i < n; i++) {
        Letter l;
        cin>>l.name>>l.address>>l.district>>l.province>>l.zip;
        letters.push_back(l);
    }
    correctZipAndSortLetters(zipinfo, letters);
    for (auto& l:letters) {
        cout<<l.name<<" "<<l.address<<" "<<l.district<<" "<<l.province<<" "<<l.zip<<endl;
    }
}