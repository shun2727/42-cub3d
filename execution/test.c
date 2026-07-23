
// struct probably looking like this

typedef struct s_game
{
    char **map;

    int map_width;
    int map_height;

    t_player player;
    t_texture textures[4];

    void *mlx;
    void *win;
    void *img;

} t_game;


