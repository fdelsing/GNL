/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:27:20 by fdelsing          #+#    #+#             */
/*   Updated: 2017/12/15 23:56:07 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t		ft_len(char *sample)
{
	size_t	i;

	i = 0;
	while (sample[i] != '\n' && sample[i])
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	size_t		len;
	char		*buf;
	static char *sample = "";


	if (fd < 0)
		return (-1);
	buf = ft_strnew(BUFF_SIZE); 
	while(ft_strchr(sample, '\n') == NULL)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if (ret == -1)
		{
			free(buf);
			return (-1);
		}
		sample = ft_strjoin(sample, buf);
		if (ret < BUFF_SIZE)
		{
			len = ft_len(sample);
			*line = ft_strsub(sample, 0, len);
//			ft_putstr("sample = ");
//			ft_putendl(sample);
			free(buf);
			free(sample);
			if (ret == 0 && ft_strlen(sample) == 0)
				return (0);
			sample = ft_strsub(sample, len + 1, ft_strlen(sample) - len);
			return (1);
		}
	}
//	ft_putstr("sample = ");
//	ft_putendl(sample);
	len = ft_len(sample);
	*line = ft_strsub(sample, 0, len);
	free(sample);
	sample = ft_strsub(sample, len + 1, ft_strlen(sample) - len);
	free(buf);
//	ft_putstr("sample = ");
//	ft_putendl(sample);
	return (1);
}

int		main2(int argc, char **argv)
{
	int fd;
	int i;
	char *line;

	fd = open(argv[1], O_RDONLY);
	i = 0;

	ft_putnbr(get_next_line((const int)fd, &line));
	ft_putchar('\n');
	ft_putendl(line);
	ft_putnbr(get_next_line((const int)fd, &line));
	ft_putchar('\n');
	ft_putendl(line);
	ft_putnbr(get_next_line((const int)fd, &line));
	ft_putchar('\n');
	ft_putendl(line);
	ft_putnbr(get_next_line((const int)fd, &line));
	ft_putchar('\n');
	ft_putendl(line);
	ft_putnbr(get_next_line((const int)fd, &line));
	ft_putchar('\n');
	ft_putendl(line);
	ft_putnbr(get_next_line((const int)fd, &line));
	ft_putchar('\n');
	ft_putendl(line);
	ft_putnbr(get_next_line((const int)fd, &line));
	ft_putchar('\n');
	ft_putendl(line);
	//	while (get_next_line((const int)fd, &line) != 0)
	//	{
	//		ft_putnbr(get_next_line((const int)fd, &line));
	//		ft_putchar('\n');
	//
	//		ft_putstr("line = ");
	//		ft_putendl(line);
	//	}
	return (0);
}

int		main(int argc, char **argv)
{
	main2(argc, argv);
		while (1)
		{}
	return (0);
}
