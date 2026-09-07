#ifndef	CUB3D_H
#define CUB3D_H

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>//temp
#include <fcntl.h>//for files 

typedef struct s_texture
{
	char *no;
	char *so;
	char *we;
	char *ea;
	char *f;
	char *c;
	
} t_texture;

//check_file
int charcount(char needle, char *haystack);
char *ft_rstrstr(char *needle, char *haystack, int needlen);

//read_file
char *read_file(char *file, t_texture *texture);

#endif
