/*
** init.c for init in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 12:38:35 2015 Rémi DURAND
** Last update Tue Mar  3 14:45:24 2015 Rémi DURAND
*/

#include "lemipc.h"

int		algo_player(t_player *player, char *map, key_t key)
{
  int		sm_q_id[2];
  struct sembuf	sops;

  sops = sembuf_init();
  sm_q_id[0] = semget(key, 0, SHM_R | SHM_W);
  sem_set(sm_q_id[0], &sops, 1);
  while (42)
    {
      if (semctl(sm_q_id[0], 0, GETVAL) == (player->eq - 48))
	{
	  sem_set(sm_q_id[0], &sops, -1);
	}
    }
  (void)map;
  return (0);
}

int		algo_first(t_player *player, char *map, key_t key)
{
  int		sm_q_id[2];
  struct sembuf	sops;

  sops = sembuf_init();
  sm_q_id[0] = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
  while (42)
    {
      if (semctl(sm_q_id[0], 0, GETVAL) == player->eq)
	{
	  write(1, "\e[0;0H", 7);
	  display_map(map);
	  sem_set(sm_q_id[0], &sops, map_max(map) - 50);
	}
    }
}

int		is_first(char *map)
{
  int		v;
  int		count;

  v = 0;
  count = 0;
  while (v != MAP_SIZE)
    {
      if (map[v] == '1')
	++count;
      if (map[v] > '1' || count > 1)
	return (-1);
      ++v;
    }
  return (0);
}

int	        init_player(int map_id, key_t key)
{
  t_player      player;
  char		*addr;

  srandom(time(NULL));
  addr = (char *)shmat(map_id, NULL, SHM_W | SHM_R);
  if (map_nb_minions(addr) > 63)
    return (-1);
  player.eq = map_max(addr);
  if (add_player(&player, addr) == (-1))
    return (-1);
  if (player.eq == '1' && is_first(addr) == 0)
    {
      write(1, "\e[0;0H\e[2J", 12);
      write(1, "\e[?25l", 7);
      algo_first(&player, addr, key);
    }
  else
    algo_player(&player, addr, key);
  return (0);
}
