/*
** tserver.h for  in /Users/Lifely/Developer/project/Zappy/server_zappy
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 05:07:36 2011 Julien Di Marco
** Last update Sun Jul  3 22:59:53 2011 solvik blum
*/

#ifndef		TSERV_H_
# define	TSERV_H_

#  include	"module.h"
#  include	"network.h"
#  include	"map.h"
#  include	"team.h"
#  include	"player.h"
#  include	"stone.h"

typedef		struct
{
  double	delay;
  double	time;
  uint		port;
  uint		nb_clients;
}		t_info;

typedef		struct
{
  t_list *	modules;
  t_list *	teams;
}		t_names;

typedef		struct
{
  t_names	names;
  t_info	info;
  t_map		map;
  fds		pool;
  t_list	*module;	/* t_module */
  t_list 	*team;		/* t_team */
  bool		run;
}		t_server;

t_player *	new_player(char *);

uint		get_map_width(void);
uint		get_map_height(void);
t_box 		*get_map(void);
uint		get_map_max(void);

t_box 		*get_box(uint, uint);
uint		get_box_nbstones(uint, uint, e_stone);
uint		get_player_nbstones(uint, e_stone);

int		get_port(void);
double		get_delay(void);
double		get_time(void);
fds 		*get_pool(void);
t_list		*get_teams(void);
t_list		*get_box_players(uint, uint);
t_team		*get_team_of_player(t_player *);
t_list		*get_modules(void);
t_player	*get_player_by_id(uint);
<<<<<<< HEAD
t_list		*get_players_by_level(uint, uint, uint);
=======
uint		get_player_level(uint);
bool		get_player_pos(uint, uint *, uint *);
t_list * /* t_stone */	get_player_stones(uint);
uint		get_player_food(uint);
>>>>>>> b0b191fcc74997b9962c40d813a72f512ad9f0ce

void		set_map_width(uint);
void		set_map_height(uint);
void		set_map(t_box *);
bool		set_box_addstone(uint, uint, e_stone, uint);
bool		set_box_delstone(uint, uint, e_stone, uint);
bool		set_box_addfood(uint, uint, uint);
bool		set_box_delfood(uint, uint, uint);
bool		setplayer_addstone(t_player *, e_stone, uint);
bool		setplayer_delstone(t_player *, e_stone, uint);
bool		set_box_add_player(t_player *, char *, uint, uint);
bool		set_new_module(t_module *);
void		set_port(int);
void		set_delay(double);
void		set_time(double);
void		set_nb_clients(uint);
void		set_run(bool);
bool		set_box_addplayer(t_player *, char *, uint, uint);

bool		available_modules(char *);
bool		available_teams(char *);

bool		gserv_const(bool);

#endif		/* !TSERV_H_ */
