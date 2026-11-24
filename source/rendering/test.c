#include "render.h"


t_texture data1 = {
    .floor = {50, 50, 50},
    .ceiling = {100, 100, 150},

    .wall_textures = {
        "../../tester_files/N.xpm",
        "../../tester_files/S.xpm",
        "../../tester_files/E.xpm",
        "../../tester_files/W.xpm"
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
        "../../tester_files/N.xpm",
        "../../tester_files/S.xpm",
        "../../tester_files/E.xpm",
        "../../tester_files/W.xpm"
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
	
	texture = data2;
	
	render(&texture);


	return (0);
}


