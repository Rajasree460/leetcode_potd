/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // A structure to hold node details like height and level
struct NodeInfo {
    int height;
    int level;
};

// A structure to hold level details, the two highest heights at each level
struct LevelInfo {
    int maxHeight;
    int secondMaxHeight;
};

// HashMap replacement: dynamically allocated arrays for nodes and levels
struct NodeInfo* nodeMap[100001]; // Assuming max node values <= 100000
struct LevelInfo* levelMap[100001]; // Assuming reasonable level count

// DFS helper function
int dfs(struct TreeNode* root, int level) {
    if (root == NULL) return 0;

    int left = dfs(root->left, level + 1);
    int right = dfs(root->right, level + 1);
    int height = (left > right) ? left : right;

    // Store level information
    if (levelMap[level] == NULL) {
        levelMap[level] = (struct LevelInfo*)malloc(sizeof(struct LevelInfo));
        levelMap[level]->maxHeight = -1;
        levelMap[level]->secondMaxHeight = -1;
    }

    if (height >= levelMap[level]->maxHeight) {
        levelMap[level]->secondMaxHeight = levelMap[level]->maxHeight;
        levelMap[level]->maxHeight = height;
    } else if (height > levelMap[level]->secondMaxHeight) {
        levelMap[level]->secondMaxHeight = height;
    }

    // Store node information
    nodeMap[root->val] = (struct NodeInfo*)malloc(sizeof(struct NodeInfo));
    nodeMap[root->val]->height = height;
    nodeMap[root->val]->level = level;

    return height + 1;
}

int* treeQueries(struct TreeNode* root, int* queries, int queriesSize, int* returnSize) {
    *returnSize = queriesSize;

    int maxDepth = dfs(root, 0) - 1;
    int* results = (int*)malloc(queriesSize * sizeof(int));

    for (int i = 0; i < queriesSize; i++) {
        int q = queries[i];
        struct NodeInfo* node = nodeMap[q];
        int height = node->height;
        int level = node->level;
        struct LevelInfo* lev = levelMap[level];

        if (lev->maxHeight == height) {
            if (lev->secondMaxHeight != -1) {
                results[i] = maxDepth - abs(lev->maxHeight - lev->secondMaxHeight);
            } else {
                results[i] = maxDepth - height - 1;
            }
        } else {
            results[i] = maxDepth;
        }
    }

    // Free allocated memory for maps
    for (int i = 0; i < 100001; i++) {
        if (nodeMap[i] != NULL) {
            free(nodeMap[i]);
            nodeMap[i] = NULL;
        }
        if (levelMap[i] != NULL) {
            free(levelMap[i]);
            levelMap[i] = NULL;
        }
    }

    return results;
}
