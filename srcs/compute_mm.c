/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_mm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:29:26 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/10 12:38:04 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	com_major(t_ls_file *file)
{
	int			ans;
	int			tmp;

	ans = 0;
	while (file)
	{
		if (S_ISBLK(file->filestat.st_mode) || S_ISCHR(file->filestat.st_mode))
		{
			tmp = file->filestat.st_rdev;
			while ((tmp / 256) > 0)
				tmp /= 256;
			if (ans < ft_nbrlen(tmp))
				ans = ft_nbrlen(tmp);
		}
		file = file->next;
	}
	return (ans);
}

int	com_minor(t_ls_file *file)
{
	int			ans;
	int			tmp;

	ans = 0;
	while (file)
	{
		if (S_ISBLK(file->filestat.st_mode) || S_ISCHR(file->filestat.st_mode))
		{
			tmp = file->filestat.st_rdev;
			tmp %= 256;
			if (ans < ft_nbrlen(tmp))
				ans = ft_nbrlen(tmp);
		}
		file = file->next;
	}
	return (ans);
}
