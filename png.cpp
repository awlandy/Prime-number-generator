//#include "pch.h"
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <random>

const char zerotonine[] = "123456789";

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
	char buf[17] = "";
	for (int index = 0; index < 16; ++index) {
		buf[index] = zerotonine[(std::rand() % (strlen(zerotonine)))];
	}
	return atoll(buf);
}

int main() {
	srand(time(NULL));
	long long randomprime;
	bool stop = false;
	while(1) {
		randomprime = getlldrandom();
		bool stop = prime(randomprime);
		printf("This is %s prime number %lld\n", stop ? "true" : "false", randomprime);		//just to show me whats goin' on
		if (stop)
			break;
	}
	printf("Success: Random 16-digit prime %lld\n", randomprime);		//print result
	system("pause");
	return 1;
}
