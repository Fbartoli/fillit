/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:08:14 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/28 14:22:34 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"


typedef struct s_point
{
	char		piece[5][5];
	int 		xy[4][2];
	int			width;
	int			length;
	char 		lettre;
} 				t_etris;

typedef struct s_map
{
	char		map[16][16];
	int 		current_xy[2];
	int			nb_tot_tetris;
	int			nb_piece_placed;
	int			position_piece[26][2];
	int			size_map;
} 				t_map;

int			print_error(void);
int			print_usage(void);
void		print_tetris(t_etris tetris[27]);
void        print_detailed_tetris(t_etris tetris[27]);
int			input_to_tetris(int fd, t_etris tetris[27]);
int			check_tetris(t_etris tetris[27]);
int			relative_position(char ***tetris);
int			init_map(t_map *map);
void        canonic_form(t_etris tetris[27], t_map *map);
int			is_available_map(t_etris *tetris, t_map *map);
void		print_map(t_map *map);
int			put_in_map(t_etris *tetris, t_map *map);
int			delete_tetris(t_etris *tetris, t_map *map);
#endif
