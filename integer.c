#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"integer1.h"
Integer CreateIntegerFromString(char *str){
	int i;
	int a[strlen(str)];
	Integer l;
	l.head = NULL;
	l.tail = NULL;

	for(i = 0; str[i] != '\0'; i++) {
		a[i] = str[i] - '0';
		//printf("%d", a[i]);
	}
	for(i = 0; i < strlen(str); i++) {
		node *tmp;
		tmp = (node*)malloc(sizeof(node));
		tmp -> prev = NULL;
		tmp -> next = NULL;

		tmp->val = a[i];	
		if(l.head) {
			l.tail->next = tmp;
			tmp-> prev = l.tail;
			l.tail = tmp;
		}
		else 
			l.head = l.tail = tmp;
	}
	return l;
}
/*Integer CreateIntegerFromString(char *str){
	int i;
	int a[strlen(str)];
	Integer l;
	l.head = NULL;
	l.tail = NULL;

	for(i = 0; str[i] != '\0'; i++) {
		a[i] = str[i] - '0';
		printf("%d", a[i]);
	}
	for(i = 0; i < strlen(str); i++) {
		node *tmp;
		tmp = (node*)malloc(sizeof(node));
		tmp->val = a[i];
		printf("hi");	
		if(l.head) {
			l.tail->next = tmp;
			tmp->next = l.head;
			l.head->prev = tmp;
			tmp-> prev = l.tail;
			l.tail = tmp;
		}
		else 
			l.head = l.tail = tmp->next = tmp->prev = tmp;
	}
	return l;
}*/

Integer CreateIntegerFromFile(char *fname){
}
Integer AddDigitToInteger(Integer a, char digit){
	int i, j;
	node *tmp;
	tmp = a.tail;
	i = digit - '0';
	j = tmp->val + i;
	if((j / 10) >= 1) {
		tmp->val = (j % 10);
		tmp->prev->val = tmp->prev->val + (j / 10);
		//	tmp = tmp->prev;
	}
	else
		a.tail->val = j;
	return a;
}
Integer AddIntegers(Integer a, Integer b){
}
Integer SubtractIntegers(Integer a, Integer b){
}
Integer MultiplyIntegers(Integer a, Integer b){
}
void PrintInteger(Integer a){
	printf("[");
	node *tmp;
	tmp = a.head;
	while(tmp != a.tail) {
		printf("%d", tmp->val);
		tmp = tmp->next;
	}
	if(tmp)
		printf("%d", tmp->val);
	printf("]\n");
}
