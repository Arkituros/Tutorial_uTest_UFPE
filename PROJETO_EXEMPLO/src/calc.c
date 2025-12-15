#include "../inc/calc.h"
#include <stdio.h>
#include <math.h>

/* ===============================
 *  helper
 * =============================== */
static bool is_null(void *ptr)
{
    return ptr == NULL;
}

/* ===============================
 *  Basic operations
 * =============================== */
calc_status_t calculator_add(double a, double b, double *result)
{
    if (is_null(result)) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }

    *result = a + b;
    return CALC_OK;
}

calc_status_t calculator_sub(double a, double b, double *result)
{
    if (is_null(result)) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }

    *result = a - b;
    return CALC_OK;
}

calc_status_t calculator_mul(double a, double b, double *result)
{
    if (is_null(result)) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }

    *result = a * b;
    return CALC_OK;
}

calc_status_t calculator_div(double a, double b, double *result)
{
    if (is_null(result)) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }

    if (b == 0.0) {
        return CALC_ERROR_DIV_BY_ZERO;
    }

    *result = a / b;
    return CALC_OK;
}

/* ===============================
 *  Advanced operations
 * =============================== */
calc_status_t calculator_pow(double base, double exp, double *result)
{
    if (is_null(result)) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }

    *result = pow(base, exp);
    return CALC_OK;
}

calc_status_t calculator_mod(int a, int b, int *result)
{
    if (is_null(result)) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }

    if (b == 0) {
        return CALC_ERROR_DIV_BY_ZERO;
    }

    *result = a % b;
    return CALC_OK;
}

calc_status_t calculator_abs(double a, double *result)
{
    if (is_null(result)) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }

    *result = (a < 0.0) ? -a : a;
    return CALC_OK;
}

calc_status_t calculator_min(double a, double b, double *result)
{
    if (is_null(result)) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }

    *result = (a < b) ? a : b;
    return CALC_OK;
}

calc_status_t calculator_max(double a, double b, double *result)
{
    if (is_null(result)) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }

    *result = (a > b) ? a : b;
    return CALC_OK;
}