/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqplusplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 22:56:29 by pollier           #+#    #+#             */
/*   Updated: 2014/08/21 02:26:16 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

int				main(int argc, char *argv[])
{
	int i;

	i = 0;
	while (++i <= argc)
	{
		ft_putstr("Pegasus 0\n");
		ft_open_file(argv, i);
	}
	return 0;
}

t_params	*ft_struct(int call)
{
	static t_params *params;

	if (!(params))
	{
	params = (t_params *)malloc(sizeof(t_params));
	params->error = 0;
	params->index_panda = 0;
	ft_putstr("Init struct\n");
	return (params);
	}
	if (call == 2)
	{
		ft_putstr("Acces struct\n");
		return (params);
	}
	if (call == 3)
	{
		ft_putstr("Free struct\n");
		free(params);
		params = NULL;
	}
	return (params);
}
/*
void			ft_highway_to_segfaults(char **argv, int i)
{
	ft_open_file(argv, i);
}
*/
char			*ft_open_file(char **argv, int i)
{
	int			test;

	ft_putstr("Manfred 1\n");
	test = open(argv[i], O_RDONLY);
	ft_get_grid_param(test);
	ft_putstr("Manfred 2\n");
	ft_read_files(argv[i]);
	ft_putstr("Manfred 3\n");
	return (ft_struct(2)->str);
}

void			ft_get_grid_param(int i)
{
	char		*param;
	char		buffer[BUFF_SIZE + 1];
	int			test;

	if (!(test = read(i, buffer, BUFF_SIZE)))
	{
		ft_struct(2)->error = 1;
	}
	buffer[BUFF_SIZE + 1] = '\0';
	if (!(param = ft_read_grid_first_line(buffer)))
	{
		ft_struct(2)->error = 1;
	}
	ft_putstr("grid lol\n");

	ft_struct(2)->width = ft_read_grid_second_line(buffer);
	ft_struct(2)->height = ft_atoi(param);
	while (*param >= '0' && *param <= '9')
		param++;
	ft_struct(2)->empty = *param;
	param++;
	ft_struct(2)->obstacle = *param;
	param++;
	ft_struct(2)->full = *param;
}

void		ft_read_files(char *filename)
{
	char		*content;
	int			d;
	int			r;
	int			u;
	char		*buff;

	ft_putstr("Poilu\n");
	u = (ft_struct(2)->width * ft_struct(2)->height + ft_struct(2)->width);
	content = (char*)malloc(sizeof(u + 1));
	content[0] = '\0';
	d = open(filename, O_RDONLY);
	r = 1;
	buff = (char *)malloc(sizeof(BUFF_SIZE + 1));
	while (r)
	{
		r = read(d, buff, BUFF_SIZE);
		buff[r] = '\0';
		ft_putstr("read\n");
		printf("%d\n", ft_strlen(content));
		printf("%d\n", ft_strlen(buff));
		printf("%d\n", u);
		content = ft_strcat(content, buff);
		ft_putstr("read 2\n");
	}
	free(buff);
	ft_putstr(content);
	free(content);
	free(ft_struct(2)->str);
}

char		*ft_read_grid_first_line(char *str)
{
	char	*reading;
	int		i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	if (!(reading = (char *)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		reading[i] = str[i];
		i++;
	}
	reading[i] = '\0';
	return (reading);
}

int			ft_read_grid_second_line(char *str)
{

	int		i;
	int		j;

	i = 0;
	j = 1;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	printf("%d\n", i);
	while (str[j + i] != '\n' && str[j + i] != '\0')
		j++;
	printf("%d\n", j);
	return (j - 1);
}

char		*ft_strcat(char *dest, char *src)
{
	int dest_size;
	int i;

	dest_size = ft_struct(2)->index_panda;
	i = 0;
	while (src [i] != '\0')
	{

		dest[dest_size] = src[i];
		i++;
		dest_size++;
	}
	dest[dest_size] = '\0';
	ft_struct(2)->index_panda = dest_size;
	printf("fjkfghgiofghgiudslfbgjkfldghjgflg;fjhfd;lggkjhdfjkbfdljkgdfklgfdhjkdfklgfjhlg");
	return (dest);
}

int			ft_atoi(char *s1)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (s1[i] && s1[i] <= '9' && s1[i] >= '0')
	{
		nb = (nb * 10) + (s1[i] - '0');
		i++;
	}
	return (nb);
}

int		ft_strnlen(char *str, int offset)
{
	int size;

	size = ft_strlen(str);
	if (offset >= size)
		return (0);
	return (size - offset);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

