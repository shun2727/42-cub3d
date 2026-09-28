
// struct probably looking like this

// typedef struct s_game
// {
//     char **map;

//     int map_width;
//     int map_height;

//     t_player player;
//     t_texture textures[4];

//     void *mlx;
//     void *win;
//     void *img;

// } t_game;

#include "test.h"





int	main(void)
{
	t_vars	*vars;
	// char **argv = map;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);

	// temporary testing
	vars->map.width = 10; // temporary test value


	// parse_arg(argv, argc, vars); // original code; not needed; thus commented

	init_everything(vars, "Testing title");
	render_map(vars); // main func to for rendering
	free_vars(vars);
	return (0);
}






/*

// ① 画面上の位置
camera_x = ...;

// ② この列のRay方向
ray_dir_x = dir_x + plane_x * camera_x;
ray_dir_y = dir_y + plane_y * camera_x;

// ③ Rayの左右・上下の進む向き
step_x = ...;
step_y = ...;

// ④ DDAの準備
delta_dist_x = ...;
delta_dist_y = ...;
side_dist_x = ...;
side_dist_y = ...;

// ⑤ DDA
while (!hit)
{
    if (side_dist_x < side_dist_y)
    {
        side_dist_x += delta_dist_x;
        map_x += step_x;
        side = 'x';
    }
    else
    {
        side_dist_y += delta_dist_y;
        map_y += step_y;
        side = 'y';
    }

    if (map[map_y][map_x] == '1')
        hit = 1;
}

// ⑥ 壁までの正面距離
perp_wall_dist = ...;

// ⑦ 壁の高さ
line_height = screen_height / perp_wall_dist;

// ⑧ 描画範囲
wall_top = ...;
wall_bottom = ...;


camera_x
   ↓
ray_dir
   ↓
step
   ↓
DDA
   ↓
hit
   ↓
perp_wall_dist
   ↓
line_height
   ↓
wall_top / wall_bottom
   ↓
描画
*/





