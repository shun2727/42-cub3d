/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:09:27 by selow             #+#    #+#             */
/*   Updated: 2026/10/01 18:09:28 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
// Init func on my side, storing everything into my own struct
// start drawing a square and the player 
// 

//temp
int	close_window(t_render *r)
{
	//free_vars(vars);
	(void)r; // temp due to free vars being commented out and -Wextra hates me
	exit(0); 
}
int	key_hook(int keycode, t_render *r)
{
	if (keycode == ESC_KEY)
		close_window(r);
	return (0);
}


void	init_ray(t_render *r, int x)
{
    r->ray.camera_x = 2.0 * x / r->win.width - 1.0;

    r->ray.dir_x = r->player.dir_x
        + r->player.plane_x * r->ray.camera_x;
    r->ray.dir_y = r->player.dir_y
        + r->player.plane_y * r->ray.camera_x;

    r->ray.map_x = (int)r->player.x;
    r->ray.map_y = (int)r->player.y;

    r->ray.delta_dist_x = ft_fabs(1.0 / r->ray.dir_x);
    r->ray.delta_dist_y = ft_fabs(1.0 / r->ray.dir_y);

    r->ray.step_x = r->ray.dir_x < 0 ? -1 : 1;
    r->ray.step_y = r->ray.dir_y < 0 ? -1 : 1;

    if (r->ray.dir_x < 0)
        r->ray.side_dist_x =
            (r->player.x - r->ray.map_x) * r->ray.delta_dist_x;
    else
        r->ray.side_dist_x =
            (r->ray.map_x + 1.0 - r->player.x) * r->ray.delta_dist_x;

    if (r->ray.dir_y < 0)
        r->ray.side_dist_y =
            (r->player.y - r->ray.map_y) * r->ray.delta_dist_y;
    else
        r->ray.side_dist_y =
            (r->ray.map_y + 1.0 - r->player.y) * r->ray.delta_dist_y;
}

void	draw_wall_column(t_render *r, int x)
{
    int	y;

    y = 0;
    while (y < r->ray.draw_start)
    {
        put_pixel(r, x, y, r->texture->ceiling_color);
        y++;
    }
    while (y <= r->ray.draw_end)
    {
        put_pixel(r, x, y, wall_color(r));
        y++;
    }
    while (y < WIN_HEIGHT)
    {
        put_pixel(r, x, y, r->texture.floor_color);
        y++;
    }
}

void	draw_background(t_render *r)
{
	int	ceiling_color;
	int	floor_color;

	ceiling_color = rgb_to_int(r->texture.ceiling);
	floor_color = rgb_to_int(r->texture.floor);
	draw_ceiling_or_floor(r, 0, WIN_HEIGHT / 2, ceiling_color);
	draw_ceiling_or_floor(r, WIN_HEIGHT / 2, WIN_HEIGHT, floor_color);
}

void	render_frame(t_render *r)
{
    int	x;

    draw_background(r);

	// rendering the foreground or target (wall -w-)
    x = 0;
    while (x < WIN_WIDTH)
    {
        init_ray(r, x); 
        perform_dda(r);
        calculate_wall_distance(r);
        draw_wall_column(r, x);
        x++;
    }
}


int	game_loop(t_render *r)
{
    refresh_player(r); // checking for player movement
    render_frame(r); //  
    mlx_put_image_to_window(
        r->win.mlx, r->win.mlx_win, r->img.ptr, 0, 0
    );
    return (0);
}

int	render(t_texture *t)
{
	t_render	r;
	init_renderer_side(&r, t, "Cub3D");
	
	// actually putting everythign together
	// mlx_put_image_to_window(r.win.mlx, r.win.mlx_win, r.img.ptr, 0, 0);

	// main game logic starts here
	mlx_loop_hook(r.win.mlx, game_loop, &r);
	mlx_key_hook(r.win.mlx_win, key_hook, &r);
	mlx_hook(r.win.mlx_win, CLOSE, 1L << 1, close_window, &r);
	mlx_loop(r.win.mlx);

	return 0;
}
