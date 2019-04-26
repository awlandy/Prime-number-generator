//#include "pch.h"
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <random>

constexpr int PRIME_NUMBER_DIGITS = 16;	// this cannot go bigger than 18 with long long or 19 with unsigned long long

const char zerotonine[] = "0123456789";
const char onetonine[] = "123456789";
const char odd[] = "13579";

bool prime(long long n) {
	long limit = sqrt(n);
	if (n % 2 == 0)
		return false;
	for (long i = 3; i <= limit; ++(++i)) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

long long getlldrandom() {
	char buf[PRIME_NUMBER_DIGITS + 1] = "";

	buf[0] = onetonine[(std::rand() % (strlen(onetonine)))];
	buf[PRIME_NUMBER_DIGITS - 1] = odd[(std::rand() % (strlen(odd)))];
	for (int index = 1; index < (PRIME_NUMBER_DIGITS - 1); ++index) {
		buf[index] = zerotonine[(std::rand() % (strlen(zerotonine)))];
	}
	return atoll(buf);
}

int main() {
	srand(time(NULL));
	long long randomprime;
	bool stop = false;
	while (1) {
		randomprime = getlldrandom();
		bool stop = prime(randomprime);
#ifdef _DEBUG	// #ifdef DEBUG for other compilers
		printf("This is %s prime number %lld\n", stop ? "true" : "false", randomprime);
#endif
			if (stop)
				break;
	}
	printf("Success: Random 16-digit prime %lld\n", randomprime);		//print result
	system("pause");
	return 1;
}
