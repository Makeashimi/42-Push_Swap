/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 12:10:28 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/24 16:48:16 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				check_sort(t_ps *ps)
{
	int		i;

	i = 0;
	while (i + 1 < ps->size_a)
	{
		if (ps->a[i] > ps->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static void		selection_sort_classic(t_ps *ps)
{
	int		med;

	check_min(ps);
	med = ps->size_a / 2;
	if (ps->pos <= med)
	{
		while (ps->a[0] != ps->min)
		{
			if (ra(ps))
				break ;
			ft_printf("ra\n");
		}
	}
	else
		while (ps->a[0] != ps->min)
		{
			if (rra(ps))
				break ;
			ft_printf("rra\n");
		}
	if (check_sort(ps))
	{
		pb(ps);
		ft_printf("pb\n");
	}
}

void			push_swap(t_ps *ps)
{
	if (check_sort(ps))
	{
		if (ps->size_a >= 20)
		{
			if (!(ps->tab = (int*)malloc(sizeof(int) * ps->size_a)))
				ft_error("Malloc error");
			cleartab(ps->tab, ps->size_a);
			selection_sort_improved(ps);
		}
		else
		{
			if (ps->a[0] > ps->a[1])
			{
				s_move(ps->size_a, ps->a);
				ft_printf("sa\n");
			}
			while (ps->size_a != 0 && check_sort(ps))
				selection_sort_classic(ps);
			while (ps->size_b != 0)
			{
				pa(ps);
				ft_printf("pa\n");
			}
		}
	}
}
