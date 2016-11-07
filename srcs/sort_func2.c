/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:24:43 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/10 14:25:16 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	sort_lstatchg(t_ls_file *a, t_ls_file *b)
{
	long	ta;
	long	tb;

	ta = a->filestat.st_ctime;
	tb = b->filestat.st_ctime;
	if (ta == tb)
	{
		ta = a->filestat.st_ctimespec.tv_nsec;
		tb = b->filestat.st_ctimespec.tv_nsec;
		if (ta == tb)
			return (sort_alpha(a, b));
	}
	return ((ta - tb) > 0 ? 1 : 0);
}
