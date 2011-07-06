/*
** tna.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jul  6 17:18:49 2011 solvik blum
** Last update Wed Jul  6 17:52:21 2011 solvik blum
*/

#include	<stdlib.h>
#include	"visu_func.h"
#include	"client_zappy.h"

static bool             match_team(void *data, void *arg)
{
  int			n;

  n = !strcmp(((t_team *)data)->name, (char *)arg);
  return ((!n) ? true : false);
}

int		visu_tna(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  t_team	*t;
  t_team	*tmp;

  (void)pooler;
  t = malloc(sizeof(*t));
  t->name = cmd->argv[1];
  if (!(tmp = get_data_as_arg(visu->teams, match_team, cmd->argv[1])) &&
      (!put_in_list(&(visu->teams), t)))
    return (0);
  return (1);
}


int		send_tna(t_fds *pooler, t_cmd *cmd)
{
  (void)cmd;
  sends(pooler, "tna");
  return (1);
}