/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
    int **res = (int**)malloc(sizeof(int*) * m);
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    *returnSize = m;
    
    for(int i = 0; i < m; i++){
        res[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    char move = 'R';
    int row = 0, col = 0, edge[4] = {n - 1, m - 1, 0, 1};
    for(int grids = m * n, i = 0; i < grids; i++){
        if(head) res[row][col] = head->val, head = head->next;
        else res[row][col] = -1;

        switch(move){
            case 'R':
                if(col < edge[0]) col++;
                else move = 'D', row++, edge[0]--;
                break;
            case 'D':
                if(row < edge[1]) row++;
                else move = 'L', col--, edge[1]--;
                break;
            case 'L':
                if(col > edge[2]) col--;
                else move = 'U', row--, edge[2]++;
                break;
            case 'U':
                if(row > edge[3]) row--;
                else move = 'R', col++, edge[3]++;
                break;
        }
    }

    return res;
}
