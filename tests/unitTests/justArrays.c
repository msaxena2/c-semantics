int main(void) {
	int x[] = {[4] = 10, 11, 12, 0, 14};
	int y[][2] = {{1, 2}, {0, 4}};
	int z[][2][2] = {{{1, 2}, {0, 4}}, {{5, 6}, {7, 8}}};
	int w[][2][2] = {1, 2, 0, 4, 5, 6, 7, 8};
	x[7] = x[8];
	y[1][0] = y[0][1];
	z[0][1][0] = z[1][0][1];
	w[0][1][0] = w[1][0][1];
	if (x[7] != 14) {return 1;}
	if (y[1][0] != 2) {return 2;}
	if (z[0][1][0] != 6) {return 3;}
	if (w[0][1][0] != 6) {return 4;}
	if (sizeof(x)/sizeof(x[0]) != 9) {return 50;}
	return 0;
}