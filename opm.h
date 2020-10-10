/* Nuked OPM
 * Copyright (C) 2020 Nuke.YKT
 *
 * This file is part of Nuked OPM.
 *
 * Nuked OPM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 2.1
 * of the License, or (at your option) any later version.
 *
 * Nuked OPM is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Nuked OPM. If not, see <https://www.gnu.org/licenses/>.
 *
 *  Nuked OPM emulator.
 *  Thanks:
 *      siliconpr0n.org(digshadow, John McMaster):
 *          YM2151 and other FM chip decaps and die shots.
 *
 * version: 0.0
 */
#ifndef _OPM_H_
#define _OPM_H_

#include <stdint.h>


typedef struct {
    uint32_t cycles;
    uint8_t ic;
    // IO
    uint8_t write_data;
    uint8_t write_a;
    uint8_t write_a_en;
    uint8_t write_d;
    uint8_t write_d_en;
    uint8_t write_busy;
    uint8_t write_busy_cnt;
    uint8_t mode_address;
    uint8_t io_ct1;
    uint8_t io_ct2;

    // LFO
    uint8_t lfo_am_lock;
    uint8_t lfo_pm_lock;

    // Env Gen
    uint8_t eg_state[32];
    uint8_t eg_rate;
    uint8_t eg_ksv;
    uint8_t eg_ratesel;
    uint8_t eg_sl[2];
    uint8_t eg_tl[2];

    // Phase Gen
    uint16_t pg_fnum[32];
    uint8_t pg_kcode[32];
    uint32_t pg_inc[32];
    uint32_t pg_phase[32];
    uint8_t pg_reset[32];
    uint8_t pg_reset_latch[32];
    uint8_t pg_reset_lt;

    // Register set
    uint8_t mode_test[8];
    uint8_t mode_kon_operator[4];
    uint8_t mode_kon_channel;

    uint8_t reg_address;
    uint8_t reg_address_ready;
    uint8_t reg_data;
    uint8_t reg_data_ready;

    uint8_t ch_rl[8];
    uint8_t ch_fb[8];
    uint8_t ch_connect[8];
    uint8_t ch_kc[8];
    uint8_t ch_kf[8];
    uint8_t ch_pms[8];
    uint8_t ch_ams[8];

    uint8_t sl_dt1[32];
    uint8_t sl_mul[32];
    uint8_t sl_tl[32];
    uint8_t sl_ks[32];
    uint8_t sl_ar[32];
    uint8_t sl_am_e[32];
    uint8_t sl_d1r[32];
    uint8_t sl_dt2[32];
    uint8_t sl_d2r[32];
    uint8_t sl_d1l[32];
    uint8_t sl_rr[32];

    uint8_t noise_en;
    uint8_t noise_freq;

    uint16_t timer_a_reg;
    uint8_t timer_b_reg;

    uint8_t lfo_freq_hi;
    uint8_t lfo_freq_lo;
    uint8_t lfo_pmd;
    uint8_t lfo_amd;
    uint8_t lfo_wave;

    uint8_t kon_csm;
    uint8_t kon_do;
    uint8_t kon_chanmatch;
    uint8_t kon[32];
    uint8_t mode_kon[32];
} opm_t;

#endif
