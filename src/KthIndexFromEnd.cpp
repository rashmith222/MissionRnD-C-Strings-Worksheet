/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K) {
	if (str == '\0' || str == "" || K < 0){
		return '\0';
	}
	int i = 0,j=0,len=0;
	while (str[j]!='\0')
	{
		len++;
		j++;
	}
	if (K == 0){
		return str[len-1];
	}
	if (K == len - 1){
		return str[0];
	}
	if (K == (len-1 ) / 2){
		return str[(len ) / 2];
	}
	for (i = len - 1; i >= 0; i++){
		if (i == K-1){
			return str[i];
		}
	}
}