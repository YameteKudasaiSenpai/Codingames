#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    // game loop
    while (1) {
        
        vector<int> vMountainH;
        
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of one mountain.
            cin >> mountainH; cin.ignore();
            vMountainH.push_back(mountainH);
        }
        cout << max_element(vMountainH.begin(),vMountainH.end()) - vMountainH.begin() << endl;
    }
}