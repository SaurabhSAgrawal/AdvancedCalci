
/*****************************************************************************
 * Copyright (C) Saurabh Agrawal saurabhagrawal1483@gmail.com
 
 * This file is part of Calculator.

 *   Calculator is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.

 *   Calculator is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *   You should have received a copy of the GNU General Public License
 *   along with Calculator.  If not, see <http://www.gnu.org/licenses/>.

 *****************************************************************************/

#include<stdio.h>
#include"stack.h"

void init(stack *s){
	s->i = 0;
}
void push(stack *s,double num){
	s->arr[s->i] = num;	
	(s->i)++;
}
double pop(stack *s){
	double x;
	x = s->arr[(s->i)-1];
	(s->i)--;
	return x;
}
int isempty(stack *s){
	return s->i;
}
int isfull(stack *s){
	return s->i == MAXI - 1;
}
double top(stack *s){
	return s->arr[(s->i)-1];
}
void cinit(cstack *t){
	t->i = 0;
}
void cpush(cstack *t,char c){
	t->carr[t->i] = c;	
	(t->i)++;
}
char cpop(cstack *t){
	char x;
	x = t->carr[(t->i)-1];
	(t->i)--;
	return x;
}
int cisempty(cstack *t){
	return t->i;
}
int cisfull(cstack *t){
	return t->i == MAXI - 1;
}
char* ctop(cstack *t){
	return &(t->carr[(t->i)-1]);
}


