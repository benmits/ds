#include <stdio.h> #include <stdlib.h>
void addition(int r, int c, int A[r][c], int B[r][c], int R[r][c]);
void subtraction(int r, int c, int A[r][c], int B[r][c], int R[r][c]);
void multiplication(int r1, int c1, int A[r1][c1], int r2, int c2, int B[r2][c2], int R[r1][c2]);
void display(int r, int c, int R[r][c]);
int main() {
int r1, c1, r2, c2; int o;
printf("FIRST MATRIX IS:\n");
printf("Enter number of rows for Matrix A: "); scanf("%d", &r1);
printf("Enter number of columns for Matrix A: "); scanf("%d", &c1);
printf("\nSECOND MATRIX IS:\n"); printf("Enter number of rows for Matrix B: "); scanf("%d", &r2);
printf("Enter number of columns for Matrix B: "); scanf("%d", &c2);
int A[r1][c1], B[r2][c2];
printf("\nEnter elements of Matrix A:\n"); for (int i = 0; i < r1; i++) {
for (int j = 0; j < c1; j++) { scanf("%d", &A[i][j]);
}
}
printf("\nEnter elements of Matrix B:\n"); for (int i = 0; i < r2; i++) {
for (int j = 0; j < c2; j++) { scanf("%d", &B[i][j]);
}
}
printf("\nMatrix A:\n"); for (int i = 0; i < r1; i++) {
for (int j = 0; j < c1; j++) {
 
printf("%d ", A[i][j]);
}
printf("\n");
}
printf("\nMatrix B:\n"); for (int i = 0; i < r2; i++) {
for (int j = 0; j < c2; j++) { printf("%d ", B[i][j]);
}
printf("\n");
}
do {
printf("1: Matrix Addition\n"); printf("2: Matrix Subtraction\n"); printf("3: Matrix Multiplication\n"); printf("4: Exit\n");
printf("Enter your choice: "); scanf("%d", &o);
switch (o) { case 1:
if (r1 == r2 && c1 == c2) { int sum[r1][c1]; addition(r1, c1, A, B, sum);
printf("\n--- Addition Result (A + B) ---\n"); display(r1, c1, sum);
} else {
printf("\nADDITION NOT POSSIBLE (Matrix size mismatch)\n");
}
break; case 2:
if (r1 == r2 && c1 == c2) { int diff[r1][c1];
subtraction(r1, c1, A, B, diff);
printf("\n--- Subtraction Result (A - B) ---\n"); display(r1, c1, diff);
} else {
printf("\nSUBTRACTION	NOT	POSSIBLE	(Matrix	size mismatch)\n");
}
break;
case 3:
if (c1 == r2) {
int product[r1][c2];
multiplication(r1, c1, A, r2, c2, B, product); printf("\n--- Multiplication Result (A x B) ---\n");
 
display(r1, c2, product);
} else {
printf("\nMULTIPLICATION	NOT	POSSIBLE	(Invalid dimensions)\n");
}
break; case 4:
exit(0); default:
printf("\nInvalid choice! Try again.\n");
}
} while (o != 4); return 0;
}
void addition(int r, int c, int A[r][c], int B[r][c], int R[r][c]) { for (int i = 0; i < r; i++)
for (int j = 0; j < c; j++) R[i][j] = A[i][j] + B[i][j];
}
void subtraction(int r, int c, int A[r][c], int B[r][c], int R[r][c]) { for (int i = 0; i < r; i++)
for (int j = 0; j < c; j++) R[i][j] = A[i][j] - B[i][j];
}
void multiplication(int r1, int c1, int A[r1][c1], int r2, int c2, int B[r2][c2],
int R[r1][c2]) { for (int i = 0; i < r1; i++) {
for (int j = 0; j < c2; j++) { R[i][j] = 0;
for (int k = 0; k < c1; k++) R[i][j] += A[i][k] * B[k][j];
}
}
}
void display(int r, int c, int R[r][c]) { for (int i = 0; i < r; i++) {
for (int j = 0; j < c; j++) printf("%d\t", R[i][j]);
printf("\n");
}
}
