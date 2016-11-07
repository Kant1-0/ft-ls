/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:24:56 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/10 14:25:17 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	sort_rev_alpha(t_ls_file *a, t_ls_file *b)
{
	return (!sort_alpha(a, b));
}

int	sort_rev_time(t_ls_file *a, t_ls_file *b)
{
	return (!sort_time(a, b));
}

int	sort_rev_last_access(t_ls_file *a, t_ls_file *b)
{
	return (!sort_last_access(a, b));
}

int	sort_rev_birth(t_ls_file *a, t_ls_file *b)
{
	return (!sort_birth(a, b));
}

int	sort_rev_lstatchg(t_ls_file *a, t_ls_file *b)
{
	return (!sort_lstatchg(a, b));
}
