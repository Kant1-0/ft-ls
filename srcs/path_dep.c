/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_dep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:29:26 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/18 12:23:14 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	tabcount(const char **arg)
{
	register size_t	i;

	i = 0;
	while (arg[i])
		++i;
	return (i - 1);
}

static size_t	sizetabcount(const char **arg)
{
	register int	i;
	register int	j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		j += (ft_strlen(arg[i]));
		++i;
	}
	return (j);
}

char			*ft_strglu(const char **arg, char separator)
{
	char			*res;
	const size_t	size = tabcount(arg);
	register size_t	i;
	register int	j;
	register int	k;

	i = 0;
	k = 0;
	res = (char *)malloc(sizeof(char) * ((separator >= 0 ? size : 0)
		+ sizetabcount(arg) + 1));
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
			res[k++] = arg[i][j++];
		if (separator >= 0 && i < size)
			res[k++] = separator;
		i++;
	}
	res[k] = 0;
	return (res);
}

int				usefull(const char *path)
{
	register int	a;
	register int	n;

	n = ft_strlen(path) - 1;
	a = 0;
	while (path[n] == '.' && a < 3)
	{
		++a;
		--n;
	}
	if (a < 3 && path[n] == '/')
		return (0);
	return (1);
}

char			*add_path(const char *path, const char *new)
{
	const char	*tab[3];

	tab[0] = path;
	tab[1] = new;
	tab[2] = NULL;
	if (path[ft_strlen(path) - 1] == '/')
		return (ft_strglu(tab, -1));
	else
		return (ft_strglu(tab, '/'));
}
