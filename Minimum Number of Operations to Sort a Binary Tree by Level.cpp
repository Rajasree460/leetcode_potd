/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef int (* PCmp)(const void *, const void *);

int cmp_int_asc(const int * const pThis, const int * const pBase){
	if (*pThis < *pBase){
		return -1;
	}else if (*pThis > *pBase){
		return 1;
	}else {
		return 0;
	}
}

//----------------

#define MAX_VAL ((int)1e5)

int minSwapToMakeUniqueArrAsc(
	int * const nums,
	const int numsLen
){
	assert(numsLen >= 1);

	int numToIdx[1 + MAX_VAL];
	memset(&numToIdx, -1, sizeof (numToIdx));
	for (int i = 0; i < numsLen; i += 1){
		assert((nums[i] >= 0 && nums[i] <= MAX_VAL) &&
			-1 == numToIdx[nums[i]]);
		numToIdx[nums[i]] = i;
	}

	int targetNums[numsLen];
	memcpy(targetNums, nums, sizeof (int) * numsLen);
	qsort(targetNums, numsLen, sizeof (int), (PCmp)&cmp_int_asc);

	int swapCnt = 0;

	for (int i = 0; i < numsLen; i += 1){
		if (nums[i] == targetNums[i]){
			continue;
		}

		swapCnt += 1;

		const int targetIdx = numToIdx[targetNums[i]];
		nums[targetIdx] = nums[i];
		numToIdx[nums[i]] = targetIdx;
	}

	return swapCnt;
}

//----------------

typedef struct TreeNode TreeNode;

#define MAX_NODE ((int)1e5)

int minimumOperations(const TreeNode * const pRoot){
	int opCnt = 0;

	const TreeNode * bfsQueue[MAX_NODE];
	int get = 0, set = 0;

	if (pRoot != NULL){
		bfsQueue[set] = pRoot;
		set += 1;
	}

	while (get < set){
		int numsBuf[MAX_NODE];
		for (int i = 0; get + i < set; i += 1){
			numsBuf[i] = bfsQueue[get + i]->val;
		}
		opCnt += minSwapToMakeUniqueArrAsc(numsBuf, set - get);

		for (int cntDown = set - get; cntDown > 0; cntDown -= 1){
			const TreeNode * const pCur = bfsQueue[get];
			get += 1;

			if (pCur->left != NULL){
				bfsQueue[set] = pCur->left;
				set += 1;
			}
			if (pCur->right != NULL){
				bfsQueue[set] = pCur->right;
				set += 1;
			}
		}
	}

	return opCnt;
}
