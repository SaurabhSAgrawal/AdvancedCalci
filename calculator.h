
/*****************************************************************************
 * Copyright (C) Saurabh Agrawal saurabhagrawal1483@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
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
