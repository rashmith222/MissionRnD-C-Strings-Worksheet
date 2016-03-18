/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<string.h>

void number_to_str(float number, char *str,int afterdecimal){
	float f1;
	f1 = number;
	int c, flag = 0, rev = 0, r;
	if (number<0)
		number = -number;
	r = number;
	while (r != 0)
	{
		c = r % 10;
		rev = rev * 10 + c;
		r = r / 10;
		flag++;
	}
	int p;
	p = number * 1000000;
	int i = 0, output, j = 0;
	char temp;
	while (p != 0)
	{
		output = p % 10;
		str[i] = output + '0';
		i++;
		p = p / 10;
	}
	str[i] = '\0';
	int length = strlen(str);
	if (f1<0){
		i = 1;
		str[0] = '-';
	}
	else if (f1>0){
		i = 0;
	}
	j = length - 1;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	str[length] = '\0';
	char b[10];
	if (f1<0)
		i = flag + 1;
	else
		i = flag;
	j = 0;
	while (str[i] != '\0'){
		b[j] = str[i];
		i++;
		j++;
	}
	b[j] = '\0';
	if (f1<0){
		i = flag + 1;
	}
	else
		i = flag;
	if (afterdecimal>0){
		str[i] = '.';
		j = i + 1;
		int l = 0;
		while (l<afterdecimal){
			str[j] = b[l];
			j++;
			l++;
		}
		str[j] = '\0';
	}
	else if (afterdecimal == 0 && f1>0){
		str[flag] = '\0';
	}
	else if (afterdecimal == 0 && f1<0){
		str[flag + 1] = '\0';
	}
}
