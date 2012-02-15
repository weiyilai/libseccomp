/**
 * BPF Language Definitions
 *
 * Copyright (c) 2012 Red Hat <pmoore@redhat.com>
 * Author: Paul Moore <pmoore@redhat.com>
 */

/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _BPF_H
#define _BPF_H

#include <inttypes.h>

/* these structures and values are designed to match the Linux Kernel's BPF
 * interface (see /usr/include/linux/filter.h), but we define our own here so
 * that we can function independent of the host OS */

struct bpf_instr {
	uint16_t op;
	uint8_t jt;
	uint8_t jf;
	uint32_t k;
} __attribute__ ((packed));

struct bpf_program {
	uint16_t i_cnt;
	struct bpf_instr *i;
};
#define BPF_PGM_SIZE(x) \
	((x)->blk_cnt * sizeof(*((x)->blks)))

/* bpf command classes */
#define BPF_CLASS(code)		((code) & 0x07)
#define BPF_LD			0x00
#define BPF_LDX			0x01
#define BPF_ST			0x02
#define BPF_STX			0x03
#define BPF_ALU			0x04
#define BPF_JMP			0x05
#define BPF_RET			0x06
#define BPF_MISC		0x07

/* BPF_LD and BPF_LDX */
#define BPF_SIZE(code)		((code) & 0x18)
#define BPF_W			0x00
#define BPF_H			0x08
#define BPF_B			0x10
#define BPF_MODE(code)		((code) & 0xe0)
#define BPF_IMM			0x00
#define BPF_ABS			0x20
#define BPF_IND			0x40
#define BPF_MEM			0x60
#define BPF_LEN			0x80
#define BPF_MSH			0xa0

#define BPF_OP(code)		((code) & 0xf0)
/* BPF_ALU */
#define BPF_ADD			0x00
#define BPF_SUB			0x10
#define BPF_MUL			0x20
#define BPF_DIV			0x30
#define BPF_OR			0x40
#define BPF_AND			0x50
#define BPF_LSH			0x60
#define BPF_RSH			0x70
#define BPF_NEG			0x80
/* BPF_JMP */
#define BPF_JA			0x00
#define BPF_JEQ			0x10
#define BPF_JGT			0x20
#define BPF_JGE			0x30
#define BPF_JSET		0x40

#define BPF_SRC(code)		((code) & 0x08)
#define BPF_K			0x00
#define BPF_X			0x08

/* BPF_RET (BPF_K and BPF_X also apply) */
#define BPF_RVAL(code)		((code) & 0x18)
#define BPF_A			0x10

/* BPF_MISC */
#define BPF_MISCOP(code)	((code) & 0xf8)
#define BPF_TAX			0x00
#define BPF_TXA			0x80

#endif