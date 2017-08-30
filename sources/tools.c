/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 12:09:50 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/24 16:48:26 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a(t_ps *ps, int pos, int med, int var)
{
	if (pos <= med)
	{
		while (ps->a[0] != var)
		{
			ra(ps);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (ps->a[0] != var)
		{
			rra(ps);
			ft_printf("rra\n");
		}
	}
}

void	move_b2(t_ps *ps, int var)
{
	while (ps->b[0] != var)
	{
		if (ps->b[0] == ps->lmax)
		{
			pa(ps);
			ft_printf("pa\n");
		}
		else
		{
			rrb(ps);
			ft_printf("rrb\n");
		}
	}
}

void	move_b(t_ps *ps, int pos, int med, int var)
{
	if (pos <= med)
	{
		while (ps->b[0] != var)
		{
			if (ps->b[0] == ps->lmax)
			{
				pa(ps);
				ft_printf("pa\n");
			}
			else
			{
				rb(ps);
				ft_printf("rb\n");
			}
		}
	}
	else
		move_b2(ps, var);
}

void	rewrite_order(t_ps *ps)
{
	int		o;

	if (!(ps->tab = ft_taballoc(ps->tab, ps->size_a * sizeof(int))))
		ft_error("Malloc error");
	tabset(ps->tab, ps->size_b, ps->size_a);
	check_min(ps);
	o = 1;
	while (o != ps->size_a)
		o = write_order(ps, o);
}

int		write_order(t_ps *ps, int o)
{
	int		i;

	i = 0;
	previous_min(ps);
	while (i < ps->size_a)
	{
		if (ps->a[i] == ps->min)
		{
			ps->tab[i] = o + ps->size_b;
			o++;
		}
		i++;
	}
	return (o);
}
