
#include "render.h"

int 	draw_wall(t_render *r)
{
	// ⑥ 壁までの正面距離
	perp_wall_dist = ...;

	// ⑦ 壁の高さ
	line_height = screen_height / perp_wall_dist;

	// ⑧ 描画範囲
	wall_top = ...;
	wall_bottom = ...;
}
