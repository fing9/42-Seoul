#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <utility>
#include <bitset>
#include <unistd.h>

#define FAST ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define D_MAX 2147483647
#define LL_MAX 9223372036854775807
#define MAX 1000000001
#define MIN -1000000001
#define ll long long
#define ull unsigned long long
#define GRAPH vector<vector<pair<int, int>>>
#define CCW_MAX 1004


using namespace std;

// first, second, next의 각을 계산
ll ccw(const pair<int,int> &A, const pair<int,int> &B, const pair<int,int> &C) {
    return ((A.first * B.second) + (B.first * C.second) + (C.first * A.second) - (B.first * A.second) - (C.first * B.second) - (A.first * C.second));
}

double dist(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

vector<pair<int,int>> convex_hull(vector<pair<int,int>> v) {
    // y좌표, x좌표 순으로 오름차순 정렬
    swap(v[0], *min_element(v.begin(), v.end()));

    // 반시계 반향으로 정렬(기준점 0을 제외)
    sort(v.begin() + 1, v.end(), [&](const pair<int,int> &A, const pair<int,int> &B){
        auto c = ccw(v[0], A, B);
        if(c) return c > 0;
        return dist(v[0], A) < dist(v[0], B);
    });

    vector<pair<int,int>> ret;
    for(const auto &i : v){
        while(ret.size() >= 2 && ccw(ret[ret.size()-2], ret.back(), i) <= 0) ret.pop_back();
        ret.push_back(i);
    }
    return ret;
}

int main() {
    ll t;

    scanf("%lld", &t);
    while (t--) {
        vector<pair<int,int>> v;
        long long a, b;
        scanf("%lld %lld", &a, &b);
        pair<int,int> sh = pair<int,int>(a, b); // 승혁이의 시작위치
        scanf("%lld %lld", &a, &b);
        pair<int,int> ex = pair<int,int>(a, b); // 탈출구의 위치
        ll N;
        scanf("%lld", &N);

        for (ll i=0;i<N;i++) {
            ll x, y;
            
            scanf("%lld %lld", &x, &y);
            v.push_back({x,y});
        }
        
        // 악동이 1명이거나 2명이면 무조건 승훈과 탈출구를 포함하는 컨벡스헐을 구성할 수 있음
        // 악동들만을 가지고 convex hull을 구성한다.
        v = convex_hull(v);
        N = v.size();

        // 악동들의 convex hull안에 승혁이가 있다면 INPOSSIBLE
        bool is_outer1 = false;
        for (int i=0;i<N;i++) {
            int j = i + 1 == N ? 0 : i + 1; // 시작과 끝 잇기
            // 승훈이가 볼록 껍질의 밖에 존재한다면
            if (ccw(v[i], v[j], sh) <= 0) {
                is_outer1 = true;
                break;
            }
        }
        if (!is_outer1) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        // 악동들의 convex hull안에 exit가 있다면 INPOSSIBLE
        bool is_outer2 = false;
        for (int i=0;i<N;i++) {
            int j = i + 1 == N ? 0 : i + 1; // 시작과 끝 잇기
            // exit가 볼록 껍질의 밖에 존재한다면
            if (ccw(v[i], v[j], ex) <= 0) {
                is_outer2 = true;
                break;
            }
        }
        if (!is_outer2) {
            printf("IMPOSSIBLE\n");
            continue;
        }

        // 승훈이와 탈출구도 포함
        v.push_back(sh);
        v.push_back(ex);
        // 모두를 가지고 convex hull을 구성한다.
        v = convex_hull(v);
        N = v.size();

        // 승훈이와 탈출구의 인덱스를 구한다.
        // 예외 케이스
        int i, j;
        for (i=1; i<=N && ccw(v[i-1], v[i%N], sh)>0; i++);
        for (j=1; j<=N && ccw(v[j-1], v[j%N], ex)>0; j++);
        if (i==j || i>N || j>N) {
            printf("%.3lf\n", dist(sh, ex));
            continue;
        }
        i %= N;
        j %= N;

        //컨벡스헐을 따라서 두 점을 잇는 최소 길이를 구한다.
        double conv_len1 = dist(sh, v[i]) + dist(ex, v[(j == 0 ? N-1 : j-1)]);
        double conv_len2 = dist(sh, v[(i == 0 ? N-1 : i-1)]) + dist(ex, v[j]);
        for (ll k = i;k!=(j == 0 ? N-1 : j-1);k = (k+1 == N ? 0 : k+1)) {
            conv_len1 += dist(v[k], v[(k+1 == N ? 0 : k+1)]);
        }
        for (ll k = j;k!=(i == 0 ? N-1 : i-1);k = (k+1 == N ? 0 : k+1)) {
            conv_len2 += dist(v[k], v[(k+1 == N ? 0 : k+1)]);
        }

        printf("%.3lf\n", min(conv_len1, conv_len2));
    }

    return 0;
}
