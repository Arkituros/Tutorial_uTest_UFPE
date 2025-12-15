#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  Error codes
 */
typedef enum
{
    CALC_OK = 0,
    CALC_ERROR_DIV_BY_ZERO,
    CALC_ERROR_INVALID_ARGUMENT
} calc_status_t;

/*
 *  Function Prototypes 
 */
calc_status_t calculator_add(double a, double b, double *result);
calc_status_t calculator_sub(double a, double b, double *result);
calc_status_t calculator_mul(double a, double b, double *result);
calc_status_t calculator_div(double a, double b, double *result);
calc_status_t calculator_pow(double base, double exp, double *result);
calc_status_t calculator_mod(int a, int b, int *result);
calc_status_t calculator_abs(double a, double *result);
calc_status_t calculator_min(double a, double b, double *result);
calc_status_t calculator_max(double a, double b, double *result);

#ifdef __cplusplus
}
#endif

#endif /* CALCULATOR_H */
