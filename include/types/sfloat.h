/**
 * \file
 * \author       Kosma Moczek <kosma@cloudyourcar.com>
 * \brief
 */

#pragma once

//_____ I N C L U D E S _______________________________________________________
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#include "constants.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
typedef struct
{
    int_least32_t value;
    int_least32_t scale;
} sfloat_t;
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * \brief   Rescale a fixed-point value to a different scale. Rounds towards zero.
 *
 * \param   f[in] - sfloat number which need to be rescale.
 * \param   new_scale[in] - new scale value.
 *
 * \return  rescaled fixed-point number.
 */
static inline int_least32_t sfloat_rescale(sfloat_t *f, int_least32_t new_scale)
{
    if (f->scale == 0)
    {
        return 0;
    }

    if (f->scale == new_scale)
    {
        return f->value;
    }

    if (f->scale > new_scale)
    {
        return (f->value + ((f->value > 0) - (f->value < 0)) * f->scale / new_scale / 2) / (f->scale / new_scale);
    }
    else
    {
        return f->value * (new_scale / f->scale);
    }
}

/**
 * \brief   Convert a fixed-point sfloat value to a floating-point value.
 *  Returns NaN for "unknown" values.
 *
 * \param   f[in] - sfloat number.
 *
 * \return  float number.
 */
static inline float sfloat_to_float(sfloat_t *f)
{
    if (f->scale == 0)
    {
        return NAN;
    }

    return ((float)f->value / (float)f->scale);
}

/**
 * \brief   Convert a float-point number into fixed-point sfloat number
 *
 * \param   fnum[in] - float-point number.
 *
 * \return  fixed-point number.
 */
static inline sfloat_t float_to_sfloat(float fnum)
{
    float cpart, dpart;
    uint8_t i = 0, j = 0, k = 0;
    int8_t sign = 1;
    sfloat_t sf = {0, 1};

    if (fnum == 0.0f)
    {
        return sf;
    }

    sign = (fnum > 0) ? 1 : -1;
    fnum *= sign;

    do
    {
        fnum = fnum / 10;
        i++;
    } while ((uint16_t)fnum > 0);

    do
    {
        j++;
        fnum = fnum * 10.0f;
        dpart = modff(fnum, &cpart);
    } while (dpart != 0.0f);

    sf.value = cpart * sign;
    sf.scale = 1ul;

    k = j - i;
    for (uint8_t a = 0; a < k; a++)
    {
        sf.scale *= 10;
    }

    return sf;
}
