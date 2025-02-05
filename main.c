/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:01:14 by asene             #+#    #+#             */
/*   Updated: 2025/02/05 11:26:20 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_strnjoin(char **strs, unsigned int size, char *sep);
void	ft_putstr_fd(char *str, int fd);

int	main(int argc, char **argv, char **envp)
{
	char	*str1;
	char	*str2;
	void	*tmp;

	if (argc < 5)
	{
		ft_putstr_fd("Usage: pipex <FILE> <COMMAND> <COMMAND>... <FILE>\n", 2);
		exit(1);
	}
	str1 = ft_strnjoin(&(argv[2]), argc - 3, " | ");
	tmp = (char *[]){"<", argv[1], str1, ">", argv[argc -1]};
	str2 = ft_strnjoin(tmp, 5, " ");
	free(str1);
	execve("/bin/bash", (char *[]){"/bin/bash", "-c", str2, 0}, envp);
	return (free(str2), perror("execve: "), 1);
}
