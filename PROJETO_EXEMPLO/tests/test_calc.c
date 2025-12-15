#include "../inc/utest.h"
#include "../inc/calc.h"
#include <stdio.h>
#include <string.h>


/* Helper macros for printing test results */
#define PRINT_BIN_TEST_D(function, a, b, expected, actual) \
    printf("[          ] %s: %.2f %s %.2f = %.2f (expected %.2f)\n", (function), (a), op_from_function(function), (b), (actual), (expected))

#define PRINT_BIN_TEST_I(function, a, b, expected, actual) \
    printf("[          ]  %s: %d %s %d = %d (expected %d)\n", (function), (a), op_from_function(function), (b), (actual), (expected))

#define PRINT_UNARY_TEST(function, a, expected, actual) \
    printf("[          ] %s: |%.2f| = %.2f (expected %.2f)\n", (function), (a), (actual), (expected))

static const char *op_from_function(const char *function)
{
    if (strcmp(function, "Add") == 0) return "+";
    if (strcmp(function, "Sub") == 0) return "-";
    if (strcmp(function, "Mul") == 0) return "*";
    if (strcmp(function, "Div") == 0) return "/";
    if (strcmp(function, "Pow") == 0) return "^";
    if (strcmp(function, "Abs") == 0) return "| |";
    if (strcmp(function, "Mod") == 0) return "%";
    if (strcmp(function, "Min") == 0) return "or";
    if (strcmp(function, "Max") == 0) return "or";

    return "?";
}


/* Tolerance for floating-point comparisons */
#define TOLERANCE 1e-6

/* =========================================================
 *  COMMON VARIABLES
 * ========================================================= */
    double r;
    double a;
    double b;
    double expected;

    int r_int;
    int a_int;
    int b_int;
    int expected_int;


/* =========================================================
 *  ADDITION
 * ========================================================= */
UTEST(calculator_add, success)
{
    a = 2.0;
    b = 3.0;
    expected = 5.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_add(a, b, &r));

    PRINT_BIN_TEST_D("Add", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_add, null_result)
{
    ASSERT_EQ(CALC_ERROR_INVALID_ARGUMENT,
              calculator_add(1.0, 2.0, NULL));
}

/* =========================================================
 *  SUBTRACTION
 * ========================================================= */
UTEST(calculator_sub, success)
{
    a = 5.0;
    b = 3.0;
    expected = 2.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_sub(a, b, &r));
    PRINT_BIN_TEST_D("Sub", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_sub, negative_result)
{
    a = 3.0;
    b = 5.0;
    expected = -2.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_sub(a, b, &r));
    PRINT_BIN_TEST_D("Sub", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_sub, null_result)
{
    ASSERT_EQ(CALC_ERROR_INVALID_ARGUMENT,
              calculator_sub(1.0, 2.0, NULL));
}

/* =========================================================
 *  MULTIPLICATION
 * ========================================================= */
UTEST(calculator_mul, success)
{
    a = 4.0;
    b = 3.0;
    expected = 12.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_mul(a, b, &r));
    PRINT_BIN_TEST_D("Mul", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_mul, by_zero)
{
    a = 5.0;
    b = 0.0;
    expected = 0.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_mul(a, b, &r));
    PRINT_BIN_TEST_D("Mul", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_mul, null_result)
{
    ASSERT_EQ(CALC_ERROR_INVALID_ARGUMENT,
              calculator_mul(1.0, 2.0, NULL));
}

/* =========================================================
 *  DIVISION
 * ========================================================= */
UTEST(calculator_div, success)
{
    a = 10.0;
    b = 2.0;
    expected = 5.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_div(a, b, &r));
    PRINT_BIN_TEST_D("Div", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_div, divide_by_zero)
{
    a = 10.0;
    b = 0.0;
    expected = 0.0;
    r = 0.0;
    ASSERT_EQ(CALC_ERROR_DIV_BY_ZERO, calculator_div(a, b, &r));
    PRINT_BIN_TEST_D("Div", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_div, null_result)
{
    ASSERT_EQ(CALC_ERROR_INVALID_ARGUMENT,
              calculator_div(10.0, 2.0, NULL));
}

/* =========================================================
 *  POWER
 * ========================================================= */
UTEST(calculator_pow, success)
{
    a = 2.0;
    b = 3.0;
    expected = 8.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_pow(a, b, &r));
    PRINT_BIN_TEST_D("Pow", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_pow, zero_exponent)
{
    a = 5.0;
    b = 0.0;
    expected = 1.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_pow(a, b, &r));
    PRINT_BIN_TEST_D("Pow", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_pow, null_result)
{
    ASSERT_EQ(CALC_ERROR_INVALID_ARGUMENT,
              calculator_pow(2.0, 3.0, NULL));
}

/* =========================================================
 *  MODULO
 * ========================================================= */
UTEST(calculator_mod, success)
{
    a_int = 10;
    b_int = 3;
    expected_int = 1;
    r_int = 0;
    ASSERT_EQ(CALC_OK, calculator_mod(a_int, b_int, &r_int));
    PRINT_BIN_TEST_I("Mod", a_int, b_int, expected_int, r_int);
    ASSERT_EQ(expected_int, r_int);
}

UTEST(calculator_mod, divide_by_zero)
{
    a_int = 10;
    b_int = 0;
    expected_int = 0;
    r_int = 0;
    ASSERT_EQ(CALC_ERROR_DIV_BY_ZERO, calculator_mod(a_int, b_int, &r_int));
    PRINT_BIN_TEST_I("Mod", a_int, b_int, expected_int, r_int);
    ASSERT_EQ(expected_int, r_int);
}

UTEST(calculator_mod, null_result)
{
    ASSERT_EQ(CALC_ERROR_INVALID_ARGUMENT,
              calculator_mod(10, 3, NULL));
}

/* =========================================================
 *  ABSOLUTE VALUE
 * ========================================================= */
UTEST(calculator_abs, positive)
{
    a = 5.0;
    expected = 5.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_abs(a, &r));
    PRINT_UNARY_TEST("Abs", a, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_abs, negative)
{
    a = -5.0;
    expected = 5.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_abs(a, &r));
    PRINT_UNARY_TEST("Abs", a, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_abs, zero)
{
    a = 0.0;
    expected = 0.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_abs(a, &r));
    PRINT_UNARY_TEST("Abs", a, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_abs, null_result)
{
    ASSERT_EQ(CALC_ERROR_INVALID_ARGUMENT,
              calculator_abs(5.0, NULL));
}

/* =========================================================
 *  MIN
 * ========================================================= */
UTEST(calculator_min, first_smaller)
{
    a = 2.0;
    b = 3.0;
    expected = 2.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_min(a, b, &r));
    PRINT_BIN_TEST_D("Min", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_min, second_smaller)
{
    a = 5.0;
    b = 1.0;
    expected = 1.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_min(a, b, &r));
    PRINT_BIN_TEST_D("Min", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_min, equal)
{
    a = 5.0;
    b = 1.0;
    expected = 1.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_min(a, b, &r));
    PRINT_BIN_TEST_D("Min", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_min, null_result)
{
    ASSERT_EQ(CALC_ERROR_INVALID_ARGUMENT,
              calculator_min(1.0, 2.0, NULL));
}

/* =========================================================
 *  MAX
 * ========================================================= */
UTEST(calculator_max, first_bigger)
{
    a = 5.0;
    b = 3.0;
    expected = 5.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_max(a, b, &r));
    PRINT_BIN_TEST_D("Max", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_max, second_bigger)
{
    a = 2.0;
    b = 4.0;
    expected = 4.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_max(a, b, &r));
    PRINT_BIN_TEST_D("Max", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_max, equal)
{
    a = 3.0;
    b = 3.0;
    expected = 3.0;
    r = 0.0;
    ASSERT_EQ(CALC_OK, calculator_max(a, b, &r));
    PRINT_BIN_TEST_D("Max", a, b, expected, r);
    ASSERT_NEAR(expected, r, TOLERANCE);
}

UTEST(calculator_max, null_result)
{
    ASSERT_EQ(CALC_ERROR_INVALID_ARGUMENT,
              calculator_max(1.0, 2.0, NULL));
}

/* =========================================================
 *  Test runner
 * ========================================================= */
UTEST_MAIN();
