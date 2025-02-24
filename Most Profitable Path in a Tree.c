struct node {
    int val;
    struct node *next;
};

void add_neighbor(struct node **g, int u, int v) {
    
    struct node *n = malloc(sizeof(struct node));
    struct node *head = g[u];
    g[u] = n;
    n->val = v;
    n->next = head;
}

int mostProfitablePath(int** edges, int edgesSize, int* edgesColSize, int bob, int* amount, int amountSize) {
    // form the graph.
    struct node **g = calloc(amountSize, sizeof(void *));
    int u, v;
    for (int i = 0; i < edgesSize; i++) {
        u = edges[i][0];
        v = edges[i][1];

        add_neighbor(g, u, v); // THIS IS THE BOTTLENECK
        add_neighbor(g, v, u);
    }

    int *parents = calloc(amountSize, sizeof(int));
    int *stack = calloc(amountSize, sizeof(int));
    int j = 0;
    struct node *curr;
    while (j >= 0) {
        u = stack[j--];
        curr = g[u];
        while (curr) {
            v = curr->val;
            if (v != parents[u]) {
                // remove_neighbor(g, v, u); // remove u fron g[v]
                stack[++j] = v;
                parents[v] = u;
            }
            
            curr = curr->next;
        }
    }

    // get path length to bob
    int pathlen = 1, *path = calloc(amountSize, sizeof(int));
    path[0] = bob;
    while (parents[bob] != bob) {
        path[pathlen++] = parents[bob];
        bob = parents[bob];
    }

    // for (j=0; j<pathlen; j++) {
    //     printf("path[%d] = %d\n", j, path[j]);
    // }

    // modify amounts
    j = 0;
    while (pathlen > 0) {
        if (pathlen == 1) {
            amount[path[j]] >>= 1; // since amounts are even
        } else {
            amount[path[j]] = 0;
        }
        // printf("amount[%d] = %d\n", j, amount[j]);
        j++; pathlen -= 2;
    }

    // propogate ans
    j = 0; stack[0] = 0;
    bool leaf, first = 1;
    int ans = 0;
    while (j >= 0) {
        u = stack[j--];
        leaf = 1;
        curr = g[u];
        while (curr) {
            v = curr->val;
            if (v != parents[u]) {
                stack[++j] = v;
                amount[v] += amount[u];
                leaf = 0;
            }
            curr = curr->next;
        }
        if (leaf) {
            if (first) {
                first = 0;
                ans = amount[u];
            } else if (ans < amount[u]) {
                ans = amount[u];
            }
        }
    }
    free(stack);
    free(parents);
    free(path);
    // destroy g
    return ans;
}
