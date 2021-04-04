#include <stdio.h>
#include <math.h>

main ()
{
int a, b, c, d, e;
unsigned long long a5, b5, c5, d5;
unsigned long long sum_ab, sum_abc;
int tot;
bool flag = false;
	for (a = 3; a < 150; a++)
	{
		a5 = pow(a, 5);
		for (b = a; b < 150; b++)
		{
			b5 = pow(b, 5);
			sum_ab = a5 + b5;
			for (c = b; c < 150; c++)
			{
				c5 = pow(c, 5);
				sum_abc= a5 + b5 + c5;
				for (d = c; d < 150; d++)
				{
					d5 = pow(d, 5);
					e = pow((sum_abc + d5), 0.2);
					if (sum_abc + d5 == pow(e, 5))
					{
						tot = a + b + c + d + e;
						printf("%d\n", tot);
					}
				}
			}
		}
	}
}
