/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_improved.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:09:25 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/24 16:44:58 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		go_b(t_ps *ps)
{
	int		med;

	med = ps->size_a / 2;
	check_min(ps);
	move_a(ps, ps->pos, med, ps->min);
	pb(ps);
	ft_printf("pb\n");
}

static void		go_a(t_ps *ps)
{
	int		med;

	med = ps->size_b / 2;
	check_max(ps);
	previous_max(ps);
	move_b(ps, ps->pos, med, ps->max);
	pa(ps);
	ft_printf("pa\n");
}

void			selection_sort_improved(t_ps *ps)
{
	int		lencopy;
	int		limit;
	int		o;

	o = 1;
	limit = 0;
	lencopy = ps->size_a;
	check_min(ps);
	while (o != ps->size_a)
		o = write_order(ps, o);
	value(ps);
	while (check_sort(ps) && limit + ps->val < lencopy)
	{
		limit = limit + ps->val;
		compare_value(ps, limit, ps->size_a / 2, ps->val);
	}
	while (check_sort(ps) && ps->size_a != 0)
		go_b(ps);
	while (ps->size_b != 0)
	{
		go_a(ps);
		if (ps->a[0] > ps->a[1])
		{
			s_move(ps->size_a, ps->a);
			ft_printf("sa\n");
		}
	}
}
