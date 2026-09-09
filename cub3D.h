#ifndef	CUB3D_H
#define CUB3D_H

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <mlx.h>
#include <X11/keysym.h>

#include <stdlib.h>
#include <stdio.h>//temp
#include <fcntl.h>//for files 

//only .xpm files are allowed but not sure what size to use
typedef enum e_texture_enum
{
	NO = 0,
	SO = 1,
	EA = 2,
	WE = 3,
	F = 4,
	C = 5

} t_texture_enum;


typedef struct s_texture
{
	int		floor[3];
	int		ceiling[3];
	char	*wall_textures[4];
	char	*floor_ceiling[2];

}	t_texture;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;

}	t_window;

//check_file
int charcount(char needle, char *haystack);
char *ft_rstrstr(char *needle, char *haystack, int needlen);

//read_file
char *read_file(char *file, t_texture *texture);

//helper
char	*ft_strdup_nl(const char *src);
void	print_err(char *str);

//mlx_handlers
int hook_close_window(int keycode, t_window *window);
int key_hook(int keycode, t_window *window);
//void initialize_mlx(); (from main)

#endif
