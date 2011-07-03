/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Sun Jul  3 23:02:55 2011 solvik blum
*/

#define		_GNU_SOURCE

#include	<stdio.h>
#include	<stdlib.h>

#include	"player.h"
#include	"stone.h"
#include	"server_zappy.h"
#include	"tserver.h"

typedef struct	s_elevation
{
  uint		nb_players;
  uint		linemate;
  uint		deraumere;
  uint		sibur;
  uint		mendiane;
  uint		phiras;
  uint		thystame;
}		t_elevation;

static const t_elevation      gl_elevation_infos[] =
  {
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0},
    {2, 2, 0, 1, 0, 2, 0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 3, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1}
  };

#define ELV	gl_elevation_infos[player->level]

static bool	verif_incantation(t_player *player)
{
  if (ELV.linemate == getbox_nbstones_by_player(player, LINEMATE) &&
      ELV.deraumere == getbox_nbstones_by_player(player, DERAUMERE) &&
      ELV.sibur == getbox_nbstones_by_player(player, SIBUR) &&
      ELV.mendiane == getbox_nbstones_by_player(player, MENDIANE) &&
      ELV.phiras == getbox_nbstones_by_player(player, PHIRAS) &&
      ELV.thystame == getbox_nbstones_by_player(player, THYSTAME) &&
      ELV.nb_players == (uint)get_list_len(get_players_by_level(player->x,
								player->y,
								player->level)))
    return (true);
  return (false);
}

int		zappy_incantation(t_fds *client, char *cmd)
{
  int		r;
  char		*msg;

  (void)cmd;
  if (!verif_incantation(player_data))
    {
      sends(client, "ko");
      return (0);
    }
  sends(client, "elevation en cours");
  player_data->level += 1;
  r = asprintf(&msg, "niveau actuel : %d", player_data->level);
  sends(client, msg);
  if (msg)
    free(msg);
  return (1);
}
