#include <iostream>

using namespace std;

int lt, md, rt;

int pv_max[3];
int cr_max[3];

int pv_min[3];
int cr_min[3];

int N;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> lt >> md >> rt;

	pv_max[0] = lt;
	pv_max[1] = md;
	pv_max[2] = rt;

	pv_min[0] = lt;
	pv_min[1] = md;
	pv_min[2] = rt;

	if (N == 1) {
		cr_max[0] = lt;
		cr_max[1] = md;
		cr_max[2] = rt;

		cr_min[0] = lt;
		cr_min[1] = md;
		cr_min[2] = rt;
	}
	for (int i = 1; i < N; i++) {
		cin >> lt >> md >> rt;

		cr_max[0] = max(pv_max[0], pv_max[1]) + lt;
		cr_max[1] = max(max(pv_max[0], pv_max[1]), pv_max[2]) + md;
		cr_max[2] = max(pv_max[1], pv_max[2]) + rt;

		cr_min[0] = min(pv_min[0], pv_min[1]) + lt;
		cr_min[1] = min(min(pv_min[0], pv_min[1]), pv_min[2]) + md;
		cr_min[2] = min(pv_min[1], pv_min[2]) + rt;

		for (int j = 0; j < 3; j++) {
			pv_max[j] = cr_max[j];
			pv_min[j] = cr_min[j];
		}
	}
	int max_ans = max(max(cr_max[0], cr_max[1]), cr_max[2]);
	int min_ans = min(min(cr_min[0], cr_min[1]), cr_min[2]);

	cout << max_ans << ' ' << min_ans;

	return 0;
}