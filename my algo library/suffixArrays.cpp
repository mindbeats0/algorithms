#include <bits/stdc++.h>
using namespace std;
#define MAXN 65536
#define MAXLG 17
char A[MAXN];
struct entry {
    int l,r,id;
} L[MAXN];
int P[MAXLG][MAXN], N, i, stp, cnt;
int cmp(struct entry a, struct entry b)
{
    return a.l == b.l ? (a.r < b.r ? 1 : 0) : (a.l < b.l ? 1 : 0);
}

int lcp(int x, int y)
{
	int k, ret = 0;
	if (x == y) return N - x;
	for (k = stp - 1; k >= 0 && x < N && y < N; k --)
		if (P[k][x] == P[k][y])
			x += 1 << k, y += 1 << k, ret += 1 << k;
	return ret;
}


int main(void)
{
    gets(A);
    for (N = strlen(A), i = 0; i < N; i ++)
        P[0][i] = A[i] - 'a';
    for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1)
    {
		for (i = 0; i < N; i ++)
		{
			L[i].l = P[stp - 1][i];
			L[i].r = i + cnt < N ? P[stp - 1][i + cnt] : -1;
			L[i].id = i;
		}
		sort(L, L + N, cmp);
		for (i = 0; i < N; i ++)
			P[stp][L[i].id] = i > 0 && L[i].l == L[i - 1].l && L[i].r == L[i - 1].r ?P[stp][L[i - 1].id] : i;
    }
    return 0;
}
