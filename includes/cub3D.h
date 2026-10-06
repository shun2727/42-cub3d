#ifndef	CUB3D_H
#define CUB3D_H

#define MAP_SIZE 102

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <mlx.h>
#include <X11/keysym.h>

#include <stdlib.h>
#include <stdbool.h>
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

typedef enum e_fulfilled_flag
{
	CHECKING_FILE_TEXTURE = 0,
	MAP_ERROR = 1,
	TEXTURE_ERROR = 2,
	FULFILLED_FILE = 3,
	CHECKING_MAP_CONTENT = 4

}  t_fulfilled_flag;

typedef enum e_map_flag
{
	BEFORE_MAP_CHECKING = 0,
	DURING_MAP_CHECKING = 1,
	AFTER_MAP_CHECKING = 2

}  t_map_flag;

typedef struct s_texture
{
	int		floor[3];
	int		ceiling[3];
	char	*wall_textures[4];
	char	*floor_ceiling[2];
	char	map[MAP_SIZE][MAP_SIZE];
	
	int		player_x;
	int		player_y;
	char	player_dir;

}	t_texture;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;

}	t_window;

//helper_functions
int 	chr_count(char needle, char *haystack);
char 	*ft_rstrstr(char *needle, char *haystack, int needlen);
char	*ft_strdup_nl(const char *src);
void	print_err(char *str);
bool	is_blank_line(char *str);

//decision tree realted functions
int		read_file(char *file, t_texture *texture);
int		flag_check(int *flag, t_texture *texture);
void	read_file_map(int *flag, char *str, t_texture *texture);
void	read_file_texture(int *flag, char *str, t_texture *texture, int *texture_count);

//texture_parsing
int		feed_texture(char *str, t_texture *texture, char **texture_compare);
int		validate_texture(t_texture *texture);
int		extract_int(char *str, char *start, char *end);
int		assign_rgb_value(int arr[3], char *str);
void	init_texture_compare(char **texture_compare);

//path_parsing
void	init_map_texture(char map_texture[8]);
int		check_map_texture(char *str);
int		feed_map(char (*map)[MAP_SIZE][MAP_SIZE], char *str, t_texture *texture);
int		validate_map(char (*ori_map)[MAP_SIZE][MAP_SIZE],t_texture *texture);
int		match_direction(char dir);

//validate_map_path.c
void	dup_map(char ori_map[MAP_SIZE][MAP_SIZE], char (*map_copy)[MAP_SIZE][MAP_SIZE]);
void	flood_outside_map(int row, int col, char (*map)[MAP_SIZE][MAP_SIZE]); 
int		flood_inside_map (int row, int col, char (*map)[MAP_SIZE][MAP_SIZE]);
bool	is_inside(int row, int col, char map[MAP_SIZE][MAP_SIZE]);
bool	is_outside(int row, int col, char map[MAP_SIZE][MAP_SIZE]);

//debugger
void	print_map_debug(char map[MAP_SIZE][MAP_SIZE]);
void	print_struct_debug(t_texture *texture);

//clean up
void	free_texture(t_texture *texture);

//mlx_handlers
int		hook_close_window(int keycode, t_window *window);
int		key_hook(int keycode, t_window *window);

//void initialize_mlx(); (from main)
#endif
