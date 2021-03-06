/****************************************************************************
 * arch/renesas/src/rx65n/rx65n_eth.h
 *
 *   Copyright (C) 2008-2019 Gregory Nutt. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ***************************************************************************/

#ifndef __ARCH_RENESAS_SRC_RX65N_RX65N_ETH_H
#define __ARCH_RENESAS_SRC_RX65N_RX65N_ETH_H

/****************************************************************************
 * Included Files
 ***************************************************************************/

#include <nuttx/config.h>
#include "chip.h"

/****************************************************************************
 * Pre-processor Definitions
 ***************************************************************************/

/* Understood PHY types */

/* Definitions for use with rx65n_phy_boardinitialize */

#define RX65N_NETHERNET 1

#define EMAC0_INTF 0

/****************************************************************************
 * Public Functions
 ***************************************************************************/

#ifndef __ASSEMBLY__

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Functions
 ***************************************************************************/

/****************************************************************************
 * Function: rx65n_ethinitialize
 *
 * Description:
 *   Initialize the EMAC driver.
 *
 * Input Parameters:
 *   intf - If multiple EMAC peripherals are supported, this identifies the
 *     the EMAC peripheral being initialized.
 *
 * Returned Value:
 *   OK on success; Negated errno on failure.
 *
 * Assumptions:
 *   Called very early in the initialization sequence.
 *
 ****************************************************************************/

#ifdef CONFIG_RX65N_EMAC0
int rx65n_ethinitialize(int intf);

/****************************************************************************
 * Function: rx65n_poll_expiry
 *
 * Description:
 *   Poll Expiry timer
 *
 * Input Parameters:
 *   argc - Input argument
 *   arg  - Input argument
 *
 * Returned Value:
 *  None
 *
 ****************************************************************************/

void rx65n_poll_expiry(int argc, uint32_t arg, ...);

/****************************************************************************
 * Function: rx65n_txtimeout_expiry
 *
 * Description:
 *   txtimeout timer
 *
 * Input Parameters:
 *   argc - Input argument
 *   arg  - Input argument
 *
 * Returned Value:
 *  None
 *
 ****************************************************************************/

void rx65n_txtimeout_expiry(int argc, uint32_t arg, ...);
#endif

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_RENESAS_SRC_RX65N_RX65N_ETH_H */
