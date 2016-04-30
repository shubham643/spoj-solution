#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#define S 100000
using namespace std;



short int node[3*S], ship[100010], K;

inline int min(int a, int b) { return ( a < b ? a : b ); }
int max(int a, int b) { return ( a > b ? a : b ); }

int updatemin(int id, int lft, int rgt, int val) {
    if ( lft == rgt ) {
        node[id] += val;
        ship[lft] += val;
    }
    else if (node[id<<1] <= K-val ) {
        node[id] = min(updatemin(id<<1, lft, (rgt+lft)/2, val), node[1|(id<<1)]);
    }
    else {
        node[id] = min(updatemin(1|(id<<1), (rgt+lft)/2 + 1, rgt, val), node[id<<1]);
    }

    return node[id];
}

int main(void) {
    /* freopen("input.txt", "r", stdin); */
    int i, ans, T, N, cnt=0, val;
    char s[1024];

    scanf("%d", &T);

    while(T--) {
        scanf("%d\n%d\n", &K, &N);

        for (i=1; i<=3*S; i++) node[i] = 0;
        for (i=1; i<=cnt; i++) ship[i] = 0;

        while(N) {
            fgets(s, 1024, stdin);

            if ( s[0] == 'b' ) {
                sscanf(&s[2], "%d %d", &cnt, &val);
                N -= cnt;

                while(cnt--) updatemin(1, 1, S, val);
            }
            else {
                sscanf(s, "%d", &val);
                N--;

                updatemin(1, 1, S, val);
            }
        }

        ans = 0; cnt = 0;
        for (i=1; ship[i]; i++) {
            ans += K - ship[i];
            cnt++;
        }

        printf("%d %d\n", cnt, ans);
    }

    return 0;
}