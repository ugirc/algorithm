/*
	2019年11月3日 星期日
	AC: /4
*/

/// 5247. Minimum Swaps to Make Strings Equal
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x1 = 0, x2 = 0;
        int n = s1.size(), cnt = 0;
        for (int i = 0; i < n; i ++) {
            if (s1[i] != s2[i]) {
                if (s1[i] == 'x') x1 ++;
                if (s2[i] == 'x') x2 ++;
            }
        }

        if ((x1 - x2) & 1) return -1;

        if (x1 & 1 ) {
            if (max(x1, x2) == 1) return 2;
            else return (x1 + x2 - 1) / 2 + 2;
        }

        return (x1 + x2) / 2;
    }
};

