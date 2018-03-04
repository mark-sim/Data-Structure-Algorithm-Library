#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string dna1; 
	string dna2;
	int gapPenalty;
	int mismatchPenalty;

	getline(cin, dna1);
	getline(cin, dna2);

	cin >> gapPenalty;
	cin >> mismatchPenalty; 

	int m = dna1.length();
	int n = dna2.length();
	int mismatchPenaltyTemp = mismatchPenalty;

	int A[m+1][n+1] = {0}; /* initialize the 2D array to all 0 */

	/* start sequenceAlignmentDP here */

	/* base case: if one of the dna is empty, then 
	it must be the length of the non-empty dna * gapPenalty */
	for(int i=1; i<=m; i++) {
		A[i][0] = i * gapPenalty;
	}

	for(int i=1; i<=n; i++) {
		A[0][i] = i * gapPenalty;
	}

	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(dna1[i-1] == dna2[j-1]) {
				mismatchPenaltyTemp = 0;
			} else {
				mismatchPenaltyTemp = mismatchPenalty;
			}
			A[i][j] = min(min(A[i-1][j-1] + mismatchPenaltyTemp, A[i-1][j] + gapPenalty), A[i][j-1] + gapPenalty);
		}
	}

	/* backtrace to get the actual alignment : dna X and Y */

	int i = m;
	int j = n;
	string x = "";
	string y = "";
	string verticalLine = "";

	while(i > 0 && j > 0) {
		int target = A[i][j];
		if(dna1[i-1] == dna2[j-1]) {
			mismatchPenaltyTemp = 0;
		} else {
			mismatchPenaltyTemp = mismatchPenalty;
		}
		if(A[i-1][j-1] + mismatchPenaltyTemp == target) {
			x = dna1[i-1] + x;
			y = dna2[j-1] + y;
			if(dna1[i-1] == dna2[j-1]) {
				verticalLine = "|" + verticalLine;
			} else {
				verticalLine = " " + verticalLine;
			}
			i--;
			j--;
		} else if(A[i-1][j] + gapPenalty == target) {
			/* X[i] was used to match with a gap */
			x = dna1[i-1] + x;
			y = "-" + y;
			verticalLine = " " + verticalLine;
			i--;
		} else if(A[i][j-1] + gapPenalty == target) {
			/* Y[j] was used to match with a gap */
			x = "-" + x;
			y = dna2[j-1] + y;
			verticalLine = " " + verticalLine;
			j--;
		} else {
			cout << "ERROR CHECK" << endl;
		}
	}

	/* ending up here means i or j was 0 (possibly both) */
	if(i == 0 && j == 0) {
		/* don't do anything */
	} else if(i == 0) {
		/* j > 0 */
		while(j > 0) {
			x = "-" + x;
			y = dna2[j-1] + y;
			verticalLine = " " + verticalLine;
			j--;
		}
	} else {
		/* i > 0 */
		while(i > 0) {
			x = dna1[i-1] + x;
			y = "-" + y;
			verticalLine = " " + verticalLine;
			i--;
		}
	}

	/* print the alignments */

	cout << x << endl;
	cout << verticalLine << endl;
	cout << y << endl;

}