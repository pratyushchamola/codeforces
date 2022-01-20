#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

const int INF = int(1e9);

int H,W;
int x1, yone, x2, y2;
int w, h;

// inline bool read() {
// 	if(!(cin >> W >> H))
// 		return false;
// 	cin >> x1 >> yone >> x2 >> y2;
// 	cin >> w >> h;
// 	return true;
// }

void solve() {
    int t; cin >> t;
	while(t--) {
    cin >> W >> H;
    cin >> x1 >> yone >> x2 >> y2;
	cin >> w >> h;
	int ans = INF;
	if ((x2 - x1 + w) <= W) {
		ans = min(ans, max(0, w - x1));
		ans = min(ans, max(0, x2 - (W - w)));
	}
	if ((y2 - yone + h) <= H) {
		ans = min(ans, max(0, h - yone));
		ans = min(ans, max(0, y2 - (H - h)));
	}
	if (ans == INF)
		cout << -1 << endl;
	else
		cout << double(ans) << endl;
    
    }
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif	
	cout << fixed << setprecision(9);
	// int t; cin >> t;
	// while(t--) {
		// (read());
        // cin >> W >> H;
        // cin >> x1 >> yone >> x2 >> y2;
	    // cin >> w >> h;
		solve();
	// }
	return 0;
}