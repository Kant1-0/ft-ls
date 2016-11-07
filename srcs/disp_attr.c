/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:29:26 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/10 12:38:00 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	disp_acl(char *path)
{
	listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		write(1, "@ ", 2);
	else
		write(1, "  ", 2);
}
