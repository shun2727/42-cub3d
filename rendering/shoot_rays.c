/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 19:52:53 by selow             #+#    #+#             */
/*   Updated: 2026/10/05 19:52:56 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

// shoots only one ray in a certain direction
// Returns the location of the wall that it hit
// It uses the DDA algoritmn to shoot a ray
int	shoot_ray(t_render *r)
{
	double	wall;

	// rayDir = direction + cameraPlane * cameraX
	calculate_raydir(r);

	wall = dda();
	// shoot the actual ray until it hits a wall; dda is just a loop checking if the ray has hit a wall yet
	return (wall);
}

/*
double side_dist_x
double side_dist_y
double delta_dist_x
double delta_dist_y
int map_x
int map_y
int step_x
int step_y

double raydir_x
double raydir_y
double plane_len
double plane_x
double plane_y
*/

void	calculate_raydir(t_render *r)
{
	// getting ready for the ray to be shot
	// camera pos, ray dir, map pos, ΔDist, steps
	double	camera_x = 2.0 * r->player.x / WIN_WIDTH - 1.0;

	// ② この列のRay方向
	double	ray_dir_x = r->player.dir_x + r->player.plane_x * camera_x;
	double 	ray_dir_y = r->player.dir_y + r->player.plane_y * camera_x;


	double	plane_len = tan(FOV / 2);

	double	plane_x = -(r->player.dir_y) * plane_len;
	double 	plane_y =  r->player.dir_x * plane_len;

	// ④ DDAの準備
	double 	delta_dist_x = 1.0 / fabs(ray_dir_x);
	double 	delta_dist_y = 1.0 / fabs(ray_dir_y);
	
	int 	map_x = (int)r->player.x;
	int 	map_y = (int)r->player.y;

	// Decide step direction (+1 or -1)
	// We must determine if the ray moves left/right and up/down, based on the ray angle:
	// This tells DDA which direction to step in each axis during traversal.
	// ③ Rayの左右・上下の進む向き
	// Rayが進む方向
	// for initialising 
	if (ray_dir_x < 0)
	{
		int 	step_x = -1;
		double 	side_dist_x = (r->player.x - map_x) * delta_dist_x;
	}
	else
	{
		int 	step_x = 1;
		double 	side_dist_x = (map_x + 1.0 - r->player.x) * delta_dist_x;
	}

	if (ray_dir_y < 0)
	{
		int 	step_y = -1;
		double 	side_dist_y = (r->player.y - map_y) * delta_dist_y;
	}
	else
	{
		int 	step_y = 1;
		double 	side_dist_y = (map_y + 1.0 - r->player.y) * delta_dist_y;
	}
}


void	dda(t_render *r)
{
	// DDA PREP
	// where the ray starts
	// Convert player’s position to grid cell coordinates
	r->player.x = (int)(r->player.y / GRID_CELL_SIZE);  // Column in the map grid
	r->player.y = (int)(r->player.x / GRID_CELL_SIZE);  // Row in the map grid

	/*
	Calculate initial distance to the first vertical/horizontal grid line
	We now compute how far the ray must travel from the player’s current position to reach the first vertical and horizontal grid lines.

	For vertical lines (X steps):
	This gives distance from current position to the next vertical grid boundary in the direction of the ray.
	*/
	if (x_step == -1)
		dda.x_dist = (player->y / 64 - dda.x) * dda.x_line_length;
	else
		dda.x_dist = (dda.x + 1 - player->y / 64) * dda.x_line_length;
	/*
	For horizontal lines (Y steps):
	Same idea, but for horizontal intersections.
	These distances are the starting points for DDA traversal.
	*/
	if (y_step == -1)
		dda.y_dist = (player->x / 64 - dda.y) * dda.y_line_length;
	else
		dda.y_dist = (dda.y + 1 - player->x / 64) * dda.y_line_length;


}

double	dda(t_render *r)
{
	int	hit;

	hit = 0;
	// ⑤ DDA
	while (!hit)
	{
		if (r->ray.side_dist_x < r->ray.side_dist_y)
		{
			r->ray.side_dist_x += r->ray.delta_dist_x;
			r->ray.map_x += r->ray.step_x;
			r->ray.wall_hit = 'x';
		}
		else
		{
			r->ray.side_dist_y += r->ray.delta_dist_y;
			r->ray.map_y += r->ray.step_y;
			r->ray.wall_hit = 'y';
		}

		if (r->texture.map[r->ray.map_y][r->ray.map_x] == '1')
			hit = 1;
	}
}

/*
camera_x
↓
ray_dir
↓
map position
↓ 
deltaDist
↓
step
↓
sideDist
↓
DDA
↓
wall hit

Return the wall hit




1本のRayを計算する流れ
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
*/