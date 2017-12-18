/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_helper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:10:56 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/18 12:02:03 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_HELPER_H
# define GFX_HELPER_H
# include "../libvect/libvect.h"
# include "wolf3d.h"
# define WIDTH 640
# define HEIGHT 480
# define A_RAT 1.78
# define F_DIST 9
# define Z_MAX 2147483647
# define Z_MIN -2147483648

typedef struct		s_vertex
{
	t_vect3d		*map;
	t_vect3d		*world;
	t_vect3d		*align;
	t_vect2d		*screen;
	unsigned int	color;
}					t_vertex;

typedef enum		e_keys
{
	KEY_A = 0x00,
	KEY_S = 0x01,
	KEY_D = 0x02,
	KEY_F = 0x03,
	KEY_H = 0x04,
	KEY_G = 0x05,
	KEY_Z = 0x06,
	KEY_X = 0x07,
	KEY_C = 0x08,
	KEY_V = 0x09,
	KEY_B = 0x0B,
	KEY_Q = 0x0C,
	KEY_W = 0x0D,
	KEY_E = 0x0E,
	KEY_R = 0x0F,
	KEY_Y = 0x10,
	KEY_T = 0x11,
	KEY_1 = 0x12,
	KEY_2 = 0x13,
	KEY_3 = 0x14,
	KEY_4 = 0x15,
	KEY_6 = 0x16,
	KEY_5 = 0x17,
	KEY_EQ = 0x18,
	KEY_9 = 0x19,
	KEY_7 = 0x1A,
	KEY_DASH = 0x1B,
	KEY_8 = 0x1C,
	KEY_0 = 0x1D,
	KEY_R_SQ = 0x1E,
	KEY_O = 0x1F,
	KEY_U = 0x20,
	KEY_L_SQ = 0x21,
	KEY_I = 0x22,
	KEY_P = 0x23,
	KEY_RET = 0x24,
	KEY_L = 0x25,
	KEY_J = 0x26,
	KEY_APOS = 0x27,
	KEY_K = 0x28,
	KEY_SCOL = 0x29,
	KEY_BSLH = 0x2A,
	KEY_COM = 0x2B,
	KEY_FSLH = 0x2C,
	KEY_N = 0x2D,
	KEY_M = 0x2E,
	KEY_PER = 0x2F,
	KEY_TAB = 0x30,
	KEY_SPC = 0x31,
	KEY_TLD = 0x32,
	KEY_BKSP = 0x33,
	KEY_ESC = 0x35,
	KEY_CMD = 0x37,
	KEY_LSFT = 0x38,
	KEY_CPSL = 0x39,
	KEY_LOPT = 0x3A,
	KEY_LCTR = 0x3B,
	KEY_RSFT = 0x3C,
	KEY_ROPT = 0x3D,
	KEY_RCTR = 0x3E,
	KEY_FN = 0x3F,
	KEY_F17 = 0x40,
	KEY_NPER = 0x41,
	KEY_NMUL = 0x43,
	KEY_NPLU = 0x45,
	KEY_NCLR = 0x47,
	KEY_NDIV = 0x4B,
	KEY_ENT = 0x4C,
	KEY_NMIN = 0x4E,
	KEY_F18 = 0x4F,
	KEY_F19 = 0x50,
	KEY_NEQU = 0x51,
	KEY_N0 = 0x52,
	KEY_N1 = 0x53,
	KEY_N2 = 0x54,
	KEY_N3 = 0x55,
	KEY_N4 = 0x56,
	KEY_N5 = 0x57,
	KEY_N6 = 0x58,
	KEY_N7 = 0x59,
	KEY_F20 = 0x5A,
	KEY_N8 = 0x5B,
	KEY_N9 = 0x5C,
	KEY_F5 = 0x60,
	KEY_F6 = 0x61,
	KEY_F7 = 0x62,
	KEY_F3 = 0x63,
	KEY_F8 = 0x64,
	KEY_F9 = 0x65,
	KEY_F11 = 0x67,
	KEY_F13 = 0x69,
	KEY_F16 = 0x6A,
	KEY_F14 = 0x6B,
	KEY_F10 = 0x6D,
	KEY_F12 = 0x6F,
	KEY_F15 = 0x71,
	KEY_HOME = 0x73,
	KEY_PGUP = 0x74,
	KEY_DEL = 0x75,
	KEY_F4 = 0x76,
	KEY_END = 0x77,
	KEY_F2 = 0x78,
	KEY_PGDN = 0x79,
	KEY_F1 = 0x7A,
	KEY_LEFT = 0x7B,
	KEY_RGHT = 0x7C,
	KEY_DOWN = 0x7D,
	KEY_UP = 0x7E
}					t_keys;
#endif
