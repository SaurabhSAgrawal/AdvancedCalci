
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

int precedence(char c);

void operation(char c);

int infixeval(char *a);

void itoa(int n,char s[]);

void reverse(char s[]);

long long int fact(long long int n);

char* fact1(int n);
