#include<stdio.h>
//#define LOCAL
long long n, sp, sq, k, mink;
int main()
{
	int a, b, mina, minb, firstk;
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	while (scanf ("%lld%lld%lld", &n, &sp, &sq) != EOF)
	{
		firstk = 1;
		for (a = 0; a < 32; a++)
		{
			for (b = 0; b < 32; b++)
			{
				k = ( ( (n - 1) * sp + ( (n - 1) * sp << a)) >> b) + sq; //容易验证只要满足该式便不会重叠
				if (k < n * sq)
					break;
				else
				{
					if (firstk)
					{
						mink = k;
						mina = a;
						minb = b;
						firstk = 0;
					}
					if (k < mink)
					{
						mina = a;
						minb = b;
						mink = k;
					}
				}
			}
		}
		printf ("%lld %d %d\n", mink, mina, minb);
	}
	return 0;
}