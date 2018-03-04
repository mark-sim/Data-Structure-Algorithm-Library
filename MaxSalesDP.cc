#include <iostream>
#include <algorithm>


int main() {
    int N = 5;
    int M = 10;
    int S[6][11] = {0}; /* initialize all array to 0 first */
    int P[5] = {1,2,3,7,9}; /* original price */
    int PP[5] = {5, 11, 15, 20, 10}; /* sales price */

    //base case
    for(int i=0; i<=N; i++) {
        S[i][0] = 0;
    }

    for(int j=0; j<=M; j++) {
        S[0][j] = j;
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            std::cout << "i:" << i << " j:" << j << std::endl;
            for(int q=0; q<=(j/P[i-1]); q++) {
                S[i][j] = std::max(S[i][j], S[i-1][j-q*P[i-1]] + q * (PP[i-1] - P[i-1]));
            }
        }
    }

    std::cout << S[N][M] << std::endl;
}
