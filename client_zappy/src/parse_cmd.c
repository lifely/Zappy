/*
** parse_cmd.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jul  6 00:35:33 2011 solvik blum
** Last update Wed Jul  6 00:39:13 2011 solvik blum
*/

#include	<stdlib.h>

#include	"client_zappy.h"

t_cmd		*parse_cmd(char *str)
{
  int		len;
  t_cmd		*s;
  char		*ret;

  len = 0;
  s = malloc(sizeof(*s));
  s->argv = malloc(sizeof(*(s->argv)));
  if ((ret = strtok(str, " \t")))
    {
      s->argv = realloc(s->argv, sizeof(*(s->argv)) * (len + 1));
      s->argv[len++] = strdup(ret);
    }
  while ((ret = strtok(NULL, " \t")))
    {
      s->argv = realloc(s->argv, sizeof(*(s->argv)) * (len + 1));
      s->argv[len++] = strdup(ret);
    }
  s->argc = len;
  return (s);
}
