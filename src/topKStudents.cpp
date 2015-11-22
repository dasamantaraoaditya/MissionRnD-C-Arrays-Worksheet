/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};
struct student ** topKStudents(struct student *students, int len, int k)
{
	int i, j, L;
	struct student temp;
	temp.name = (char *)malloc(sizeof(char) * 10);

	if (students == NULL || len < 0 || k<0)
		return NULL;
	for (i = 0; i < k - 1; i++)
	{
		for (j = 0; j < k - i - 1; j++)
		{
			if (students[j].score<students[j + 1].score)
			{
				for (L = 0; students[j].name[L] != '\0'; L++)
					temp.name[L] = students[j].name[L];
				temp.name[L] = '\0';
				temp.score = students[j].score;

				for (L = 0; students[j + 1].name[L] != '\0'; L++)
					students[j].name[L] = students[j + 1].name[L];
				students[j].name[L] = '\0';
				students[j].score = students[j + 1].score;

				for (L = 0; temp.name[L] != '\0'; L++)
					students[j + 1].name[L] = temp.name[L];
				students[j + 1].name[L] = '\0';
				students[j + 1].score = temp.score;

			}
		}
	}

}