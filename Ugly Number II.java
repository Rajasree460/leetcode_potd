class Solution {
    public int nthUglyNumber(int n) {

      //array to store the 1st 10 ugly nos
      int[] uglyno=new int[n];
      uglyno[0]=1; //first ugly no=1

      //pointers for multiple of 2,3 & 5
      int p2=0,p3=0,p5=0;  //decides with which ele 2,3 or 5 will be multiplied

    //initialize miltiple of 2, 3 or 5
    int next2=2;  //for tracking & storing purpose
    int next3=3;
    int next5=5;
    
    //generate ugly nos upto nth one
    for(int i=1;i<n;i++){
        //find the next ugly no.
        int nextugly=Math.min(next2,Math.min(next3,next5));
        uglyno[i]=nextugly; //add the no to the existing array

        //update pointers
        if(nextugly==next2){
            p2++;
            next2=uglyno[p2]*2;
        }
        if(nextugly==next3){
            p3++;
            next3=uglyno[p3]*3;
        }
        if(nextugly==next5){
            p5++;
            next5=uglyno[p5]*5;
        }
    }

    //nth ugly no is the last ele of the array
    return uglyno[n-1];
    }
}


// ### Example: Finding the 10th Ugly Number (`n = 10`)

// #### Initialization:
// - `uglyno[] = [1]` (array to store the first `n` ugly numbers)
// - `p2 = 0`, `p3 = 0`, `p5 = 0` (pointers for multiples of 2, 3, and 5)
// - `next2 = 2`, `next3 = 3`, `next5 = 5` (initialize multiples of 2, 3, and 5)

// #### Iterations:

// 1. **Iteration 1**:
//    - Smallest `nextugly = min(2, 3, 5) = 2`
//    - Update: `uglyno[] = [1, 2]`
//    - Move `p2` forward: `p2 = 1`, `next2 = uglyno[1] * 2 = 2 * 2 = 4`

// 2. **Iteration 2**:
//    - Smallest `nextugly = min(4, 3, 5) = 3`
//    - Update: `uglyno[] = [1, 2, 3]`
//    - Move `p3` forward: `p3 = 1`, `next3 = uglyno[1] * 3 = 2 * 3 = 6`

// 3. **Iteration 3**:
//    - Smallest `nextugly = min(4, 6, 5) = 4`
//    - Update: `uglyno[] = [1, 2, 3, 4]`
//    - Move `p2` forward: `p2 = 2`, `next2 = uglyno[2] * 2 = 3 * 2 = 6`

// 4. **Iteration 4**:
//    - Smallest `nextugly = min(6, 6, 5) = 5`
//    - Update: `uglyno[] = [1, 2, 3, 4, 5]`
//    - Move `p5` forward: `p5 = 1`, `next5 = uglyno[1] * 5 = 2 * 5 = 10`

// 5. **Iteration 5**:
//    - Smallest `nextugly = min(6, 6, 10) = 6`
//    - Update: `uglyno[] = [1, 2, 3, 4, 5, 6]`
//    - Move `p2` and `p3` forward:
//      - `p2 = 3`, `next2 = uglyno[3] * 2 = 4 * 2 = 8`
//      - `p3 = 2`, `next3 = uglyno[2] * 3 = 3 * 3 = 9`

// 6. **Iteration 6**:
//    - Smallest `nextugly = min(8, 9, 10) = 8`
//    - Update: `uglyno[] = [1, 2, 3, 4, 5, 6, 8]`
//    - Move `p2` forward: `p2 = 4`, `next2 = uglyno[4] * 2 = 5 * 2 = 10`

// 7. **Iteration 7**:
//    - Smallest `nextugly = min(10, 9, 10) = 9`
//    - Update: `uglyno[] = [1, 2, 3, 4, 5, 6, 8, 9]`
//    - Move `p3` forward: `p3 = 3`, `next3 = uglyno[3] * 3 = 4 * 3 = 12`

// 8. **Iteration 8**:
//    - Smallest `nextugly = min(10, 12, 10) = 10`
//    - Update: `uglyno[] = [1, 2, 3, 4, 5, 6, 8, 9, 10]`
//    - Move `p2` and `p5` forward:
//      - `p2 = 5`, `next2 = uglyno[5] * 2 = 6 * 2 = 12`
//      - `p5 = 2`, `next5 = uglyno[2] * 5 = 3 * 5 = 15`

// 9. **Iteration 9**:
//    - Smallest `nextugly = min(12, 12, 15) = 12`
//    - Update: `uglyno[] = [1, 2, 3, 4, 5, 6, 8, 9, 10, 12]`
//    - Move `p2` and `p3` forward:
//      - `p2 = 6`, `next2 = uglyno[6] * 2 = 8 * 2 = 16`
//      - `p3 = 4`, `next3 = uglyno[4] * 3 = 5 * 3 = 15`

// #### Conclusion:
// At the end of these 9 iterations (plus the initial ugly number 1), the `uglyno` array contains:

// \[ \text{uglyno[]} = [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] \]

// Thus, the 10th ugly number is **12**.

