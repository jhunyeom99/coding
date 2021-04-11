#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 1024
#define MAX_PRIMES 180


typedef struct {
	int base, exponent;
} form;


void primeFactorize(form f[], int n, int *count) {
	int i, j, k;
	int num_list[n];
	*count = 0;

	for (i = 0; i < n; i++)
		num_list[i] = i + 1;

	for (i = 1; i <= n; i++) {

		if (num_list[i-1] == 1) continue;

		k = 0;
		while (n % i == 0) {
			k++;
			n = n / i;
		}

		if (k != 0) {
			f[*count].base = i;
			f[*count].exponent = k;
			(*count)++;
		}

		if (n == 1) break;

		for (j = i; j <= n; j++) {
			if (num_list[j] % i == 0)
				num_list[j] = 1;
		}
	}
}


int main(void) {
	int n, factor_count, i;
	form factors[MAX_PRIMES];

	printf("Please input integer for Prime Factorization: ");
	scanf("%d", &n);

	if (n > MAX_INPUT || n < 2) {   // check boundary
		fprintf(stderr, "invalid input\n");
		exit(1);
	}

	primeFactorize(factors, n, &factor_count);

	printf("%d = ", n);
	for (i = 0; i < factor_count; i++) {
		printf("%d^%d", factors[i].base, factors[i].exponent);
		if ((factor_count - i) != 1)
			printf(" * ");
	}
	printf("\n");

	return 0;
}
