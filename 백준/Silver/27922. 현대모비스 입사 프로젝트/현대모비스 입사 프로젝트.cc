#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> ab, bc, ac;
    
    for(int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ab.push_back(a + b);
        bc.push_back(b + c);
        ac.push_back(a + c);
    }
    
    // 각 경우별로 내림차순 정렬
    sort(ab.begin(), ab.end(), greater<int>());
    sort(bc.begin(), bc.end(), greater<int>());
    sort(ac.begin(), ac.end(), greater<int>());
    
    long long sum_ab = 0, sum_bc = 0, sum_ac = 0;
    
    // 각각 상위 K개씩 더하기
    for(int i = 0; i < K; i++) {
        sum_ab += ab[i];
        sum_bc += bc[i];
        sum_ac += ac[i];
    }
    
    // 세 경우 중 가장 큰 값이 정답
    cout << max({sum_ab, sum_bc, sum_ac});
    
    return 0;
}