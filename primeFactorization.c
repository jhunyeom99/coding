#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 1024
#define MAX_PRIMES 180


typedef struct {
	int base, exponent;
} form;


void findPrimes(int *p, int *count, int n) {
	int i, j;
	int number_list[n];   // all natural numbers below n
	*count = 0;

	for (i = 1; i <= n; i++)   // fill number_list
		number_list[i-1] = i;

	for (i = 1; i <= n; i++) {   // for loop to find all primes
		if (number_list[i-1] == 1)   // 1 means non-prime
			continue;

		p[*count] = i;   // save prime number to list
		(*count)++;

		for (j = i; j < n; j++) {   // mark all multiples of prime number 1
			if(number_list[j] % i == 0)
				number_list[j] = 1;
		}
	}
}


int primeFactorize(form f[], int p[], int total, int n) {
	int i, j = 0, count;

	for (i = 0; i < total; i++) {
		count = 0;   // exponent

		while (n % p[i] == 0) {   // while prime number is a factor
			count++;   // adds exponent
			n = n / p[i];   // factorization
		}

		if (count != 0) {   // if prime number is a factor, add it to factor list
			f[j].base = p[i];
			f[j].exponent = count;
			j++;
		}

		if (n == 1)   // if factorization is over, break
			break;
	}

	return j;   // returns number of prime factors
}


int main(void) {
	int n, prime_count, factor_count, i;   // integer input, number of primes below n, number of factors
	int primes[MAX_PRIMES];   // prime numbers below n
	form factors[MAX_PRIMES]; 

	printf("Please input integer for Prime Factorization: ");
	scanf("%d", &n);

	if (n > MAX_INPUT || n < 2) {   // check boundary
		fprintf(stderr, "invalid input\n");
		exit(1);
	}

	findPrimes(primes, &prime_count, n);
	factor_count = primeFactorize(factors, primes, prime_count, n);

	printf("%d = ", n);   //printing the result
	for (i = 0; i < factor_count; i++) {
		printf("%d^%d", factors[i].base, factors[i].exponent);
		if ((factor_count - i) != 1)
			printf(" * ");
	}
	printf("\n");

	return 0;
}
