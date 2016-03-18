/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include<malloc.h>

void str_words_in_rev(char *input, int len){
	int i = 0, j = 0, t = 0, count = 0, p = 0, k = 0, l = 0;
	char **a;
	char b[10];
	a = (char **)malloc(10 * sizeof(char *));
	for (l = 0; l<10; l++)
		a[l] = (char *)malloc(len*sizeof(char));
	while (input[i] != '\0')
	{
		k = 0;
		while (input[i] != ' ')
		{
			a[p][k] = input[i];
			k++;
			if (k > len)
				break;
			i++;
			if (i>len){
				break;
			}
		}
		a[p][k] = '\0';
		b[t] = input[i];
		++count;
		t++;
		++p;
		if (input[i] == ' ')
			i++;
	}
	j = 0; p = p - 1; k = 0; t = 0;
	while (a[p] != '\0')
	{
		while (a[p][k] != '\0')
		{
			input[j] = a[p][k];
			k++;
			++j;
		}
		k = 0;
		--p;
		if (p == -1)
			break;
		input[j] = b[t];
		t++;
		++j;
	}
	input[j] = '\0';
}
