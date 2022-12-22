/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:39:33 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/22 15:35:56 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 400

//*start Libft functions
int			ft_strncmp(char *s1, char *s2, unsigned int n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin_split(char *s1, char *s2);
char		*ft_substr_split(char *s, unsigned int start, size_t len);
char		**ft_split(char *s, char sep);
//*start Libft functions

// *start printf functions
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			count_nbr(unsigned long nbr, int bs, int sign);
int			ft_putnbr(long int nbr);
int			ft_putnbr_hex(unsigned long nbr, char bs);
size_t		ft_strlen(const char *str);
int			ft_printf(const char *str, ...);
// *end printf functions

// *start Get next line functions
int			ft_strchr(char *str);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char **s, char *buff);
char		*get_next_line(int fd);
// *END Get next line functions

typedef struct s_data
{
	void	*img_player;
	void	*img_wall;
	void	*img_gr;
	void	*img_collect;
	void	*img_exit;
	int		width;
	int		height;
}			t_img;

typedef struct s_map
{
	char	**data_map;
	void	*player;
	void	*wall;
	void	*collect;
	void	*exit;
	int		width;
	int		height;
	int		player_x;
	int		player_y;

}			t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

// so long
int			ft_check_map_path(char *map_path);
int			key_hook_press(int keycode, void *param);
int			ft_error(void);
void		check_player_position(t_map *map);
int			check_line_length(t_map *map);
int			check_square(t_map *map);
int			map(t_map *map, char *argv);
void		render_map(t_img *img, t_vars *vars, char *argv);
int check_one_p_e_c(t_map *map);

#endif