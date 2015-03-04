/*
** move.c for move in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Wed Mar  4 12:54:34 2015 Rémi DURAND
** Last update Wed Mar  4 15:45:14 2015 Ambroise Coutarel
*/

#include "lemipc.h"

int		enemies_around(t_player *player, char *map)
{
  int		ret;
  /* int		pos; */

  ret = 0;
  ret += checkForEnemies(player, map, 1);
  ret += checkForEnemies(player, map, 9);
  ret += checkForEnemies(player, map, 10);
  ret += checkForEnemies(player, map, 11);
  /* pos = (player->y * 10) + player->x; */
  /* if (pos != 0 && map[pos - 1] != player->eq && map[pos - 1] != '0') */
  /*   ++ret; */
  /* if (pos != 99 && map[pos + 1] != player->eq && map[pos + 1] != '0') */
  /*   ++ret; */
  /* if ((pos + 10) <= 99 && map[pos + 10] != player->eq && map[pos + 10] != '0') */
  /*   ++ret; */
  /* if ((pos - 10) >= 0 && map[pos - 10] != player->eq && map[pos - 10] != '0') */
  /*   ++ret; */
  /* if ((pos + 11) <= 99 && map[pos + 11] != player->eq && map[pos + 11] != '0') */
  /*   ++ret; */
  /* if ((pos - 11) >= 0 && map[pos - 11] != player->eq && map[pos - 11] != '0') */
  /*   ++ret; */
  /* if ((pos + 9) <= 99 && map[pos + 9] != player->eq && map[pos + 9] != '0') */
  /*   ++ret; */
  /* if ((pos - 9) >= 0 && map[pos - 9] != player->eq && map[pos - 9] != '0') */
  /*   ++ret; */
  return (ret);
}

int		find_enemies(t_player *player, char *map)
{
  int		pos;
  int		en1;
  int		en2;

  pos = (player->y * 10) + player->x;
  en1 = pos;
  while (en1 != MAP_SIZE && (map[en1] == '0' || map[en1] == player->eq))
    ++en1;
  en2 = pos;
  while (en2 != 0 && (map[en2] == '0' || map[en2] == player->eq))
    --en2;
  if (en1 == 100 && en2 == 0)
    return (-1);
  return ((en1 - pos) < (pos - en2) ? en1 : en2);
}

int		flank(int mover)
{
  int		sign;

  sign = mover < 0 ? -1 : 1;
  mover = mover * sign;
  mover = mover == 1 ? 10 : 1;
  return (mover * sign); 
}

void		move_to_pos(t_player *player, char *map, int pos_en)
{
  int		dif_en_x;
  int		dif_en_y;
  int		pos_p;
  int		mover;

  pos_p = (player->y * 10) + player->x;
  dif_en_x = X(pos_en) - player->x;
  dif_en_y = Y(pos_en) - player->y;
  if (dif_en_x > dif_en_y)
    mover = dif_en_x > 0 ? 1 : -1;
  else
    mover = dif_en_y > 0 ? 10 : -10;
  if (map[pos_p + mover] != '0')
    //mover = flank(mover);
    return;
  pos_p += mover;
  map[pos_p] = player->eq;
  map[(player->y * 10) + player->x] = '0';
  player->x = X(pos_p);
  player->y = Y(pos_p);
}

void	        moves(t_player *player, char *map)
{
  int		pos_en;
  int		around;

  around = enemies_around(player, map);
  if (around >= 2)
    {
      player->not_dead = 0;
      map[(player->y * 10) + player->x] = '0';
      return ;
    }
  else if (around == 1)
    return ;
  else
    {
      pos_en = find_enemies(player, map);
      if (pos_en > 0)
	move_to_pos(player, map, pos_en);
    }
}
