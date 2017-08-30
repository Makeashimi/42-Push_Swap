/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:40:26 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/24 17:22:37 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 2 > 1 > 0 > -1 > -2
** -2147483647 > -2147483648
*/

void	init_param(t_ps *ps, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		ps->sa = 1;
	else if (ft_strcmp(str, "sb") == 0)
		ps->sb = 1;
	else if (ft_strcmp(str, "ss") == 0)
		ps->ss = 1;
	else if (ft_strcmp(str, "pa") == 0)
		ps->pa = 1;
	else if (ft_strcmp(str, "pb") == 0)
		ps->pb = 1;
	else if (ft_strcmp(str, "ra") == 0)
		ps->ra = 1;
	else if (ft_strcmp(str, "rb") == 0)
		ps->rb = 1;
	else if (ft_strcmp(str, "rr") == 0)
		ps->rr = 1;
	else if (ft_strcmp(str, "rra") == 0)
		ps->rra = 1;
	else if (ft_strcmp(str, "rrb") == 0)
		ps->rrb = 1;
	else if (ft_strcmp(str, "rrr") == 0)
		ps->rrr = 1;
	else
		ft_error("Error");
}

void	write_ok_ko(t_ps *ps)
{
	int		i;

	i = 0;
	while (i < ps->size_a)
	{
		if (i > 0 && ps->a[i - 1] > ps->a[i])
		{
			ft_printf("KO\n");
			exit(0);
		}
		i++;
	}
	ft_printf("OK\n");
}

void	init_all(t_ps *ps)
{
	ps->a = NULL;
	ps->b = NULL;
	ps->tab = NULL;
	ps->size_a = 0;
	ps->size_b = 0;
	ps->size_a = 0;
	ps->size_b = 0;
	ps->sa = 0;
	ps->sb = 0;
	ps->ss = 0;
	ps->pa = 0;
	ps->pb = 0;
	ps->ra = 0;
	ps->rb = 0;
	ps->rr = 0;
	ps->rra = 0;
	ps->rrb = 0;
	ps->rrr = 0;
	ps->min = 0;
	ps->max = 0;
	ps->pos = 0;
	ps->lpos = 0;
	ps->lmax = 0;
	ps->lines = 0;
	ps->val = 0;
}

int		main(int argc, char **argv)
{
	t_ps	ps;
	char	*str;

	init_all(&ps);
	check_error(&ps, argc, argv);
	if (ft_strcmp(argv[0], "./checker") == 0)
	{
		while (get_next_line(0, &str) == 1)
		{
			init_param(&ps, str);
			move_tabs_first(&ps);
			ft_strdel(&str);
		}
		write_ok_ko(&ps);
	}
	else
	{
		push_swap(&ps);
		ft_memdel((void**)&ps.a);
		ft_memdel((void**)&ps.b);
		ft_memdel((void**)&ps.tab);
	}
	return (0);
}
