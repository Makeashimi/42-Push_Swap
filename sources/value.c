/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:25:46 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/24 16:40:24 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			value(t_ps *ps)
{
	if (ps->size_a < 250)
		ps->val = 19;
	else
		ps->val = 70;
}

static int		get_diff_begin(t_ps *ps, int limit)
{
	int		i;

	i = 0;
	while (i < ps->size_a)
	{
		if (ps->tab[i] < limit)
		{
			ps->pos = i;
			return (i);
		}
		i++;
	}
	return (0);
}

static int		get_diff_end(t_ps *ps, int limit)
{
	int		o;

	o = ps->size_a - 1;
	while (o >= 0)
	{
		if (ps->tab[o] < limit)
		{
			ps->lpos = o;
			return (o);
		}
		o--;
	}
	return (0);
}

void			compare_value(t_ps *ps, int limit, int med, int var)
{
	int		i;
	int		o;
	int		num;

	num = var;
	while (num > 0)
	{
		i = get_diff_begin(ps, limit);
		o = get_diff_end(ps, limit);
		if (i <= (ps->size_a - o))
		{
			move_a(ps, ps->pos, med, ps->a[i]);
			pb(ps);
			ft_printf("pb\n");
			rewrite_order(ps);
		}
		else
		{
			move_a(ps, ps->lpos, med, ps->a[o]);
			pb(ps);
			ft_printf("pb\n");
			rewrite_order(ps);
		}
		num--;
	}
}
