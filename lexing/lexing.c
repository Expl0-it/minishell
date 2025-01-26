/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:18:49 by codespace         #+#    #+#             */
/*   Updated: 2025/01/26 20:33:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int     pipe_count(char **args)
// {
//     int     count;
//     int     i;

//     i = 0;
//     count = 1;
//     while (args[i])
//     {
//         if (args[i][0] == '|')
//             count++;
//         i++;
//     }
//     return (count);
// }

// int  fill_cmd(t_data *data, int j, int i)// {
//  int     c;//  int     k;
    //  k = 0;
//          perror(""); //  c = cmd_count(&data->args[j]);
//  data->pipes[i].cmd = malloc(sizeof(char *) * (c + 1));//  while (k < c)
//  {//      data->pipes[i].cmd[k] = ft_strdup(data->args[j]);
//      j++;
//      k++;//  }
//  data->pipes[i].cmd[k] = NULL;//  return (c);
// }
void initiate_pipe(t_pipes *pipe)
{
    pipe->old_outfd = -1;
	pipe->infd = 0;
    pipe->outfd = -1;    
	pipe->pid = 0;
    pipe->heredoc = false;    
	pipe->invalid_infile = false;
    pipe->write_mode = REPLACE;    
	pipe->infile = NULL;
    pipe->outfile = NULL;    
	pipe->limiter = NULL;
}
// void lexer(t_data *data)// {
//  int p = pipe_count(data->args);//  int j = 0;
//  int c;//  // NOTE: WHEN ALLOCATING WITH CALLOC IT DOESNT SEGFAULT ANYMORE
//  data->pipes = ft_calloc(p + 1, sizeof(t_pipes));//  /*data->pipes = malloc(sizeof(t_pipes *) * (p + 1));*/
//  for (int i = 0; i < p; i++)//  {
//      initiate_pipe(&data->pipes[i]);//      c = fill_cmd(data, i, j);       
//      while (j < c * (i + 1))//          j++;
//      while (data->args[j] != NULL && ft_strncmp(data->args[j], "|", ft_strlen(data->args[j])) != 0)//      {
//          if (ft_strncmp(data->args[j], ">", 1) == 0)//          {
//              int     flag;
                //              flag = O_TRUNC;
//              if (ft_strncmp(data->args[j], ">>", 2) == 0)//              {
//                  flag = O_APPEND;//                  data->pipes[i].write_mode = APPEND;
//              }//              if (data->pipes[i].outfile)
//              {//                  close(data->pipes[i].outfd);
//                  free(data->pipes[i].outfile);//              }
//              data->pipes[i].outfd = open(data->args[j + 1], O_WRONLY | O_CREAT | flag, 0644);//              data->pipes[i].outfile = ft_strdup(data->args[j + 1]);
//          }//          j++;
//      }//      if (data->pipes[i].outfd != -1) {
//          data->pipes[i].old_outfd = dup(STDOUT_FILENO);//          dup2(data->pipes[i].outfd, STDOUT_FILENO);
//          close(data->pipes[i].outfd);//      }
//  }// }

//          // if (ft_strncmp(data->args[j], "<", ft_strlen(data->args[j])) == 0)//          // {
//          //  data->pipes[i].infd = open(data->args[j + 1], O_RDONLY);//          //  if (data->pipes[i].infile)
//          //      close(data->pipes[i].infd);//          //  data->pipes[i].infile = ft_strdup(data->args[j + 1]);
//          // }//          // else if (ft_strncmp(data->args[j], "<<", ft_strlen(data->args[j])) == 0)
//          // {//          //  data->pipes[i].limiter = ft_strdup(data->args[j + 1]);
//          //  data->pipes[i].heredoc = true;//          // }

int pipes_count(char **args)
{
    int pipes;
    
	pipes = 0;    
	while (*args)
    {        
		if (!ft_strncmp(*args, "|", 1))
            pipes++;        
		args++;
    }    
	return (pipes +1);
}

int     fill_cmd(char **args, t_pipes *pipe)
{
    int     i;

    i = 0;    
	while (args[i]
        && ft_strncmp(args[i], "|", ft_strlen(args[i]))        
		&& ft_strncmp(args[i], "<", ft_strlen(args[i]))
        && ft_strncmp(args[i], ">", ft_strlen(args[i]))        
		&& ft_strncmp(args[i], ">>", ft_strlen(args[i]))
        && ft_strncmp(args[i], "<<", ft_strlen(args[i])))
    {        
		if (pipe)
            pipe->cmd[i] = ft_strdup(args[i]);        
		i++;
    }   
	return (i);
}
void print_pipe_debug(t_pipes *pipe)
{
    printf("pipe->cmd: ");    
	for (int i = 0; pipe->cmd[i]; i++)
        printf("%s ", pipe->cmd[i]);    
	printf("\n");
    printf("pipe->limiter: %s\n", pipe->limiter);   
	printf("pipe->infile: %s\n", pipe->infile);
    printf("pipe->outfile: %s\n", pipe->outfile);    
	printf("pipe->old_outfd: %d\n", pipe->old_outfd);
    printf("pipe->infd: %d\n", pipe->infd);   
	printf("pipe->outfd: %d\n", pipe->outfd);
    printf("pipe->pid: %d\n", pipe->pid);    
	printf("pipe->heredoc: %d\n", pipe->heredoc);
    printf("pipe->invalid_infile: %d\n", pipe->invalid_infile);    
	printf("pipe->write_mode: %d\n", pipe->write_mode);
    printf("\n");
}
void    fill_pipes(t_pipes *pipe, char **args, int *j)
{    
	int cmd_count;
    
	cmd_count = fill_cmd(args + *j, NULL);
    initiate_pipe(pipe);    
	pipe->cmd = malloc(sizeof(char *) * (cmd_count + 1));
    pipe->cmd[cmd_count] = NULL;    
	*j += fill_cmd(args + *j, pipe);
    while (args[*j] && ft_strncmp(args[*j], "|", 1))    
	{
        if (args[*j] && !ft_strncmp(args[*j], ">", 1))
        {            
			int flag;

            flag = O_TRUNC;
            if (!ft_strncmp(args[*j], ">>", 2))            
			{
                flag = O_APPEND;                
				pipe->write_mode = APPEND;
            }            
			if (pipe->outfile)
            {                
				close(pipe->outfd);
                free(pipe->outfile);            
			}
            pipe->outfd = open(args[*j + 1], O_WRONLY | O_CREAT | flag, 0644);            
			pipe->outfile = ft_strdup(args[*j + 1]);
            (*j)++;        
		}
        if (args[*j])
            (*j)++;    
	}
    if (pipe->outfd != -1)    
	{
        pipe->old_outfd = dup(STDOUT_FILENO);        
		dup2(pipe->outfd, STDOUT_FILENO);
        close(pipe->outfd);    
	}
    // Print pipe for debugging        
	print_pipe_debug(pipe);
}
void    lexer(t_data *data)
{
    int i;   
	int j;
    int pipes;

    pipes = pipes_count(data->args);    
	data->pipes = ft_calloc(pipes + 1, sizeof(t_pipes));
    i = 0;    
	j = 0;
    while (i < pipes)
	{
        fill_pipes(data->pipes + i, data->args, &j);
        i++;                
    }
}