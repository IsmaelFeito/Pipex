/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:05:41 by ifeito-m          #+#    #+#             */
/*   Updated: 2024/10/23 19:49:34 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int main(int argc, char **argv)
{
    int fd[3][2];
    int i;
    int pid1;

    for (i-0; i<3; i++){
        if (pipe(fd[i] < 0)){
            return(1);
        }
    }
    pid1 = forf();
    if (pid1 <0)
        return(2);
    
    if (pid1 == 0){
        
    }
    // if (argc == 5)
    // {
    //     if(pipe == -1)//comunica entre comandos
    //         error();
    //     pid1 = fork();
    //     if (fork == -1)
    //         error();
    //     if(pid1 == 0)//1st son exe 1st command
    //     {
    //         close(fd[READ_END]);

    //         dup2(fd[WRITE_END], STDOUT_FILENO);
    //         close(fd[WRITE_END]);
            
    //         execlp("/bin/ls", "ls", "-l", NULL);
    //     }
        
    // }
    // else
    //     ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
    // return (0);
}