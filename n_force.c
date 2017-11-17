/**
 * Example usage:
 *
 * $ ./n_force 3 4
 *            *
 *           ***
 *          *****
 *         *     *
 *        ***   ***
 *       ***** *****
 *      *     *     *
 *     ***   ***   ***
 *    ***** ***** *****
 *   *     *     *     *
 *  ***   ***   ***   ***
 * ***** ***** ***** *****
 *
 *
 * Solution used:               
 *                                  
 * o----> i
 * |                1111111111222
 * |      01234567890123456789012
 * |    +------------------------
 * |  0 | <<<>>><<<oo*            \
 * v  1 | <<<>>><<<o***           | k=0     
 *    2 | <<<>>><<<*****__________/
 * j  3 | >>><<<oo*ooooo*         \
 *    4 | >>><<<o***ooo***        | k=1 
 *    5 | >>><<<*****o*****_______/
 *    6 | <<<oo*ooooo*ooooo*      \
 *    7 | <<<o***ooo***ooo***     | k=2
 *    8 | <<<*****o*****o*****____/
 *    9 | oo*ooooo*ooooo*ooooo*   \
 *   10 | o***ooo***ooo***ooo***  | k=3
 *   11 | *****o*****o*****o*****_/
 *
 *
 *   Symbols:
 *
 *     <<< >>>   
 *     <<< >>> = Empty blocks before triangle groups. 
 *     <<<,>>>
 *     
 *        o    = Whitespace (inivsible).
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./test <TRIANGLE_HEIGHT> <NUM_TRIANGLES>\n"); 
        return 1;
    }
    const int h = atoi(argv[1]);  // Triangle height.
    const int n = atoi(argv[2]);  // Number of triangles.

    const int max_height = h * n; // The maximum value of "j".

    int i, j, k, l, m;
    int empty_blocks = 0; // Number of "empty" square blocks before the triangles.

    for (j = 0; j < max_height; ++j) {

        k = (j / h);

        // Calculate how many empty blocks there are.
        empty_blocks = (j == 0) ? (n - 1) : ((n - 1) - k);
        
        // Draw the first triangle in the row.
        for (i = 0; i < max_height + j; ++i) {
            if (i < (empty_blocks * h) + (2 * h)) {
                if ((i > (empty_blocks * h) + (h - (j % h) - 2)) &&
                    (i < (empty_blocks * h) + (h + (j % h)    )))
                    printf("*");
                else
                    printf(" ");
            }
        }

        // Draw all the other triangles in the row.
        for (l = 0; l < k; ++l) {
            for (m = 0; m < 2 * h; ++m) {
                if ((m > h - (j % h) - 2) && (m < h + (j % h))) 
                    printf("*");
                else if (l < k - 1 || m < h)
                    printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}

