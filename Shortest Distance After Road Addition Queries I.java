/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define BIGNUM 1000000

int bellman(int **queries, int k, int n, int iq[n-1][2]);

int* shortestDistanceAfterQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int *ans = (int*) malloc(queriesSize * sizeof(int));
    int i, initQueries[n-1][2];
    for (i = 0; i < n-1; ++i) {
        initQueries[i][0] = i;
        initQueries[i][1] = i+1;
    }
    for (i = 0; i < queriesSize; ++i) {
        ans[i] = bellman(queries, i, n, initQueries);
    }
    *returnSize = queriesSize;
    return ans;
}

int bellman(int **queries, int k, int n, int iq[n-1][2]) {
    bool changed = true;
    int i, dist[n];
    dist[0] = 0;
    for (i = 1; i < n; ++i) dist[i] = BIGNUM;
    while (changed) {
        changed = false;
        for (i = 0; i < n-1; ++i) {
            if (dist[iq[i][0]] + 1 < dist[iq[i][1]]) {
                dist[iq[i][1]] = dist[iq[i][0]] + 1;
                changed = true;
            }
        }
        for (i = 0; i <= k; ++i) {
            if (dist[queries[i][0]] + 1 < dist[queries[i][1]]) {
                dist[queries[i][1]] = dist[queries[i][0]] + 1;
                changed = true;
            }
        }
    }
    return dist[n-1];
}
