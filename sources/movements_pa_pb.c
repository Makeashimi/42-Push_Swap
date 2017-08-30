/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_pa_pb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:15:27 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/24 17:03:23 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		decrease_tab(int *tab, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		tab[i] = tab[i + 1];
		i++;
	}
}

static void		increase_tab(int *tab, int len)
{
	int		i;

	i = len;
	tab[i] = 0;
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
}

int				pa(t_ps *ps)
{
	if (ps->size_b == 0)
		return (1);
	if (!(ps->a = ft_taballoc(ps->a, sizeof(int) * ps->size_a + 1)))
		ft_error("Malloc error");
	increase_tab(ps->a, ps->size_a);
	ps->size_a++;
	ps->a[0] = ps->b[0];
	if (ps->size_b > 1)
		decrease_tab(ps->b, ps->size_b);
	ps->size_b--;
	return (0);
}

int				pb(t_ps *ps)
{
	if (ps->size_a == 0)
		return (1);
	if (!(ps->b = ft_taballoc(ps->b, sizeof(int) * ps->size_b + 1)))
		ft_error("Malloc error");
	increase_tab(ps->b, ps->size_b);
	ps->size_b++;
	ps->b[0] = ps->a[0];
	decrease_tab(ps->a, ps->size_a);
	ps->size_a--;
	return (0);
}
