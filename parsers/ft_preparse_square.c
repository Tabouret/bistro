/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparse_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 21:58:09 by pollier           #+#    #+#             */
/*   Updated: 2014/08/18 22:22:52 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ft_biggest_square (int x, int y)
{
	if (x >= y)
	{
		return (y);
	}
	else
		return (x);
}

ft_biggest_offset_x (int x, int y)
{
	return(x - ft_biggest_square(x, y));
}

ft_biggest_offset_y (int x, int y)
{
	return(y - ft_biggest_square(x, y));
}
