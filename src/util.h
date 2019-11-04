#ifndef __util_h__
#define __util_h__

#include "stdio.h"
#include "math.h"
#include "gmp.h"

/**
 * Type's alias for facility
 **/
typedef enum {
    false,
    true
} bool;

typedef mpz_t integer;
typedef mpf_t real;
typedef unsigned long int ul_int;
typedef unsigned int u_int;

/**
 * GMP's functions name redefined for facility
 **/
#define init_i __gmpz_init
#define inits_i __gmpz_inits
#define sum_i __gmpz_add
#define sum_i_ui __gmpz_add_ui
#define sub_i __gmpz_sub
#define sub_i_ui __gmpz_sub_ui
#define mul_i __gmpz_mul
#define clear_i __gmpz_clear
#define clears_i __gmpz_clears
#define set_i __gmpz_set
#define set_i_ui __gmpz_set_ui
#define set_i_r __gmpz_set_f
#define init_set_i_ui __gmpz_init_set_ui
#define cmp_i __gmpz_cmp
#define cmp_i_ui __gmpz_cmp_ui
#define mod_i __gmpz_mod
#define mod_i_ui mpz_fdiv_r_ui
#define divs_i_ui __gmpz_divisible_ui_p
#define div_i_ui mpz_cdiv_q_ui
#define pow_ui __gmpz_pow_ui
#define powm_i __gmpz_powm
#define get_i_s __gmpz_get_str /* Integer to string */
#define cmp_r __gmpf_cmp
#define init_r __gmpf_init
#define init_set_r_d __gmpf_init_set_d
#define inits_r __gmpf_inits
#define set_r __gmpf_set
#define set_r_d __gmpf_set_d
#define set_r_i __gmpf_set_z
#define set_r_s __gmpf_set_str
#define clear_r __gmpf_clear
#define clears_r __gmpf_clears
#define mul_r __gmpf_mul
#define div_r __gmpf_div


/**
 * Assert function's declaration
 **/
bool assert_equal(ul_int expected, ul_int actual);
bool assert_equal_bool(bool expected, bool actual);
bool assert_equal_double(double expected, double actual, int places_precision);
bool assert_equal_integer(const integer expected, const integer actual);
bool assert_equal_i_ui(ul_int expected, const integer actual);
bool assert_equal_real(const real expected, const real actual);
bool assert_equal_r_d(double expected, const real actual);

/**
 * Util function's declaration
 **/
bool equal_double(double expected, double actual, int places_precision);
u_int n_digits(ul_int number);
ul_int expi(int x, int y);
u_int get_upper(u_int n_bits);
void get_upper_i(integer upper, u_int n_bits);
void get_range(u_int n_bits, ul_int *b, ul_int *e);
void get_range_i(u_int n_bits, integer b, integer e);
bool contains(ul_int e, ul_int l[], ul_int size_l);

/**
 * Alias for GMP's function string to integer, defining base 10 as default
 **/
int set_i_s(integer i, const char * s) { mpz_set_str(i, s, 10); }

/**
 * Check wheter a ul_int value is equal to the expected value
 * and print on default output the result
 * @param expected is the value expected
 * @param actual is the value actually obtained
 * @return true if expected == actual and false otherwise
 **/
bool assert_equal(ul_int expected, ul_int actual) {
    if (expected == actual) {
        printf("passed\n");
        return true;
    }
    
    printf("Expected %ld, but actual %ld\n", expected, actual);
    return false;
}

/**
 * Check wheter a bool value is equal to the expected value
 * and print on default output the result
 * @param expected is the value expected
 * @param actual is the value actually obtained
 * @return true if expected == actual and false otherwise
 **/
bool assert_equal_bool(bool expected, bool actual) {
    if (expected == actual) {
        printf("passed\n");
        return true;
    }

    if (expected == true) printf("Expected true, but actual false\n");
    else printf("Expected false, but actual true\n");

    return false;
}

/**
 * Check wheter a integer value is equal to the expected value
 * and print on default output the result
 * @param expected is the value expected
 * @param actual is the value actually obtained
 * @return true if expected == actual and false otherwise
 **/
bool assert_equal_integer(const integer expected, const integer actual) {
    if (!cmp_i(expected, actual)) {
        printf("passed\n");
        return true;
    }

    gmp_printf("Expected %Zd, but actual %Zd\n", expected, actual);
    return false;
}

/**
 * Check wheter a integer value is equal to the expected value given as ul_int
 * and print on default output the result
 * @param expected is the value expected
 * @param actual is the value actually obtained
 * @return true if expected == actual and false otherwise
 **/
bool assert_equal_i_ui(ul_int expected, const integer actual) {
    integer expected_i;
    init_set_i_ui(expected_i, expected);
    assert_equal_integer(expected_i, actual);
    clear_i(expected_i);
}

/**
 * Check wheter a double value is equal to the expected value
 * and print on default output the result
 * @param expected is the value expected
 * @param actual is the value actually obtained
 * @param places_precision indicates until decilmal place values must be compared (limit 6 places)
 * @return true if expected == actual and false otherwise
 **/
bool assert_equal_double(double expected, double actual, int places_precision) {
    if (equal_double(expected, actual, places_precision)) {
        printf("passed\n");
        return true;
    }

    printf("Expected %.15f, but actual %.15f\n", expected, actual);
    return false;
}

/**
 * Check wheter a real value is equal to the expected value
 * and print on default output the result
 * @param expected is the value expected
 * @param actual is the value actually obtained
 * @return true if expected == actual and false otherwise
 **/
bool assert_equal_real(const real expected, const real actual) {
    if (!cmp_r(expected, actual)) {
        printf("passed\n");
        return true;
    }

    gmp_printf("Expected %.20Ff, but actual %.20Ff\n", expected, actual);
    return false;
}

/**
 * Check whether a real value is equal to the expected value given as double
 * and print on default output the result
 * @param expected is the value expected
 * @param actual is the value actually obtained
 * @return true if expected == actual and false otherwise
 **/
bool assert_equal_r_d(double expected, const real actual) {
    bool result;
    real expected_r;

    init_set_r_d(expected_r, expected);
    result = assert_equal_real(expected_r, actual);
    clear_r(expected_r);

    return result;
}

/**
 * Check wheter a double value is equal to the expected value
 * @param expected is the value expected
 * @param actual is the value actually obtained
 * @param places_precision indicates until decilmal place values must be compared (limit 6 places)
 * @return true if expected == actual and false otherwise
 **/
bool equal_double(double expected, double actual, int places_precision) {
    int i_expected = (int) trunc(expected);
    int i_actual = (int) trunc(actual);

    if (i_expected != i_actual) return false;

    double precision = 1;
    
    expected -= i_expected;
    actual -= i_actual;

    if (places_precision > 0) precision /= pow(10, places_precision);
    if (fabs(expected-actual) < precision) return true;
    
    return false;
}

/**
 * Counts the number of digits of a given unsigned long int and returns it
 * @param n is the number for counting
 * @return the number of digits that composes n
 **/
u_int n_digits(ul_int n) {
    u_int c = 1;
    for (; n/10 != 0; c++) n /= 10; 
    return c;
}

/**
 * Exponential function
 * @param x is the base 
 * @param y is the power (y >= 0)
 * @return x^y
 **/
ul_int expi(int x, int y) {
    if (y == 0) return 1;
    return x * expi(x, y-1);
}

/**
 * Returns the maximum ul_int that is possible to represent with n_bits
 * @param n_bits is the quantity of digits for representation
 * @return the maximum number representable by n_bits
 **/
u_int get_upper(u_int n_bits) {
    return expi(2, n_bits) - 1;
}

/**
 * Returns the maximum integer that is possible to represent with n_bits
 * @param upper is a pointer to the integer where will be stored the maximum integer value
 * @param n_bits is the quantity of digits for representation
 **/
void get_upper_i(integer upper, u_int n_bits) {
    integer base;

    init_set_i_ui(base, 2);
    pow_ui(upper, base, n_bits);
    sub_i_ui(upper, upper, 1);

    clear_i(base);
}

/**
 * Returns the range of ul_int values represented necessarely by n_bits
 * @param n_bits is the quantity of digits for representation
 * @param b is a pointer to the ul_int where will be stored the minimum value of the range
 * @param b is a pointer to the ul_int where will be stored the maximum value of the range
 **/
void get_range(u_int n_bits, ul_int *b, ul_int *e) {
    *b = get_upper(n_bits-1) + 1;
    if (n_bits == 1) *b -= 1;
    *e = get_upper(n_bits);
}

/**
 * Returns range of integer values represented necessarely by n_bits
 * @param n_bits is the quantity of digits for representation
 * @param b is a pointer to the integer where will be stored the minimum value of the range
 * @param b is a pointer to the integer where will be stored the maximum value of the range
 **/
void get_range_i(u_int n_bits, integer b, integer e) {
    get_upper_i(b, n_bits-1);
    sum_i_ui(b, b, 1);
    if (n_bits == 1) sub_i_ui(b, b, 1);
    get_upper_i(e, n_bits);
}

/**
 * Check wheter a ul_int array constains given element
 * @param e is the element
 * @param l is the array
 * @param size_l is the quantity of elements of array l
 * @return true if l constains e, false otherwise
 **/
bool contains(ul_int e, ul_int l[], ul_int size_l) {
    int i;

    for (i = 0; i < size_l; i++)
        if (e == l[i]) return true;

    return false;
}

/**
 * Returns the square root of a given double
 * @param n is the given double
 * @return the square root of n
 */
double ssqrt_d(double n) {
    int i;

    for (i = 1; ; i++) if (i*i >= n) break;

    double ii = (double) i - 0.5;
    double j = (double) i - 1;
    double iz = 2;
    double k = (ii-j);
    // printf("k = %.15f \n", k);
    while (!equal_double(n, ii*ii, 7)) {
        // printf("n = %ld \n", n);
        // printf("ii = %.15f \n", ii);
        // printf("ii*ii - n = %.15f \n", ii*ii - n);
        // printf("iz = %.0f \n", iz);

        k = k/2;
        // k = (ii - j)/iz;
        
        if (ii*ii < n) ii += k;
        else ii -= k;

        // iz = pow(2.71, iz);
        // iz = pow(2.71, iz)/(pow(2.71, iz) + 1) + 2;
        iz++;
        
        printf("k = %.100f \n", k);
        // printf("ii*ii = %.15f \n", ii*ii);
        // if (iz > 1200) break;
        // break;
    }

    return ii;
}

#endif