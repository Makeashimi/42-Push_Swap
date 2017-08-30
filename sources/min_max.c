/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 12:01:58 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/24 14:45:07 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	previous_max(t_ps *ps)
{
	int		i;
	int		o;

	i = 0;
	while (i < ps->size_b)
	{
		if (ps->b[i] < ps->max)
		{
			ps->lmax = ps->b[i];
			o = 0;
			while (o < ps->size_b)
			{
				if (ps->b[o] > ps->lmax && ps->b[o] < ps->max)
					ps->lmax = ps->b[o];
				o++;
			}
			return ;
		}
		i++;
	}
}

void	check_max(t_ps *ps)
{
	int		i;

	i = 0;
	ps->max = ps->b[i];
	while (i < ps->size_b)
	{
		if (ps->b[i] > ps->max)
		{
			ps->pos = i;
			ps->max = ps->b[i];
		}
		i++;
	}
}

void	previous_min(t_ps *ps)
{
	int		i;
	int		o;
	int		try;

	i = 0;
	try = 0;
	while (i < ps->size_a)
	{
		if (ps->a[i] > ps->min)
		{
			try = ps->a[i];
			o = 0;
			while (o < ps->size_a)
			{
				if (ps->a[o] < try && ps->a[o] > ps->min)
					try = ps->a[o];
				o++;
			}
			ps->min = try;
			return ;
		}
		i++;
	}
}

void	check_min(t_ps *ps)
{
	int		i;

	i = 0;
	ps->min = ps->a[i];
	while (i < ps->size_a)
	{
		if (ps->a[i] < ps->min)
		{
			ps->pos = i;
			ps->min = ps->a[i];
		}
		i++;
	}
}
