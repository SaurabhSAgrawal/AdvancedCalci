#include <string.h>
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

GtkWidget* text_field;

gchar* return_button_label(gint index);

void callback( GtkWidget *widget,gpointer data);

void clearbuffer(char* text_field_buffer);

int calculation(char* text_field_buffer);

int precedance(char c);
void operation(char c);
int infixeval(char *a);
void itoa(int n,char s[]);
void reverse(char s[]);
