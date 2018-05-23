/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:38:56 by bspindle          #+#    #+#             */
/*   Updated: 2018/04/11 09:28:16 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "keycodes.h"
# include "libft.h"
# include "libgraph.h"
# include "get_next_line.h"
# include <pthread.h>
# define THREAD_NBR 10

typedef struct	s_texture
{
	void		*img;
	char		*img_str;
	int			bpp;
	int			size_line;
	int			endian;
	int			w;
	int			h;
}				t_texture;

typedef struct	s_spot_pos
{
	int			head_rot;
	double		x;
	double		y;
	double		z;
	double		rotation;
}				t_spot_pos;

typedef struct	s_menu
{
	int			display;
	t_texture	bg;
	t_texture	title;
	int			button;
	t_texture	b_resume;
	t_texture	b_restart;
	t_texture	b_map;
	t_texture	b_exit;
	t_texture	b_map_a;
	t_texture	b_map_b;
	t_texture	b_map_c;
	t_texture	b_return;
	t_texture	selec_l;
	t_texture	selec_r;

}				t_menu;

typedef struct	s_wolf3d_data
{
	char		**map;
	int			map_w;
	int			map_h;
	t_data		*data;
	t_spot_pos	*cam_pos;
	t_texture	gun;
	t_texture	cursor;
	t_texture	*walls;
	t_texture	floor;
	t_texture	roof;
	int			sprint;
	t_texture	p_sprint;
	t_menu		menu;
	int			display_map;
	t_texture	minimap;
}				t_wolf3d_data;

typedef struct	s_wolf_thread
{
	int				thread_nbr;
	t_wolf3d_data	*wolf3d;
}				t_wolf_thread;

double			find_distance(char **map, t_spot_pos p, int x);
double			mod_2pi(double angle);
int				wall_angle_checker(char **map, t_vect_d2 start, double alpha);
t_vect_d2		first_wall_met(char **map, t_vect_d2 hr, double angle);
t_vect_d2		next_wall_right(t_vect_d2 start);
t_vect_d2		next_wall_left(t_vect_d2 start);
t_vect_d2		next_wall_up(t_vect_d2 start);
t_vect_d2		next_wall_down(t_vect_d2 start);
void			free_wolf3d_data(t_wolf3d_data *wolf3d);
t_spot_pos		*find_start_pos(char **map);

/*
**	thread
*/
void			*thread(void *v);
void			draw_actual_view(t_wolf3d_data *wolf3d);

/*
** key hook functions
*/
int				wolf3d_key_hook(int keycode, void *ptr);
void			move_forward(t_wolf3d_data *data);
void			move_backward(t_wolf3d_data *data);
void			move_right(t_wolf3d_data *data);
void			move_left(t_wolf3d_data *data);

/*
**	key move function
*/
int				wolf3d_move_hook(int x, int y, void *wolf3d_data);
int				exit_prog(t_wolf3d_data *wolf);
char			**get_map(char *arg, char *line, t_wolf3d_data *wolf);

/*
**	textures
*/

t_vect_d3		put_wall_texture_n(int x, int y, t_wolf3d_data *data, double d);
t_vect_d3		put_wall_texture_w(int x, int y, t_wolf3d_data *data, double d);
t_vect_d3		put_wall_texture_e(int x, int y, t_wolf3d_data *data, double d);
t_vect_d3		put_wall_texture_s(int x, int y, t_wolf3d_data *data, double d);
t_texture		get_texture(t_wolf3d_data *wolf3d, char *path);
t_texture		*load_walls(t_wolf3d_data *wolf3d);
void			load_all_textures(t_wolf3d_data *wolf3d);

/*
**	anim
*/

float			osci_x(float max, float step);
float			osci_y(float max, float step);
float			trans(float end, float step);

/*
**	menu
*/

void			menu(t_wolf3d_data *wolf);
int				menu_key_hook(int keycode, t_wolf3d_data *wolf);
int				menu_mouse_hook(int button, int x, int y, t_wolf3d_data *wolf);
void			switch_main_button(int x, int y, t_wolf3d_data *wolf);
void			switch_map_button(int x, int y, t_wolf3d_data *wolf);
void			event_main_menu(t_wolf3d_data *wolf);
void			event_map_menu(t_wolf3d_data *wolf);

/*
**	minimap
*/

void			minimap(t_wolf3d_data *wolf);
void			draw_square(char *img_str, t_vect_d2 pos, t_vect_d3 color);
void			alpha_square(char *img_str, t_vect_d2 pos, t_vect_d4 color);
void			draw_circle(char *img_str, t_vect_d2 pos, t_vect_d3 color);

#endif
