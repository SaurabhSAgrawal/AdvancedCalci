
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
 
#include<gtk/gtk.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include"calculator.h"
#include"stack.h"

stack p;
cstack o;

//does the operation +, -, *, /
void operation(char c) {
	double a,b;
	a = pop(&p);
	b = pop(&p);
	switch(c) {	
		case'+':
			push(&p, a + b);
			break;
		case'-':
			push(&p, b - a);
			break;	
		case'*':
			push(&p, b * a);
			break;
		case'/':
			push(&p, b / a);
			break;
	}
}

//precedence of operators
int precedence(char c) {
	if( c == '-')
		return 1;
	else if( c == '+')
		return 2;
	else if( c == '*')
		return 3;
	else if(c == '/')
		return 4;
	else if(c =='(')
		return 0;
}

//buffer to store the inputs in the text field that was declared in main
extern gchar text_field_buffer[200];
extern GtkWidget* text_field;

gchar main_buffer[200];

// allocate memory for button labels
gchar* b1 = "1";
gchar* b2 = "2";
gchar* b3 = "3";
gchar* b4 = "4";
gchar* b5 = "5";
gchar* b6 = "6";
gchar* b7 = "7";
gchar* b8 = "8";
gchar* b9 = "9";
gchar* b0 = "0";
gchar* b_plus = "+";
gchar* b_minus = "-";
gchar* b_divide = "/";
gchar* b_multiply = "*";
gchar* b_equals = "=";
gchar* b_ln = "ln";
gchar* b_sin = "sin";
gchar* b_cos = "cos";
gchar* b_tan = "tan";
gchar* b_sqrt = "sqrt";
gchar* b_sinh = "sinh";
gchar* b_cosh = "cosh";
gchar* b_tanh = "tanh";
gchar* b_modulus = "|x|";
gchar* b_ob = "(";
gchar* b_cb = ")";
gchar* b_fact = "x!";
gchar* b_sq = "sq";

// returns text to be displayed on buttons
gchar* return_button_label(gint index) {
	switch(index) {
		case 0:
			return b1;
		case 1:
			return b2;
		case 2:
			return b3;
		case 3:
			return b_plus;
		case 10:
			return b4;
		case 11:
			return b5;
		case 12:
			return b6;
		case 13:
			return b_minus;
		case 20:
			return b7;
		case 21:
			return b8;
		case 22:
			return b9;
		case 23:
			return b_multiply;
		case 30:
			return b_ln;
		case 31:
			return b0;
		case 32:
			return b_equals;
		case 33:
			return b_divide;
		case 40:
			return b_sin;
		case 41:
			return b_cos;
		case 42:
			return b_tan;
		case 43:
			return b_sqrt;
		case 50:	
			return b_sinh;
		case 51:
			return b_cosh;
		case 52:
			return b_tanh;
		case 53:
			return b_modulus;
		case 60:
			return b_ob;
		case 61:
			return b_cb;
		case 62:
			return b_fact;
		case 63:
			return b_sq;
	}
}


//buffer to store the inputs in the text field
//gchar text_field_buffer[200];

void callback(GtkWidget *widget, gpointer data) {
	
	if(strcmp((gchar*)data, "=") == 0) {
		calculation(text_field_buffer);
		gtk_entry_set_text(GTK_ENTRY(text_field), text_field_buffer);
	}
	
	else if(strcmp((gchar*)data, "AC") == 0) {// if its the AC button clear inputs
		clearbuffer(text_field_buffer); // clear the inputs
		gtk_entry_set_text(GTK_ENTRY(text_field),(gchar*)text_field_buffer);
	}
	else {// continue to take vali inputs
		strcat (text_field_buffer,(gchar*)data);
		gtk_entry_set_text(GTK_ENTRY(text_field),(gchar*)text_field_buffer);		
	}
	if(strcmp((gchar*)data, "sin") == 0) {
		double a = atof(text_field_buffer);
		char *str = (char *)malloc(20);
		clearbuffer(text_field_buffer);
		sprintf(str, "%lf", sin(a)); 
		strcpy(text_field_buffer, str);
		gtk_entry_set_text(GTK_ENTRY(text_field), (gchar*)text_field_buffer);
	}
	else if(strcmp((gchar*)data, "cos") == 0) {
		double a = atof(text_field_buffer);
		char *str = (char *)malloc(20);
		clearbuffer(text_field_buffer);
		sprintf(str, "%lf", cos(a)); 
		strcpy(text_field_buffer, str);
		gtk_entry_set_text(GTK_ENTRY(text_field), (gchar*)text_field_buffer);
	}
	else if(strcmp((gchar*)data, "tan") == 0) {
		double a = atof(text_field_buffer);
		char *str = (char *)malloc(20);
		clearbuffer(text_field_buffer);
		sprintf(str, "%lf", tan(a)); 
		strcpy(text_field_buffer, str);
		gtk_entry_set_text(GTK_ENTRY(text_field), (gchar*)text_field_buffer);

	}
	else if(strcmp((gchar*)data, "sinh") == 0) {
		double a = atof(text_field_buffer);
		char *str = (char *)malloc(20);
		clearbuffer(text_field_buffer);
		sprintf(str, "%lf", sinh(a)); 
		strcpy(text_field_buffer, str);
		gtk_entry_set_text(GTK_ENTRY(text_field), (gchar*)text_field_buffer);

	}
	else if(strcmp((gchar*)data, "cosh") == 0) {
		double a = atof(text_field_buffer);
		char *str = (char *)malloc(20);
		clearbuffer(text_field_buffer);
		sprintf(str, "%lf", cosh(a)); 
		strcpy(text_field_buffer, str);
		gtk_entry_set_text(GTK_ENTRY(text_field), (gchar*)text_field_buffer);

	}
	else if(strcmp((gchar*)data, "tanh") == 0) {
		double a = atof(text_field_buffer);
		char *str = (char *)malloc(20);
		clearbuffer(text_field_buffer);
		sprintf(str, "%lf", tanh(a)); 
		strcpy(text_field_buffer, str);
		gtk_entry_set_text(GTK_ENTRY(text_field), (gchar*)text_field_buffer);

	}
	else if(strcmp((gchar*)data, "x!") == 0) {
		long long int a = atoi(text_field_buffer);
		char *str = (char *)malloc(200);
		clearbuffer(text_field_buffer);
		sprintf(str, "%lld", fact(a));
		strcpy(text_field_buffer, str);
		gtk_entry_set_text(GTK_ENTRY(text_field), (gchar*)text_field_buffer);

	}
	else if(strcmp((gchar*)data, "|x|") == 0) {
		double a = atof(text_field_buffer);
		char *str = (char *)malloc(20);
		clearbuffer(text_field_buffer);
		if(a < 0) {
			sprintf(str, "%lf", (-1 * a));
		}
		if(a >= 0) {
			 sprintf(str, "%lf", a);
		}
		strcpy(text_field_buffer, str);
		gtk_entry_set_text(GTK_ENTRY(text_field), (gchar*)text_field_buffer);

	}
	else if(strcmp((gchar*)data, "sq") == 0) {
		long long int a = atoi(text_field_buffer);
		char *str = (char *)malloc(200);
		clearbuffer(text_field_buffer);
		sprintf(str, "%lld", a * a); 
		strcpy(text_field_buffer, str);
		gtk_entry_set_text(GTK_ENTRY(text_field), (gchar*)text_field_buffer);

	}
	else if(strcmp((gchar*)data, "ln") == 0) {
		double a = atof(text_field_buffer);
		char *str = (char *)malloc(20);
		clearbuffer(text_field_buffer);
		sprintf(str, "%lf", log(a)); 
		strcpy(text_field_buffer, str);
		gtk_entry_set_text(GTK_ENTRY(text_field), (gchar*)text_field_buffer);

	}
	else if(strcmp((gchar*)data, "sqrt") == 0) {
		double a = atof(text_field_buffer);
		char *str = (char *)malloc(20);
		clearbuffer(text_field_buffer);
		sprintf(str, "%lf", sqrt(a)); 
		strcpy(text_field_buffer, str);
		gtk_entry_set_text(GTK_ENTRY(text_field), (gchar*)text_field_buffer);

	}
	
}

//calculates infix expression
int calculation(char* text_field_buffer) {
	char *infix = text_field_buffer;
	int i = 0, sum = 0;
	char g;
	init(&p);
	cinit(&o);
	while(infix[i] != '\0'){
		switch(infix[i]){
			case '1': case'2': case '3': case '4':
			case '5': case'6': case '7': case '8':
			case '9': case'0': 
				sum = sum * 10 + infix[i] -'0';
				i++;
				break;

			case'+':
				if(infix[i-1] != ')' && infix[i-1] != ' ' && infix[i-1] != ',' ){
					push(&p, sum);
					sum = 0;
				}
				if(cisempty(&o) != 0){
					if(precedence(*ctop(&o)) <= 2)
						cpush(&o, infix[i]);
					else{
						while(precedence(*ctop(&o)) > 2){
							operation(*ctop(&o));
							g = cpop(&o);

						}
						cpush(&o, infix[i]);
					}
				}
				else
					cpush(&o, infix[i]);
				i++;
				break;
				
			case'-':
				if(infix[i-1] != ')' && infix[i-1] != ' ' && infix[i-1] != ','){
					push(&p, sum);
					sum = 0;
				}
				if(cisempty(&o) != 0){
					if(precedence(*ctop(&o)) == 1)
						cpush(&o, infix[i]);
					else{
						while(precedence(*ctop(&o)) > 1){	
							operation(*ctop(&o));
							g = cpop(&o);
						}
						cpush(&o, infix[i]);
					}
				}
				else
					cpush(&o, infix[i]);
				i++;	
				break;
		
			case'*': 
				if(infix[i-1] != ')' && infix[i-1] != ' ' && infix[i-1] != ','){
					push(&p, sum);
					sum = 0;
				}
				if(cisempty(&o) != 0){
					if(precedence(*ctop(&o)) <= 3)
						cpush(&o, infix[i]);
					else{
						while(precedence(*ctop(&o)) > 3){	
						operation(*ctop(&o));
						g = cpop(&o);
						}
						cpush(&o, infix[i]);
					}
				}
				else
					cpush(&o, infix[i]);
				i++;	
				break;
				
			case'/': 
				if(infix[i-1] != ')' && infix[i-1] != ' ' && infix[i-1] != ','){
					push(&p, sum);
					sum = 0;
				}
				if(cisempty(&o) != 0){
					if(precedence(*ctop(&o)) <= 4)
						cpush(&o,infix[i]);
					else{
						while(precedence(*ctop(&o)) > 4){	
						operation(*ctop(&o));
						g = cpop(&o);
						}
						cpush(&o, infix[i]);
					}
				}
				else
					cpush(&o, infix[i]);
				i++;	
				break;
			
			case'(':
				cpush(&o, infix[i]);
				i++;
				break;
				
			case')':
				if(infix[i-1] != ')' && infix[i-1] != ' ' && infix[i-1] != ','){
					push(&p, sum);
					sum = 0;
				}
				while(*ctop(&o) != '('){
			        	operation(*ctop(&o));
					g = cpop(&o);
				}
				g = cpop(&o);
				i++;	
				break;
		
			case ' ':
			 	i++;				
			 	break;
			default:
				i++;
				GtkWidget* dialog = gtk_message_dialog_new (NULL,
                                 GTK_DIALOG_DESTROY_WITH_PARENT,
                                 GTK_MESSAGE_ERROR,
                                 GTK_BUTTONS_CLOSE,
                                 "Invalid or unsupported input\nCheck your expression");
				gtk_dialog_run (GTK_DIALOG (dialog));
				gtk_widget_destroy (dialog);
  				clearbuffer(text_field_buffer);
  				return 0;
				break;
		}
	}
	
	if(infix[i] == '\0' &&infix[i-1] != ')' && infix[i-1] != ' ' && infix[i-1] != ',')
		push(&p, sum);
	while(cisempty(&o) != 0){
				operation(*ctop(&o));
				g = cpop(&o);
	}
	char output[100];
	int y = top(&p);
	itoa(y, output);
	strcpy(text_field_buffer, output);
	
}
	
// clears any character string
void clearbuffer(char* text_field_buffer) {
	int i;
	for (i = 0; i < strlen(text_field_buffer)+1; ++i) {
		text_field_buffer[i] = 0;
	}
}

//converts integer to string
void itoa(int n,char s[]) {
	int i, sign;
	sign=n; 
	i = 0;
	do {
		s[i++]= abs(n%10) + '0';
	}
	while((n /= 10) != 0);
	if( sign < 0)
	s[i++]='-';
	s[i]='\0';
	reverse(s);
}

//reverses a string
void reverse(char s[]) {
    int c,i,j;

    for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

//calculates factorial
long long int fact(long long int n) {
	long long int a;
	int i;
	if(n == 0)
		return 1;
	a = n;
	i = n - 1;
	while(i > 0) {
		a = a * i;
		i = i - 1;
	}
	return a;
}

//calculates factorial   
char* fact1(int n) {
	int *str, a[200], index, temp, i;
	a[0] = 1;
	index = 0;
	char c[200];
	
	for(; n >= 2; n--) {
		temp = 0;
		for(i =0 ; i <= index; i++) {
			temp = (a[i] * n) + temp;
			a[i] = temp % 10;
			temp = temp / 10;
		}
		while(temp > 0) {
			a[++index] = temp % 10;
			temp = temp / 10;
		}
	}		
	for(i = 0; i < index; i++)
		c[i] = a[i] + '0';
	//str = a;
	char *k = c;
	printf("%s", k);
	return k;
}
