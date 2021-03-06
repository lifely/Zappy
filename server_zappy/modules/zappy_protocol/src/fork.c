/*
** fork.c for Zappy in ./server_zappy/modules/zappy_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include        <stdlib.h>

#include        "napi.h"
#include        "zappy_protocol.h"

bool            egg_eclosion(void *data)
{
  t_player      *player;
  t_egg         *egg;

  if (!(egg = (t_egg*)data) || !(player = egg->himself) || !player->team)
    return (false);
  if (!put_in_list(&player->team->players, player) ||
      !set_box_addplayer(player, player->x, player->y))
    return (false);
  player->fork = true;
  set_box_delegg(egg);
  return (true);
}

int             zappy_fork(t_fds *client, char *_)
{
  t_player      *p;

  (void)_;
  if (!client || !(p = *(t_player**)client) ||
      !(p->egg = set_box_addegg(p)))
    {
      sends(client, "ko");
      return (false);
    }
  sends(client, "ok");
  event_relative_dispatch("EggNew", p->egg, 0);
  event_relative_dispatch("EggHatch", p->egg, 600);
  return (true);
}
