/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:58:53 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/24 14:45:24 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_move(int len, int *tab)
{
	int		tmp;

	tmp = 0;
	if (len > 1)
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
	}
}

int		ra(t_ps *ps)
{
	int		i;
	int		current;
	int		prev;

	if (ps->size_a < 1)
		return (1);
	i = ps->size_a - 1;
	prev = ps->a[0];
	while (i > 0)
	{
		current = ps->a[i];
		ps->a[i] = prev;
		prev = ps->a[i - 1];
		ps->a[i - 1] = current;
		i = i - 2;
	}
	if (i == 0)
		ps->a[0] = prev;
	return (0);
}

int		rb(t_ps *ps)
{
	int		i;
	int		current;
	int		last;

	if (ps->size_b < 1)
		return (1);
	i = ps->size_b - 1;
	last = ps->b[0];
	while (i > 0)
	{
		current = ps->b[i];
		ps->b[i] = last;
		last = ps->b[i - 1];
		ps->b[i - 1] = current;
		i = i - 2;
	}
	if (i == 0)
		ps->b[0] = last;
	return (0);
}

int		rra(t_ps *ps)
{
	int		i;
	int		next;
	int		tmp;
	int		last;

	if (ps->size_a < 1)
		return (1);
	i = 0;
	last = ps->a[ps->size_a - 1];
	while (i < ps->size_a)
	{
		next = (i + 1) % (ps->size_a);
		tmp = ps->a[next];
		ps->a[next] = ps->a[i];
		ps->a[i] = last;
		last = tmp;
		i = i + 2;
	}
	return (0);
}

int		rrb(t_ps *ps)
{
	int		i;
	int		next;
	int		tmp;
	int		last;

	if (ps->size_b < 1)
		return (1);
	i = 0;
	last = ps->b[ps->size_b - 1];
	while (i < ps->size_b)
	{
		next = (i + 1) % (ps->size_b);
		tmp = ps->b[next];
		ps->b[next] = ps->b[i];
		ps->b[i] = last;
		last = tmp;
		i = i + 2;
	}
	return (0);
}
