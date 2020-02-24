#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* getString(char prompt[]);
void matrix2x2();
void matrix3x3();
void printMatrix(int* matrix, int size);

int main() {
	printf("1. Matrix 2x2\n");
	printf("2. Matrix 3x3\n");

	while (1) {
		char* input = getString("[1 / 2 / exit]: ");

		switch (atoi(input)) {

		case 1: matrix2x2(); break;
		case 2: matrix3x3(); break;

		default:
			if (strcmp(input, "exit") == 0) {
				return 0;
			}
		}
	}
}

const char* getString(char prompt[]) {
	static char input[256];

	printf("%s", prompt);
	scanf("%[^\n]", input);
	getchar();

	return input;
}

void matrix2x2() {
	int matrix[2][2];
	int size = 2;

	for (int row = 0; row < size; row++) {
		for (int column = 0; column < size; column++) {

			int input = 0;

			while (1) {
				char prompt[256];
				sprintf(prompt, "Matrix[%d][%d] [0-9]: ", row, column);

				input = atoi(getString(prompt));
				if (input >= 0 && input <= 9) {
					break;
				}
			}

			matrix[row][column] = input;

		}
	}

	printf("Matrix:\n");
	for (int row = 0; row < size; row++) {
		printf("| ");

		for (int column = 0; column < size; column++) {

			printf("%d ", matrix[row][column]);

		}

		printf("|\n");
	}

	int a = matrix[0][0];
	int b = matrix[0][1];
	int c = matrix[1][0];
	int d = matrix[1][1];
	int determinant = (a * d) - (b * c);
	printf("Determinant = (%d * %d) - (%d * %d) = %d\n", a, d, b, c, determinant);
}

void matrix3x3() {
	int matrix[3][3];
	int size = 3;

	for (int row = 0; row < size; row++) {
		for (int column = 0; column < size; column++) {

			int input = 0;

			while (1) {
				char prompt[256];
				sprintf(prompt, "Matrix[%d][%d] [0-9]: ", row, column);

				input = atoi(getString(prompt));
				if (input >= 0 && input <= 9) {
					break;
				}
			}

			matrix[row][column] = input;

		}
	}

	printf("Matrix:\n");
	for (int row = 0; row < size; row++) {
		printf("| ");

		for (int column = 0; column < size; column++) {

			printf("%d ", matrix[row][column]);

		}

		printf("|\n");
	}

	int a = matrix[0][0];
	int b = matrix[0][1];
	int c = matrix[0][2];
	int d = matrix[1][0];
	int e = matrix[1][1];
	int f = matrix[1][2];
	int g = matrix[2][0];
	int h = matrix[2][1];
	int i = matrix[2][2];
	int determinant = ((a * e * i) + (b * f * g) + (c * d * h)) - ((c * e * g) + (b * d * i) + (a * f * h));
	printf("Determinant = [(%d * %d * %d) + (%d * %d * %d) + (%d * %d * %d)] - [(%d * %d * %d) + (%d * %d * %d) + (%d * %d * %d)] = %d\n",
		a, e, i, b, f, g, c, d, h, c, e, g, b, d, i, a, f, h, determinant);
}
