/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:18:18 by asene             #+#    #+#             */
/*   Updated: 2025/02/05 11:25:02 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (s)
		while (s[count] != '\0')
			count++;
	return (count);
}

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

static unsigned int	ft_strnjoin_len(char **strs, unsigned int size, char *sep)
{
	unsigned int	i;
	unsigned int	len;

	len = 1;
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	if (size != 0)
		len += (size - 1) * ft_strlen(sep);
	return (len);
}

char	*ft_strnjoin(char **strs, unsigned int size, char *sep)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*result;

	len = ft_strnjoin_len(strs, size, sep);
	result = malloc(len * sizeof(char));
	i = 0;
	j = 0;
	while (i < size)
	{
		if (i != 0)
			j += ft_strlcpy(&result[j], sep, len - j);
		j += ft_strlcpy(&result[j], strs[i++], len - j);
	}
	result[j] = 0;
	return (result);
}
