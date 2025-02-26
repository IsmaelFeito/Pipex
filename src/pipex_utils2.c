/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:24:19 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/02/26 16:22:11 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	final_child_pid(pid_t child_pid2, int pid)
{
	if (waitpid(child_pid2, &pid, 0) == -1)
	{
		perror(NULL);
		exit(1);
	}
	return (pid >> 8);
}

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
