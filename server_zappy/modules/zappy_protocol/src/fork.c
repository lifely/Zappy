/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Mon Jul  4 02:12:32 2011 solvik blum
*/

#include	<stdlib.h>

#include	"player.h"
#include	"egg.h"
#include	"server_zappy.h"


int		zappy_fork(t_fds *client, char *cmd)
{
  t_egg		*egg;

  if (!(egg = set_box_addegg(player_data)))
    return (0);
  /* scheduler_relative(client, 42, */
  /* 		     (bool (*)(fds, void*))test, strdup(cmd))); */
  sends(client, "ok");
  return (1);
}
