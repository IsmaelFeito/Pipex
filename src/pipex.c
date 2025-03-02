/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:05:41 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/02/26 16:22:46 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	run_child(char **args, char **env, int *pipefd)
{
	int	input_fd;

	input_fd = open(args[1], O_RDONLY);
	if (input_fd < 0)
	{
		perror("Error opening input file");
		close(pipefd[0]);
		close(pipefd[1]);
		exit(1);
	}
	dup2(input_fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(input_fd);
	run_command(args[2], env);
}

void	run_child_2(char **args, char **env, int *pipefd)
{
	int	output_fd;

	output_fd = open(args[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd < 0)
	{
		perror("Error opening output file");
		close(pipefd[0]);
		close(pipefd[1]);
		exit(1);
	}
	dup2(pipefd[0], STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(output_fd);
	run_command(args[3], env);
}

int	execute_pipeline(char **args, char **env)
{
	int		pipefd[2];
	pid_t	child_pid;
	pid_t	child_pid2;
	int		ret;

	ret = 0;
	if (pipe(pipefd) < 0)
	{
		pipe_error();
		return (1);
	}
	child_pid = fork();
	check_fork_err(child_pid, pipefd);
	if (child_pid == 0)
		run_child(args, env, pipefd);
	child_pid2 = fork();
	check_fork_err(child_pid2, pipefd);
	if (child_pid2 == 0)
		run_child_2(args, env, pipefd);
	close(pipefd[1]);
	close(pipefd[0]);
	waitpid(child_pid, NULL, 0);
	return (final_child_pid(child_pid2, ret));
}

int	main(int argc, char **args, char **env)
{
	int	e_status;

	e_status = 0;
	if (argc == 5)
		e_status = execute_pipeline(args, env);
	else
		args_error();
	return (e_status);
}
