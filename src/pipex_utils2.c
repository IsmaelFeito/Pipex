/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:24:19 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/02/25 16:28:39 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_clean_mem(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
		freedom((void **)&result[i++]);
	freedom((void **)&result);
}

void	check_fork_err(pid_t child_pid, int	*pipefd)
{
	if (child_pid < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		perror("Fork error");
		exit(1);
	}
}
