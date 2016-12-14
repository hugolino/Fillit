/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:16:26 by hdecaux           #+#    #+#             */
/*   Updated: 2016/11/14 14:51:09 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# define BUFF_SIZE 545
# define X_P cd->x_p
# define Y_P cd->y_p
# define NB_P cd->nb_p
# define NB_L cd->nb_l
# define MAP cd->map
# define TAB cd->tab
# define COTE cd->cote
# define BUF cd->buf
# define NEWYM Y_P + pmap->i
# define NEWXM X_P + pmap->j
# define TABCT tab[ct.i][ct.j]
# define LET tetri->let
# define TETRI tetri->tetri
# define NEXT tetri->next
# define LEN tetri->len
# define BEGIN cd->begin_list
# define LAR tetri->larg
# define RET cd->ret
# define FD cd->fd

typedef struct		s_int
{
	int i;
	int j;
	int k;
}					t_int;

typedef	struct		s_etri
{
	char			**tetri;
	char			let;
	int				len;
	int				larg;
	struct s_etri	*next;
}					t_etri;

typedef struct		s_coord
{
	int				x_p;
	int				y_p;
	int				cote;
	int				fd;
	int				ret;
	size_t			nb_p;
	size_t			nb_l;
	char			*buf;
	char			**tab;
	char			**map;
	struct s_etri	*begin_list;
}					t_coord;

void				ft_errors(int ret, char *buf, char **tab);
int					ft_dot(char *buf);
int					ft_chrn(char *buf);
int					ft_col(char *buf);
int					ft_diese(char **tab, char *buf);
char				**ft_bufcpy(char *buf, t_coord *cd);
int					ft_countl(char *buf);
void				ft_putstr(char const *str);
char				**ft_malloc_tab(char **tab, char *buf);
int					ft_valid(char **tab, char *buf);
int					ft_check_first(char **tab, int i);
int					ft_check_last(char **tab, int i);
int					ft_check_lines(char **tab, int i);
char				*ft_lhorl(char **tab, char *buf, int *pieces, int *f);
char				*ft_lhorr(char **tab, char *buf, int *pieces, int *f);
char				*ft_lverr(char **tab, char *buf, int *pieces, int *f);
char				*ft_lverl(char **tab, char *buf, int *pieces, int *f);
char				*ft_square(char **tab, char *buf, int *pieces, int *f);
char				*ft_lrevhorl(char **tab, char *buf, int *pieces, int *f);
char				*ft_lrevhorr(char **tab, char *buf, int *pieces, int *f);
char				*ft_lrevverr(char **tab, char *buf, int *pieces, int *f);
char				*ft_lrevverl(char **tab, char *buf, int *pieces, int *f);
char				*ft_line_hor(char **tab, char *buf, int *pieces, int *f);
char				*ft_line_ver(char **tab, char *buf, int *pieces, int *f);
char				*ft_s(char **tab, char *buf, int *pieces, int *f);
char				*ft_s_up(char **tab, char *buf, int *pieces, int *f);
char				*ft_z(char **tab, char *buf, int *pieces, int *f);
char				*ft_z_up(char **tab, char *buf, int *pieces, int *f);
char				*ft_t(char **tab, char *buf, int *pieces, int *f);
char				*ft_t_left(char **tab, char *buf, int *pieces, int *f);
char				*ft_t_right(char **tab, char *buf, int *pieces, int *f);
char				*ft_t_up(char **tab, char *buf, int *pieces, int *f);
char				*ft_trim(char **tab, char *buf, int *pieces, int *found);
char				*ft_sub_trim(char **tab, char *buf);
void				ft_count_pieces(t_coord *cd);
char				**ft_cpy_tab(char **tab2, t_coord *cd);
char				*ft_test_l(char **tab, char *buf, int *pieces, int *f);
char				*ft_test_t(char **tab, char *buf, int *pieces, int *f);
char				**ft_map_creator(size_t cotes);
int					ft_check_tetri(t_coord *cd, t_etri *tetri, t_int *pmap);
void				ft_place(t_coord *cd, t_etri *tetri, char c, t_int *pmap);
void				ft_prepare_algo(t_coord *cd, t_etri *tetri);
int					ft_resolve(t_coord *cd, t_etri *tetri);
t_etri				*ft_add_list(t_coord *cd, t_etri *tetri, size_t *j);
t_etri				*ft_make_list(t_coord *cd);
char				*ft_cpy_tetri(t_coord *cd, size_t *j);
void				ft_cpy_first(t_coord *cd, t_etri *tetri, size_t *j);
int					ft_sqrt(int nbr);
void				ft_read_count(char *argv, t_coord *cd);

#endif
