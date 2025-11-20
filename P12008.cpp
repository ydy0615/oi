#include <bits/stdc++.h>
using namespace std;

int compute_end(int start_p, int m, int x, const vector<int>& a, const vector<vector<int>>& f, const vector<vector<int>>& pos, int V) {
	if (m == 1) return start_p;
	int cur_pos = start_p;
	int cur_v = x;
	int additional = m - 1;
	for (int d = 20; d >= 0; --d) {
		if ((additional & (1 << d)) == 0) continue;
		int nv = cur_v + 1;
		if (nv > V) return -1;
		const auto& pv = pos[nv];
		auto it = lower_bound(pv.begin(), pv.end(), cur_pos + 1);
		if (it == pv.end()) return -1;
		int q = *it;
		int jump_end = f[q][d];
		if (jump_end == -1) return -1;
		cur_pos = jump_end;
		cur_v += (1 << d);
	}
	return cur_pos;
}

bool can_do(int x, int m, const vector<int>& starts, const vector<int>& max_chain, const vector<int>& a, const vector<vector<int>>& f, const vector<vector<int>>& pos, int k, int V) {
	if (m == 0) return true;
	int s = starts.size();
	int l = 0;
	int prev_end = -1;
	int count = 0;
	while (count < k && l < s) {
		int p = starts[l];
		if (max_chain[p] < m) {
			++l;
			continue;
		}
		if (p <= prev_end) {
			++l;
			continue;
		}
		int endp = compute_end(p, m, x, a, f, pos, V);
		if (endp == -1) {
			++l;
			continue;
		}
		prev_end = endp;
		++count;
		++l;
	}
	return count >= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, V;
	cin >> n >> k >> V;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<vector<int>> pos(V + 2);
	for (int i = 0; i < n; ++i) {
		pos[a[i]].push_back(i);
	}
	const int LOG = 21;
	vector<vector<int>> f(n, vector<int>(LOG, -1));
	for (int i = 0; i < n; ++i) {
		f[i][0] = i;
	}
	for (int d = 1; d < LOG; ++d) {
		for (int i = 0; i < n; ++i) {
			int mid_pos = f[i][d - 1];
			if (mid_pos == -1) continue;
			int next_v = a[i] + (1 << (d - 1));
			if (next_v > V) continue;
			const auto& pv = pos[next_v];
			auto it = lower_bound(pv.begin(), pv.end(), mid_pos + 1);
			if (it == pv.end()) continue;
			int q = *it;
			int endp = f[q][d - 1];
			if (endp != -1) {
				f[i][d] = endp;
			}
		}
	}
	vector<int> max_chain(n, 1);
	for (int i = 0; i < n; ++i) {
		int cur_pos = i;
		int cur_v = a[i];
		int matched = 1;
		for (int dd = LOG - 1; dd >= 0; --dd) {
			int nv = cur_v + 1;
			if (nv > V) break;
			const auto& pv = pos[nv];
			auto it = lower_bound(pv.begin(), pv.end(), cur_pos + 1);
			if (it == pv.end()) continue;
			int qq = *it;
			if (f[qq][dd] != -1) {
				cur_pos = f[qq][dd];
				cur_v += (1 << dd);
				matched += (1 << dd);
				max_chain[i] = matched;
			}
		}
	}
	vector<int> ans(V + 1, 0);
	for (int x = 1; x <= V; ++x) {
		const auto& starts = pos[x];
		int ss = starts.size();
		if (ss < k) continue;
		int max_pos = 0;
		for (int p : starts) {
			max_pos = max(max_pos, max_chain[p]);
		}
		int low = 1;
		int high = min(n / k, max_pos);
		int res = 0;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (can_do(x, mid, starts, max_chain, a, f, pos, k, V)) {
				res = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		ans[x] = res;
	}
	for (int x = 1; x <= V; ++x) {
		if (x > 1) cout << ' ';
		cout << ans[x];
	}
	cout << '\n';
	return 0;
}