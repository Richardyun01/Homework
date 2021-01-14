#include <stdio.h>

int main()
{
	int x, y, w, h;
	int m = 0;

	scanf("%d%d%d%d", &x, &y, &w, &h);

	if (w - x < h - y) m = w - x;
	else if (w - x > h - y) m = h - y;

	if (m > x) m = x;
	if (m > y) m = y;

	printf("%d", m);

	return 0;
}
