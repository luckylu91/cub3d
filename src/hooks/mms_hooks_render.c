/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mms_hooks_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:50:42 by lzins             #+#    #+#             */
/*   Updated: 2021/03/05 16:04:29 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hooks.h"

int	motion_hook(int x, int y, t_pack *p)
{
	(void)x;
	(void)y;
	(void)p;
	return (0);
}

int	key_press_hook(int kc, t_pack *p)
{
	if (kc == KEY_ESC)
		free_pack_and_quit(p);
	else if (kc == KEY_W)
		p->key_pressed |= KEYMASK_W;
	else if (kc == KEY_A)
		p->key_pressed |= KEYMASK_A;
	else if (kc == KEY_S)
		p->key_pressed |= KEYMASK_S;
	else if (kc == KEY_D)
		p->key_pressed |= KEYMASK_D;
	else if (kc == KEY_LEFT)
		p->key_pressed |= KEYMASK_LEFT;
	else if (kc == KEY_RIGHT)
		p->key_pressed |= KEYMASK_RIGHT;
	return (0);
}

int	key_release_hook(int kc, t_pack *p)
{
	if (kc == KEY_W)
		p->key_pressed &= ~KEYMASK_W;
	else if (kc == KEY_A)
		p->key_pressed &= ~KEYMASK_A;
	else if (kc == KEY_S)
		p->key_pressed &= ~KEYMASK_S;
	else if (kc == KEY_D)
		p->key_pressed &= ~KEYMASK_D;
	else if (kc == KEY_LEFT)
		p->key_pressed &= ~KEYMASK_LEFT;
	else if (kc == KEY_RIGHT)
		p->key_pressed &= ~KEYMASK_RIGHT;
	return (0);
}

int	expose_hook(t_pack *p)
{
	p->redraw_fun(p);
	return (0);
}

int	loop_hook(t_pack *p)
{
	handle_movement(p);
	collect_pea(p);
	if (p->game_on && move_all_enemies(p) == -1)
		free_pack_and_quit(p);
	assess_victory(p);
	assess_life(p);
	draw(p);
	tick(p);
	return (0);
}
