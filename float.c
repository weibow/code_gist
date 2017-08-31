#include <stdio.h>

int main(void)
{
	float sum;
	char show_buffer[32];
	float b=5.001;
printf("%d\n",5.001);
printf("%d\n",b);
	sum = 1.23;
	sprintf(show_buffer, "%f", 3.1/3); 
	printf("%s\r\n", show_buffer);
	printf("%f\r\n", sum);
	printf("%.7f\r\n", sum);
}