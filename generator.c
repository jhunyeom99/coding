#include <stdio.h>
#include <stdlib.h>


int numGeneration(int n) {   // function for generating d(n) from n
	int sum = n;   // add original number n to sum

	if (n < 10) {   // if one digit number, d(n) = 2n
		sum += n;
	} 

	else {
		while (n > 9) {    // getting d(n) for non one digit numbers
			sum += n % 10;
			n -= n % 10;
			n /= 10;
		}
		
		sum += n;
	}

	return sum;   // return d(n)
}


int isSelfNumber(int n) {  // function for checking if a given number is a self number
	int i, is_self = 1;   // is_self = 1 : assumes number is self number at first

	for (i = 1; i <= n; i++) {   // check all numbers below given number
		if (numGeneration(i) == n) {   // if there is a generator below given number, it is not a self number
			is_self = 0;
			break;
		}
	}

	return is_self;   // returns 1 if self number, 0 if not
}


int main(void) {
	int a, b;   // inputs
	int i, self_determine, sum = 0;

	printf("input the range of the number: ");   // get inputs
	scanf("%d %d", &a, &b);

	if (a >= b || a < 1 || b < 1) {    // check range of inputs
		fprintf(stderr, "invalid input\n");
		exit(1);
	}

	for (i = a; i <= b; i++) {   // loop through all numbers between the range
		self_determine = isSelfNumber(i);   // 1 if self number, 0 if not

		if (self_determine == 1) {   // if self number, print it and add it to sum
			printf("%d ", i);
			sum += i;
		}
	}

	printf("\nThe sum of the Self Number: %d\n", sum);   // print sum

	return 0;
}
