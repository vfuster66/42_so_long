/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:02:04 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/06 18:12:53 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strdup_n(char *s1)
{
	char	*dest;
	int		size;
	int		i;

	dest = NULL;
	size = ft_strlen(s1);
	i = 0;
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!(dest))
		return (NULL);
	while (s1[i] && s1[i] != '\n')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlcpy_n(char *dst, char *src, int dst_size)
{
	int	i;
	int	len;

	len = ft_strlen(src);
	i = 0;
	if (dst_size == 0)
		return (len);
	while (i < dst_size - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (len);
}

char	*ft_strjoin_n(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*dst;

	dst = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup_n(s2));
	else if (s2 == NULL)
		return (ft_strdup_n(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!(dst))
		return (NULL);
	ft_strlcpy_n(dst, s1, s1_len + 1);
	ft_strlcpy_n((dst + s1_len), s2, s2_len + 1);
	free(s1);
	free(s2);
	return (dst);
}

void	ft_check_env(char **env)
{
	int	idx;

	if (!*env)
	{
		write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
		write(STDERR_FILENO, NO_ENV_ERROR, ft_strlen(NO_ENV_ERROR));
		exit(EXIT_FAILURE);
	}
	idx = 0;
	while (env[idx])
	{
		if (ft_strncmp("DISPLAY", env[idx], ft_strlen("DISPLAY")) == 0)
			return ;
		else
			idx++;
	}
	write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(STDERR_FILENO, NO_DISP_ERROR, ft_strlen(NO_DISP_ERROR));
	exit(EXIT_FAILURE);
}

int	ft_check_extension(char *map_name, char *extension)
{
	int	len_map_name;
	int	len_extension;

	len_map_name = ft_strlen(map_name);
	len_extension = ft_strlen(extension);
	if (len_map_name <= len_extension)
		return (EXIT_SUCCESS);
	map_name += len_map_name - len_extension;
	while (*map_name)
	{
		if (*map_name != *extension)
			return (EXIT_SUCCESS);
		map_name++;
		extension++;
	}
	return (EXIT_FAILURE);
}
