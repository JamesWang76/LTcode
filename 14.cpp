#include <stdio.h>

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
 * Compare with each string, and update the lcp each iteration.
 * 
 * Faster than 94.9%, memory usage 100%
 */ 


string longestCommonPrefix(vector<string>& strs);

int main() {
    string data[] = {"asdf"};
    vector<string> vdata;

    for (int i = 0; i < (int)sizeof(data) / sizeof(data[0]); i++) {
        vdata.push_back(data[i]);
    }
    longestCommonPrefix(vdata);
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";

    string lcp = strs[0], tmp_lcp;
    int j;
    for (int i = 1; i < (int)strs.size(); i++) {
        tmp_lcp = "";
        j = 0;
        while (lcp[j] || strs[i][j]) {
            if (lcp[j] == strs[i][j])
                tmp_lcp += strs[i][j];
            else {
                break;
            }
            j++;
        }
        lcp = tmp_lcp;
    }
    return lcp;
}