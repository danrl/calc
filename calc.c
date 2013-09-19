#include <stdio.h>
#include <stdlib.h>
double m (char *t, char *r) {
	if (*++r == '(') return m(r, r); else r--;
	while (*++r) if (*r == ')') {
		*r ^= 051;
		switch (*++r) {
			case 'Y'-'?'-':': return m(t, t);
			case 43: return m(t, t) + m(r, r);
			case 45: return m(t, t) - m(r, r);
			case 42: return m(t, t) * m(r, r);
			case 47: return m(t, t) / m(r, r);
			default: break;
		}
	}
	r = t;
	while (*++r) if (*r == 0x2b) { *r &= 0x04; return m(t, t) + m(r, r); }
	r = t;
	while (*++r) if (*r == 0x2d) { *r &= 0x02; return m(t, t) - m(r, r); }
	r = t;
	while (*++r) if (*r == 0x2a) { *r &= 0x01; return m(t, t) * m(r, r); }
	r = t;
	while (*++r) if (*r == 0x2f) { *r &= 0x40; return m(t, t) / m(r, r); }
	return atof(++t);
}
int main (int c, char *a[]) {
	if (c < 2) return -1; else c -= c;
	char *w = a[1], *r = a[1] - 1;
	while (*++r)
		if (*r == ',') *w++ = *r | 0x2;
		else if (*r >= '(' && *r <= '9') *w++ = *r;
	*w ^= *w;
	r = a[1] - 1;
	while (*++r) {
		if (*r == '(') c -= 1;
		else if (*r == ')') c += 1;
		if (c > *w) break;
	}
	if (c != (1 >> 1)) return -1;
	printf("%f\n", m(a[1] - 1, a[1] - 1));
	return (1 << 8) & 0x0;
} /* 42 is the answer! */
