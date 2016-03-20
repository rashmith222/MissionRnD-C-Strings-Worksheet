/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include<string.h>
#include <malloc.h>
#include<conio.h>
#define SIZE 31
char ** commonWords(char *str1, char *str2) {
		if (str1 == NULL || str2 == NULL)
			return NULL;

		int length = 0, length1 = 0, j = 0;
		while (str1[j] != '\0'){
			length++;
			j++;
		}
		j = 0;
		while (str2[j] != '\0'){
			length1++;
			j++;
		}
		int t = 0, count2 = 0, count3 = 0;
		while (str1[t] != '\0' || str2[t] != '\0')
		{
			if (str1[t] == ' ')
				count2++;
			t++;
		}
		if (count2 == length){
			return NULL;
		}
		int  i = 0, count = 0, count1 = 0, p = 0, k = 0, l = 0;
		char **a, **b, **str3;
		j = 0;
		a = (char **)malloc(10 * sizeof(char *));
		for (l = 0; l<10; l++)
			a[l] = (char *)malloc(length*sizeof(char));
		b = (char **)malloc(10 * sizeof(char *));
		for (l = 0; l<10; l++)
			b[l] = (char *)malloc(length1*sizeof(char));
		str3 = (char **)malloc(sizeof(char *) * 10);
		for (l = 0; l<10; l++)
			str3[l] = (char *)malloc(length);
		while (str1[i] != '\0')
		{
			k = 0;
			while (str1[i] != ' ')
			{
				a[p][k] = str1[i];
				k++;
				if (k > length)
					break;
				i++;
				if (i >= length){
					break;
				}
			}
			a[p][k] = '\0';
			++p;
			++count;
			if (str1[i] == ' ')
				i++;
		}
		l = 0; j = 0;
		while (str2[j] != '\0')
		{
			k = 0;
			while (str2[j] != ' ')
			{
				b[l][k] = str2[j];
				k++;
				if (k>length1)
					break;
				++j;
				if (j >= length1){
					break;
				}
			}
			b[l][k] = '\0';
			++count1;
			++l;
			if (str2[j] == ' ')
				j++;
		}
		i = 0; j = 0; k = 0; p = 0;
		while (i <= count){
			while (strcmp(a[i], b[j]) == 0){
				strcpy_s(str3[p], strlen(b[j]) + 1, b[j]);
				j++;
				if (p >= count - 1)
					break;
				++p;
			}
			if (j >= count1){
				i++;
				j = 0;
			}

			if (strcmp(a[i], b[j]) != 0){
				j++;
			}
		}
		str3[p] = '\0';
		if (p == 0)
			return NULL;
		else
		return str3;
	}
