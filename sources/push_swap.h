/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:09:48 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/24 17:01:38 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_ps	t_ps;

struct		s_ps
{
	int		*a;
	int		*b;
	int		*tab;
	int		size_a;
	int		size_b;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		min;
	int		max;
	int		lmax;
	int		pos;
	int		lpos;
	int		val;
	int		lines;
};

void		check_error(t_ps *ps, int argc, char **argv);
void		move_tabs_first(t_ps *ps);
void		s_move(int len, int *tab);
int			pa(t_ps *ps);
int			pb(t_ps *ps);
int			ra(t_ps *ps);
int			rb(t_ps *ps);
int			rra(t_ps *ps);
int			rrb(t_ps *ps);
void		push_swap(t_ps *ps);
void		selection_sort_improved(t_ps *ps);
int			check_sort(t_ps *ps);
int			write_order(t_ps *ps, int o);
void		rewrite_order(t_ps *ps);
void		value(t_ps *ps);
void		compare_value(t_ps *ps, int limit, int med, int var);
void		check_min(t_ps *ps);
void		previous_min(t_ps *ps);
void		previous_max(t_ps *ps);
void		check_max(t_ps *ps);
void		move_a(t_ps *ps, int pos, int med, int var);
void		move_b(t_ps *ps, int pos, int med, int var);

#endif
