#include "render.h"


t_texture data1 = {
    .floor = {50, 50, 50},
    .ceiling = {100, 100, 150},

    .wall_textures = {
        "./textures/north.xpm",
        "./textures/south.xpm",
        "./textures/west.xpm",
        "./textures/east.xpm"
    },

    .map = {
        "111111",
        "100001",
        "100N01",
        "100001",
        "111111"    
	},

    .player_x = 3,
    .player_y = 2
};

t_texture data2 = {
    .floor = {50, 50, 50},
    .ceiling = {100, 100, 150},

    .wall_textures = {
        "./textures/north.xpm",
        "./textures/south.xpm",
        "./textures/west.xpm",
        "./textures/east.xpm"
    },

    .map = {
        "111111",
        "100001",
        "100E01",
        "100001",
        "111111"    
	},

    .player_x = 3,
    .player_y = 2
};

// TAKEN FROM SHUNQI'S PART
// CAN PROBABLY START THE TESTING
int main(void)
{
	t_texture	texture;
	
	texture = data1;
	
	render(&texture);

	// //after reading file then only open window
	// window.mlx = mlx_init();
	// window.mlx_win = mlx_new_window(window.mlx, 1920, 1080, "cub3D");
	
	// //for exit button (mlx_hook is used for mosre specific events as stated by the 17 which is the events)
	// mlx_hook(window.mlx_win, 17, 0, hook_close_window, &window);
	// //for esc button 
	// mlx_key_hook(window.mlx_win, key_hook, &window);
	// mlx_loop(window.mlx);

	return (0);
}


