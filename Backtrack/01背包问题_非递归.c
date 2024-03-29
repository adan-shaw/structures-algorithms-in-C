#include <stdio.h>
#define N 5
#define M 20

int maxvalue;
int weighted;

void display_outcome (int *answer, int *weight, int *value)
{
	int i;
	int myvalue = 0, myweight = 0;
	for (i = 0; i < N; i++)
		if (answer[i])
		{
			myvalue += value[i];
			myweight += weight[i];
		}
	if (myvalue > maxvalue)
	{
		maxvalue = myvalue;
		weighted = myweight;
		for (int i = 0; i < N; i++)
			printf ("%d", answer[i]);
		printf ("\n");
	}
}

int condition (int *weight, int *answer, int step, int select)
{
	int i;
	int myweight = 0;
	for (i = 0; i < step; i++)
		if (answer[i])
			myweight += weight[i];
	if (select)
		myweight += weight[step];
	return myweight <= M;
}

void backtrack (int *weight, int *value)
{
	int answer[N];
	int record[N];
	int step = 0;
	record[step] = -1;
	while (step >= 0)
	{
		record[step]++;
		while (record[step] < 2 && !condition (weight, answer, step, record[step]))
			record[step]++;
		if (record[step] >= 2)
			step--;
		else if (step == N - 1)
		{
			answer[step] = record[step];
			display_outcome (answer, weight, value);
		}
		else
		{
			answer[step] = record[step];
			step++;
			record[step] = -1;
		}
	}
}

int main (int argc, char const *argv[])
{
	int weight[N] = { 3, 4, 5, 6, 7 };
	int value[N] = { 5, 4, 3, 2, 10 };
	backtrack (weight, value);
	printf ("maxvalue=%d\n", maxvalue);
	printf ("weighted=%d\n", weighted);
	return 0;
}
