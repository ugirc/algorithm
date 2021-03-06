// 高精度 X 低精度
#include <iostream>
#include <vector>

using namespace std;

vector <int> mul(vector <int> & A, int b) {
    vector <int> C;

    int t = 0;
    for (int i = 0; i < A.size(); i ++) {
        t += A[i] * b;       // t + A[i] * b = 7218
        C.push_back(t % 10); // 只取个位 8
        t /= 10;             // 721 看作 进位
    }
    
    while (t) {            // 处理最后剩余的 t
        C.push_back(t % 10);
        t /= 10;
    }
    
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    
    return C;
}

int main() {
    string a;
    int b;
    cin >> a >> b;

    vector <int> A;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');

    auto C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; i --) {
        cout << C[i];
    }

    return 0;
}