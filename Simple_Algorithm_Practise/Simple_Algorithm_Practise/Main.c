#include <stdio.h>
#include <stdlib.h>

int main() {

	puts(" ::: 19th Multiplication table :::");
	int tColumn, Row, Dan = 2, Column = 6;
	while (Dan < 20) {
		for (Row = 1; Row < 20; Row++) {
			for (tColumn = Dan; tColumn < Dan + Column && tColumn < 20; tColumn++) {
				printf(" %2d X %2d = %d\t", tColumn, Row, tColumn * Row);
			}
			puts("");
		}
		puts("");
		Dan = tColumn;
	}

	system("PAUSE");
	return 0;
}