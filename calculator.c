#include<gtk/gtk.h>
#include<math.h>
#include"calculator.h"

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
gchar* b_decimal = ".";
gchar* b_sin = "sin";
gchar* b_cos = "cos";
gchar* b_tan = "tan";
gchar* b_sqrt = "sqrt";
gchar* b_sinh = "sinh";
gchar* b_cosh = "cosh";
gchar* b_tanh = "tanh";
gchar* b_sq = "^";
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
			return b_decimal;
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
			return b_sq;
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
	int index = 0;char sym;
	int return_value = return_symbol(text_field_buffer, &index, &sym);// gets the arithmetic operator and its position
	if(return_value == 1) {// for mathematical expression
  		char dest2[100];
  		char dest1[100];
  		
  		make_string(text_field_buffer, dest1, dest2, index); //makes two number strings from the passed buffer
  		clearbuffer(text_field_buffer); 

  		double num1,num2;
  		num1 = atof(dest1);//converts each stream to double
  		num2 = atof(dest2);

  		char output[200];
  		apply_currect_operation(output, sym, num1, num2);
   		
   		strcpy(text_field_buffer, output);
   		//printf("%s",output);
  	}
  	else if(return_value == -1) {// invalid expression with multiple operators
  		GtkWidget* dialog = gtk_message_dialog_new (NULL,
                                 GTK_DIALOG_DESTROY_WITH_PARENT,
                                 GTK_MESSAGE_ERROR,
                                 GTK_BUTTONS_CLOSE,
                                 "invalid or unsupported input\ncheck your expression");
		gtk_dialog_run (GTK_DIALOG (dialog));
		gtk_widget_destroy (dialog);
  		clearbuffer(text_field_buffer);
  		return 0;
  	}
  	else // pure number without operators.. so no change is required
  		return;
}

void make_string(char* text_field_buffer, char* dest1, char* dest2, int index) {
	int i;
	for(i=0; i<index; ++i)
		dest1[i] = text_field_buffer[i];
	//append null characrter
	dest1[i] = 0;

	for (i = index+1; i < strlen(text_field_buffer); ++i) {
		dest2[i-index-1] = text_field_buffer[i];
	}
	//null char
	dest2[i-index-1] = 0;
}

int return_symbol(char* text_field_buffer, int* index, char* symbol) {
	int i;
	*symbol = 0;
	*index = 0;
	int symbolcount = 0;
	for(i = 0; i < strlen(text_field_buffer); ++i) {
		if (!isdigit(text_field_buffer[i]) && text_field_buffer[i] != '.') {
			if ( (text_field_buffer[i] == '+' || text_field_buffer[i]=='-' || text_field_buffer[i]=='^' || text_field_buffer[i]=='*' || text_field_buffer[i]=='/') ) {
				*index = i;
				*symbol = text_field_buffer[i];
				++symbolcount;
			}
			else return -1;
		}
	}
	if (symbolcount == 0) {
		return 0; // pure number without operator
	}
	else
		return 1; // valid expression
}

// clears any character string
void clearbuffer(char* text_field_buffer) {
	int i;
	for (i = 0; i < strlen(text_field_buffer)+1; ++i) {
		text_field_buffer[i] = 0;
	}
}

void apply_currect_operation(char* output, char symbol, double num1, double num2) {
	if(symbol == '+') {
		sprintf(output, "%.3f", num1+num2);
		return;
	}
	if(symbol == '-') {
		sprintf(output, "%.3f", num1-num2);
		return;
	}
	if(symbol == '*') {
		sprintf(output, "%.3f", num1*num2);
		return;
	}
	if(symbol == '/') {
		sprintf(output, "%.3f", num1/num2);
		return;
	}
	if(symbol == '^') {
		//double ans = pow(num1, num2);
		sprintf(output, "%.3f", pow(num1, num2));
		return;
	}
}
