#include <iostream>
using namespace std;
#include "HashMap.h"


int main() {
	hashmap hm;
	for (int i = 0; i < 100000000; i++) {
		int x = rand() % RAND_MAX;
		hm.insert(x);
	}
	system("pause");
	return 0;
}
