typedef struct node {
	int val;
	struct node *prev, *next;
}node;
typedef struct Integer {
	node *head, *tail;
}Integer;
Integer CreateIntegerFromString(char *str);
Integer CreateIntegerFromFile(char *fname);
Integer AddDigitToInteger(Integer a, char digit);
Integer AddIntegers(Integer a, Integer b);
Integer SubtractIntegers(Integer a, Integer b);
Integer MultiplyIntegers(Integer a, Integer b);
void PrintInteger(Integer a);
