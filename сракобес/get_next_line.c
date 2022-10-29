/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:07:13 by risolon           #+#    #+#             */
/*   Updated: 2022/09/24 18:18:09 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*make_line(char *buf, int i)
// {
// 	char	*line;

// 	line = malloc(2);
// 	if (!line)
// 		return (NULL);
// 	if (line != 0 && buf[i] == '\n')
// 	{
// 		line[0] = '\n';
// 		line[1] = '\0';
// 		return (line);
// 	}
// 	line[0] = '\0';
// 	return (line);
// }

// char	*get_line(char *buf, int j)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	while (buf[i + j] != '\n' && buf[i + j])
// 		i++;
// 	line = malloc(sizeof(char *) * (i + 2));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (buf[j] != '\n' && buf[j])
// 	{
// 		line[i++] = buf[j++];
// 	}
// 	if (buf[j] == '\n')
// 		line[i++] = '\n';
// 	line[i] = '\0';
// 	return (line);
// }

// char	*check_line(char *line)
// {
// 	if (!line)
// 		return (0);
// 	if (line[0])
// 		return (line);
// 	free (line);
// 	return (0);
// }

// char	*get_next_line(int fd)
// {
// 	static char	buf[BUFFER_SIZE + 1];
// 	static int	i = 0;
// 	char		*line;
// 	long		bytes;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (buf[i] == '\n')
// 		i++;
// 	line = make_line(buf, i);
// 	while (buf[i] != '\n')
// 	{
// 		if (buf[i] == '\0')
// 		{
// 			bytes = read(fd, buf, BUFFER_SIZE);
// 			if (bytes <= 0)
// 				return (check_line(line));
// 			buf[bytes] = '\0';
// 			i = 0;
// 		}
// 		line = ft_strjoin(line, get_line(buf, i));
// 		while (buf[i] && buf[i] != '\n')
// 			i++;
// 	}
// 	return (line);
// }

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

// char	*ft_strdup(const char *s)
// {
// 	char	*str;
// 	char	*str2;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	str2 = (char *)s;
// 	while (str2[i] != '\0')
// 		i++;
// 	str = (char *)malloc(sizeof(*str2) * (i + 1));
// 	if (!str)
// 		return (NULL);
// 	while (j < i)
// 	{
// 		str[j] = str2[j];
// 		j++;
// 	}
// 	str[j] = '\0';
// 	return (str);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len])
// 	{
// 		len++;
// 	}
// 	return (len);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	y;
// 	size_t	i;
// 	char	*str;

// 	i = 0;
// 	y = 0;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[y])
// 		str[i++] = s2[y++];
// 	str[i] = '\0';
// 	return (str);
// }

// int	get_next_line(int fd, char **line)
// {
// 	char	buf[2];
// 	int		sr;
// 	char	*tmp;

// 	sr = 0;
// 	buf[1] = '\0';
// 	*line = malloc(1);
// 	if (!(*line) || !line)
// 		return (-1);
// 	**line = 0;
// 	while ((sr = read(fd, buf, 1)) > 0)
// 	{
// 		if (*buf != '\n' && *buf != EOF && *buf != '\0')
// 		{
// 			tmp = *line;
// 			*line = ft_strjoin(*line, buf);
// 			free(tmp);
// 		}
// 		else
// 			break ;
// 	}
// 	return (sr);
// }

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*str2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str2 = (char *)s;
	while (str2[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(*str2) * (i + 1));
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = str2[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	y;
	size_t	i;
	char	*str;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(str))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = '\0';
	return (str);
}

int	get_next_line(int fd, char **line)
{
	char	buf[2];
	int		sr;
	char	*tmp;

	sr = 0;
	buf[1] = '\0';
	*line = malloc(1);
	if (!(*line) || !line)
		return (-1);
	**line = 0;
	sr = read(fd, buf, 1);
	while (sr > 0)
	{
		if (*buf != '\n' && *buf != EOF && *buf != '\0')
		{
			tmp = *line;
			*line = ft_strjoin(*line, buf);
			free(tmp);
		}
		else
			break ;
		sr = read(fd, buf, 1);
	}
	return (sr);
}
