static unsigned long next = 1;

int randint(int M) {
	unsigned long a = 1103515245, c = 12345;
	next = a * next + c;
	return ((unsigned int) (next / 65536) % 32768) % M + 1;
}
