/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_details.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:29:26 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/10 12:37:57 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*disp_owner(uid_t uid, int param)
{
	struct passwd	*tmp;

	if (param & (1 << 5) || !(tmp = getpwuid(uid)))
		return (ft_itoa(uid));
	else
		return (ft_strdup(tmp->pw_name));
}

char	*disp_group(gid_t gid, int param)
{
	struct group	*tmp;

	if (param & (1 << 5) || !(tmp = getgrgid(gid)))
		return (ft_itoa(gid));
	else
		return (ft_strdup(tmp->gr_name));
}

char	*disp_time(time_t tmp)
{
	double	timediff;

	timediff = time(NULL) - tmp;
	if ((timediff > 15778800) || (timediff < -15778800))
		return (ctime(&tmp) + 19);
	return (ctime(&tmp) + 11);
}

void	disp_link_target(char *path)
{
	char buf[1024];

	ft_bzero(buf, 1024);
	readlink(path, buf, 1024);
	ft_printf(" -> %s", buf);
}

void	disp_mf(mode_t mode)
{
	if (S_ISLNK(mode))
		write(1, "@", 1);
	else if (S_ISDIR(mode))
		write(1, "/", 1);
	else if (S_ISFIFO(mode))
		write(1, "|", 1);
	else if (S_ISSOCK(mode))
		write(1, "=", 1);
	else if (mode & S_IXUSR || mode & S_IXGRP || mode & S_IXOTH)
		write(1, "*", 1);
}
