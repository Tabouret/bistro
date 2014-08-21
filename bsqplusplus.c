/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqplusplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 22:56:29 by pollier           #+#    #+#             */
/*   Updated: 2014/08/21 17:31:23 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_header.h"

int			main(int argc, char *argv[])
{
	int i;

	i = 0;
	while (++i < argc)
	{
		ft_putstr("Pegasus 0\n");
		ft_open_file(argv, i);
		ft_struct(3);
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

void		ft_open_file(char **argv, int i)
{
	int			test;

	test = open(argv[i], O_RDONLY);
	ft_get_grid_param(test);
	ft_read_files(argv[i]);
}

void		ft_get_grid_param(int i)
{
	char		*param;
	char		buffer[BUFF_SIZE + 2];
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
	char		buff[BUFF_SIZE + 1];

	u = (ft_struct(2)->width * (ft_struct(2)->height + ft_struct(2)->width));
	content = (char*)malloc(sizeof(char) * (u + ft_struct(2)->width) + 1);
	content[0] = '\0';
	d = open(filename, O_RDONLY);
	while ((r = read(d, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		content = ft_strcat(content, buff);

	}
	content[u + 1] = '\0';
	ft_fuck_first_line(content);
	ft_parse(ft_struct(2)->str);
	free(content);
}

void		ft_fuck_first_line(char *str)
{
	char	*reading;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	i++;
	reading = (char *)malloc(sizeof(char) * ft_strlen(str) - i + 1);

	while (str[i] != '\0')
	{
		reading[j] = str[i];
		i++;
		j++;
	}
	reading[j] = '\n';
	reading[j] = '\0';
	ft_struct(2)->str = reading;
}

void		ft_parse(char *str)
{
	int		*parstr;
	int		i;
	int		max;
	int		pos;
	int		ubloop[0];

	i = 0;
	parstr = (int*)malloc(sizeof(int) * ft_strlen(str));
	while (str[i])
	{
		if (str[i] == ft_struct(2)->obstacle)
				parstr[i] = '0';
		if (str[i] == ft_struct(2)->empty)
		{
			parstr[i] = ft_jaylachiasse(parstr, i);
			if (parstr[i] > max)
			{
				max = parstr[i];
				pos = i;
			}
		}
		i++;
	}
	ubloop[0] = -10;
	ft_jaylachiasse(ubloop , 1);
	free(parstr);
}
int			ft_jaylachiasse(int *parstr, int i)
{
	int		b;
	int		c;
	int		min;

	if (parstr[0] == -10)
		ft_struct(2)->strint = parstr;
	min = parstr[i + 1];
	b = parstr[i + (ft_struct(2)->width) + 2];
	if (min > b)
		min = b;
	c = parstr[i + (ft_struct(2)->width) + 1];
	if (min > c)
	   min = c;
	return (min);
}

int			*ft_courante(char *str)
{
	int	i;
	int	u;
	int	*parstr;

	i = 0;
	u = ft_struct(2)->width;
	parstr = (int*)malloc(sizeof(int) * ft_strlen(str));
	while (str[i])
	{
		if (str[i + 1] == '\n')
			parstr[i] = ft_ai_je_la_chiasse(str, i);
		i += u;
	}
	while (str[i - u])
	{
		parstr[i - u] = ft_ai_je_la_chiasse(str, i - u);
		i++;
	}
	return (parstr);
}

int			ft_ai_je_la_chiasse(char *str, int i)
{
	if (str[i] == (ft_struct(2)->empty))
		return ('1');
	return (0);
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
	printf("%d____salut_moi_I\n", i);
	while (str[j + i] != '\n' && str[j + i] != '\0')
		j++;
	printf("%d____salut_moi_J\n", j);
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

		dest[dest_size - 1] = src[i - 1];
		i++;
		dest_size++;
	}
	dest[dest_size] = '\0';
	ft_struct(2)->index_panda = dest_size;
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

int			ft_strnlen(char *str, int offset)
{
	int size;

	size = ft_strlen(str);
	if (offset >= size)
		return (0);
	return (size - offset);
}

int			ft_strlen(char *str)
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

