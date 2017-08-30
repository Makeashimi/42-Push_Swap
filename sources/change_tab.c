/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 13:30:54 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/24 17:02:11 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		move_tabs_third(t_ps *ps)
{
	if (ps->rr == 1)
	{
		ra(ps);
		rb(ps);
		ps->rr = 0;
	}
	else if (ps->rra == 1)
	{
		rra(ps);
		ps->rra = 0;
	}
	else if (ps->rrb == 1)
	{
		rrb(ps);
		ps->rrb = 0;
	}
	else if (ps->rrr == 1)
	{
		rra(ps);
		rrb(ps);
		ps->rrr = 0;
	}
}

static void		move_tabs_second(t_ps *ps)
{
	if (ps->pb == 1)
	{
		pb(ps);
		ps->pb = 0;
	}
	else if (ps->ra == 1)
	{
		ra(ps);
		ps->ra = 0;
	}
	else if (ps->rb == 1)
	{
		rb(ps);
		ps->rb = 0;
	}
	move_tabs_third(ps);
}

void			move_tabs_first(t_ps *ps)
{
	if (ps->sa == 1)
	{
		s_move(ps->size_a, ps->a);
		ps->sa = 0;
	}
	else if (ps->sb == 1)
	{
		s_move(ps->size_b, ps->b);
		ps->sb = 0;
	}
	else if (ps->ss == 1)
	{
		s_move(ps->size_a, ps->a);
		s_move(ps->size_b, ps->b);
		ps->ss = 0;
	}
	else if (ps->pa == 1)
	{
		pa(ps);
		ps->pa = 0;
	}
	move_tabs_second(ps);
}
