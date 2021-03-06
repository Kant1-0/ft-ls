/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:29:26 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/10 16:32:36 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_sortptr	parser_init_sort(int param)
{
	if (param & (1 << 7))
		return (&sort_no);
	else if ((param & 1) && param & (1 << 8))
		return ((param & (1 << 1)) ? &sort_rev_last_access : &sort_last_access);
	else if ((param & 1) && param & (1 << 9))
		return ((param & (1 << 1)) ? &sort_rev_birth : &sort_birth);
	else if ((param & 1) && param & (1 << 11))
		return ((param & (1 << 1)) ? &sort_rev_lstatchg : &sort_lstatchg);
	else if (param & 1)
		return ((param & (1 << 1)) ? &sort_rev_time : &sort_time);
	else
		return ((param & (1 << 1)) ? &sort_rev_alpha : &sort_alpha);
}

static void			parser_init_empty(t_ls_meta *meta)
{
	meta->targetnb = 1;
	if ((meta->target = (char **)malloc(sizeof(char *))) &&
	((meta->target)[0] = ft_strnew(2)))
	{
		(meta->target)[0][0] = '.';
		(meta->target)[0][1] = 0;
	}
	else
		meta->targetnb = 0;
	meta->sortfunc = parser_init_sort(meta->param);
}

static int			parser_add_param(t_ls_meta *meta, char *arg)
{
	register int	i;

	i = 0;
	if (!arg[1])
		return (0);
	while (arg[++i])
	{
		if (ft_strnchr(arg[i], FTLS_OPT, 12) < 0)
			return (error_w_param(arg[i]));
		meta->param |= 1 << ft_strnchr(arg[i], FTLS_OPT, 12);
	}
	return (1);
}

static void			parser_init_target(t_ls_meta *meta,
	char **av, int i, int ac)
{
	register int	c;

	c = 0;
	meta->targetnb = ac - i;
	if ((meta->target = (char **)malloc(sizeof(char *) * ac - i)))
	{
		while (i < ac)
		{
			meta->target[c] = ft_strdup(av[i]);
			++c;
			++i;
		}
	}
	else
		meta->targetnb = 0;
}

int					parser(int ac, char **av, t_ls_meta *meta)
{
	register int	i;

	i = 0;
	if (ac == 1)
	{
		meta->param = 0;
		parser_init_empty(meta);
	}
	else
	{
		meta->param = 0;
		while (++i < ac && av[i][0] == '-' && av[i][1])
		{
			if (parser_add_param(meta, av[i]) < 0)
				return (0);
		}
		if (i >= ac)
			parser_init_empty(meta);
		else
			parser_init_target(meta, av, i, ac);
		meta->sortfunc = parser_init_sort(meta->param);
	}
	return (1);
}
