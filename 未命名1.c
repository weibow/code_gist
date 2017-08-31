#include <stdio.h>

int main(void)
{
	void *addr;
	printf("%d\r\n", (void*) addr);
	printf("%d\r\n", (void**) addr);
	printf("%d\r\n", (unsigned char*)addr);
}