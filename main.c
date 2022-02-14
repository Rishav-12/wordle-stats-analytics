#include <stdio.h>
#include <math.h>
int main()
{
	int n = 0, f[10];
	float s1 = 0, s2 = 0, s3 = 0, s4 = 0;

	// input stats and calculate mean
	for(int i = 1; i <= 6; i++)
	{
		printf("How many %d guess wins?\n", i);
		scanf("%d", &f[i]);
		s1 += i*f[i];
		n += f[i];
	}

	float m1 = s1/n;

	// calculate 2nd, 3rd and 4th order central moments
	for(int j = 1; j <= 6; j++)
	{
		s2 += pow((j - m1), 2)*f[j];
		s3 += pow((j - m1), 3)*f[j];
		s4 += pow((j - m1), 4)*f[j];
	}

	float m2 = s2/n;
	float m3 = s3/n;
	float m4 = s4/n;

	printf("\nMean = %f\n", m1);
	printf("\nVar = %f\n", m2);

	// calculate skewness and kurtosis
	float g1 = m3/pow(m2, 1.5);
	float g2 = m4/pow(m2, 2) - 3;

	printf("\nSkewness = %f\n", g1);
	printf("\nKurtosis = %f\n", g2);

	// check nature of skewness
	if(g1 > 0)
	{
		printf("\nThe data is positively skewed\n");
	}
	else if(g1 < 0)
	{
		printf("\nThe data is negatively skewed\n");
	}
	else
	{
		printf("\nThe data is symmetric\n");
	}

	// check nature of kurtosis
	if(g2 > 0)
	{
		printf("\nThe data is leptokurtic\n");
	}
	else if(g2 < 0)
	{
		printf("\nThe data is platykurtic\n");
	}
	else
	{
		printf("\nThe data is mesokurtic\n");
	}
}

