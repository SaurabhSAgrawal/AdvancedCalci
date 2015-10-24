#include<gtk/gtk.h>
#include<math.h>
#include"calculator.h"
#include"stack.h"
stack p;
cstack o;
//int precedance(char c);
//void operation(char c);
//int infixeval(char *a);

void operation(char c){
	double a,b;
	a = pop(&p);
	b = pop(&p);
	switch(c){	
		case'+':
			push(&p, a+b);
			break;
		case'-':
			push(&p, b-a);
			break;	
		case'*':
			push(&p, b*a);
			break;
		case'/':
			push(&p, b/a);
			break;
	}
}

int precedance(char c){
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
gchar* b_mod = "mod";

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
			return b_mod;
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
	else {// continue to take valid inputs
		strcat (text_field_buffer,(gchar*)data);
		gtk_entry_set_text(GTK_ENTRY(text_field),(gchar*)text_field_buffer);		
	}
}
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
					if(precedance(*ctop(&o)) <= 2)
						cpush(&o, infix[i]);
					else{
						while(precedance(*ctop(&o)) > 2){
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
					if(precedance(*ctop(&o)) == 1)
						cpush(&o, infix[i]);
					else{
						while(precedance(*ctop(&o)) > 1){	
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
					if(precedance(*ctop(&o)) <= 3)
						cpush(&o, infix[i]);
					else{
						while(precedance(*ctop(&o)) > 3){	
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
					if(precedance(*ctop(&o)) <= 4)
						cpush(&o,infix[i]);
					else{
						while(precedance(*ctop(&o)) > 4){	
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
			default:i++;
				printf("Error!\n");
				exit(1);
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
	//tostring(output, y);
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

void reverse(char s[]) {
    int c,i,j;

    for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
    
