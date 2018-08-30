/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:34:43 by sgarcia           #+#    #+#             */
/*   Updated: 2018/08/30 17:36:11 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/src/libft.h"

typedef	struct		s_ptr t_ptr;
typedef	struct		s_room t_room;
typedef	struct		s_path t_path;
typedef	struct		s_ant t_ant;
typedef	struct		s_poss t_poss;

typedef	struct		s_poss
{
	int				id_poss;
	int				nb_path;
	int				total_power;
	t_ptr			*id_path;
	struct s_poss	*next;
}					t_poss;

typedef	struct		s_room
{
	int				check;
	int				last_room;
	char			*name;
	t_ptr			*id_path;
	t_ptr			*tube;
}					t_room;

typedef	struct		s_ptr
{
	int				id;
	t_room			*ptr_room;
	t_path			*ptr_path;
	struct s_ptr	*back;
	struct s_ptr	*next;
}					t_ptr;

typedef	struct		s_path
{
	int				id;
	int				power;
	t_ptr			*id_path;
	t_ptr			*room;
}					t_path;

typedef	struct		s_ant
{
	int				i;
	int				j;
	int				power;
	int				check;
	int				nb_ant;
	int				nb_path;
	int				*tab_id;
	char			*line;
	t_poss			*poss;
	t_room			*start;
	t_room			*end;
	t_ptr			*path;
	t_ptr			*room;
}					t_ant;


int					main(void);
t_ant				init_room(t_ant ant);
t_ant				comment(t_ant ant);
t_ant				command(t_ant ant);
int					verif_name(t_ant ant, char *name2);
t_ant				init_ant(t_ant ant);
t_ant				init_tab(t_ant ant);
t_ant				find_final_room(t_ant ant);
t_ant				deep_way(t_ant ant);
t_ant				put_id_path(t_ant ant);
t_ant				possibility(t_ant ant);

#endif
