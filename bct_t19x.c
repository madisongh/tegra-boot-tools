/*
 * bct_t19x.c
 *
 * BCT-related functions for t19x SoCs
 *
 * Copyright (c) 2020 Matthew Madison
 */

#include "t19x/nvboot_bct.h"

/*
 * bct_update_valid_t19x
 */
int
bct_update_valid_t19x (void *cur_bct, void *cand_bct)
{
	NvBootConfigTable *cur = cur_bct;
	NvBootConfigTable *cand = cand_bct;

	if (cur->BctSize != cand->BctSize)
		return 0;
	if ((cur->BootDataVersion >> 24) != (cand->BootDataVersion >> 24))
		return 0;
	if (cur->BlockSizeLog2 != cand->BlockSizeLog2)
		return 0;
	if (cur->PageSizeLog2 != cand->PageSizeLog2)
		return 0;

	return 1;

} /* bct_update_valid_t19x */
