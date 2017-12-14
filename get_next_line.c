/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 21:00:37 by fdelsing          #+#    #+#             */
/*   Updated: 2017/12/14 19:47:53 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*malloc_sample(char *sample, char *buf, int size)
{
	char *newsample;

	if (!(newsample = (char*)malloc(sizeof(char) *
					ft_strlen(sample) + size + 1)))
		return (0);
	if (sample)
		newsample = ft_strcpy(newsample, sample);
	free(sample);
	newsample = ft_strncat(newsample, buf, size);
	return (newsample);
}

char	*ft_fill_line(char *sample, int y)
{
	char	*s;
	size_t	len;

	len = 0;
	while (y-- > 0)
	{
		if (ft_strchr(sample, '\n') == NULL)
			return (NULL);
		sample = ft_strchr(sample, '\n') + 1;
	}
	if (ft_strchr(sample, '\n') == NULL)
	{
		while (sample[len])
			len++;
		if (len == 0)
			return (NULL);
	}
	if (ft_strchr(sample, '\n') != NULL)
		while (sample[len] && sample[len] != '\n')
			len++;
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s = ft_strncpy(s, sample, len);
	s[len] = '\0';
	return (s);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static int	y = 0;
	char		*buf;
	static char *sample;

	if (fd < 0)
		return (-1);
	if (y == 0)
	{
		sample = ft_strnew(0);
		buf = ft_strnew(BUFF_SIZE);
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[ret] = '\0';
			sample = malloc_sample(sample, buf, ret);
		}
		free(buf);
	}
	if ((ft_fill_line(sample, y)) == NULL)
		return (0);
	buf = ft_fill_line(sample, y);
	*line = buf;
	free(buf);
	y++;
	return (1);
}

int		main2(int argc, char **argv)
{
	int fd;
	int i;
	char *line;

	fd = open(argv[1], O_RDONLY);
	i = 0;

	while (get_next_line((const int)fd, &line) != 0)
	{
		ft_putnbr(get_next_line((const int)fd, &line));
		ft_putchar('\n');

		ft_putstr("line = ");
		ft_putendl(line);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	main2(argc, argv);
//	while (1)
//	{}
	return (0);
}
