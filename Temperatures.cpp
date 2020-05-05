#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>     /* abs */

using namespace std;

int main()
{
    vector<int> vTplus;
    vector<int> vTminus;
    bool zero = false;
    
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        
        if(t == 0)      zero = true;
        else if(t > 0)  vTplus.push_back(t);
        else            vTminus.push_back(t);
    }
    
    if(zero) cout << "0" << endl;   // no need to go further
    else if(vTplus.size() == 0 && vTminus.size() == 0) cout << "0" << endl; // if no T + no need to go further
    else {
        int tPlus;
        int tMinus;
        
        if(vTplus.size() != 0) {
            vector<int>::iterator resultPlus  = min_element(begin(vTplus), end(vTplus));
            tPlus  = vTplus[distance(begin(vTplus), resultPlus)];
        }
        
        if(vTminus.size() != 0) {
            vector<int>::iterator resultMinus = max_element(begin(vTminus), end(vTminus));
            tMinus = vTminus[distance(begin(vTminus), resultMinus)];
        }
        
        if(vTplus.size() != 0 && vTminus.size() == 0) cout << tPlus << endl;    // no t < 0
        if(vTplus.size() == 0 && vTminus.size() != 0) cout << tMinus << endl;   // no t > 0
        
        else if(tPlus == abs(tMinus)) cout << tPlus << endl;
        else {
            tPlus > abs(tMinus) ? cout << tMinus << endl : cout << tPlus << endl;
        }
    }
}