#include <stdio.h>
#include <stdlib.h>

int main() {

	puts(" ::: 19th Multiplication table :::\n");
	int MaxDan = 19, uData = 3;
	for (int Dan = 2; Dan <= MaxDan; Dan+=uData) {
		for (int Row = 1; Row <= MaxDan; Row++) {
			for (int tDan = Dan; tDan < Dan + uData && tDan <= MaxDan; tDan++) {
				printf("%2d X %2d = %2d\t", tDan, Row, tDan * Row);
			}
			puts("");
		}
		puts("");
	}

	system("PAUSE");
	return 0;
}