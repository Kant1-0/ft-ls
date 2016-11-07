/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:24:36 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/10 14:25:15 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	sort_no(t_ls_file *a, t_ls_file *b)
{
	a = b;
	return (1);
}

int	sort_alpha(t_ls_file *a, t_ls_file *b)
{
	if (!a || !b)
		return (0);
	if (ft_strcmp(a->dp.d_name, b->dp.d_name) < 0)
		return (1);
	else
		return (0);
}

int	sort_time(t_ls_file *a, t_ls_file *b)
{
	long	ta;
	long	tb;

	ta = a->filestat.st_mtime;
	tb = b->filestat.st_mtime;
	if (ta == tb)
	{
		ta = a->filestat.st_mtimespec.tv_nsec;
		tb = b->filestat.st_mtimespec.tv_nsec;
		if (ta == tb)
			return (sort_alpha(a, b));
	}
	return ((ta - tb) > 0 ? 1 : 0);
}

int	sort_last_access(t_ls_file *a, t_ls_file *b)
{
	long	ta;
	long	tb;

	ta = a->filestat.st_atime;
	tb = b->filestat.st_atime;
	if (ta == tb)
	{
		ta = a->filestat.st_atimespec.tv_nsec;
		tb = b->filestat.st_atimespec.tv_nsec;
		if (ta == tb)
			return (sort_alpha(a, b));
	}
	return ((ta - tb) > 0 ? 1 : 0);
}

int	sort_birth(t_ls_file *a, t_ls_file *b)
{
	long	ta;
	long	tb;

	ta = a->filestat.st_birthtime;
	tb = b->filestat.st_birthtime;
	if (ta == tb)
	{
		ta = a->filestat.st_birthtimespec.tv_nsec;
		tb = b->filestat.st_birthtimespec.tv_nsec;
		if (ta == tb)
			return (sort_alpha(a, b));
	}
	return ((ta - tb) > 0 ? 1 : 0);
}
