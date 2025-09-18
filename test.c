#include <stdio.h>
#include <assert.h>
#include "base.c"

void test1() {
	assert(levenshtein("gato", "cato") == 1);
}

int main() {
	test1();

	retrun 0;

} 
