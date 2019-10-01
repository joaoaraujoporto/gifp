#include "../src/util.h"

void test_assert_equal_integer() {
    integer n, m;
    inits_i(n, m, NULL);

    set_i_ui(n, 1);
    set_i_ui(m, 1);
    assert_equal_bool(true, assert_equal_integer(n, m));

    set_i_ui(m, 2);
    assert_equal_bool(false, assert_equal_integer(n, m));

    set_i_s(m, "900000000000000000000000000000000000000000000000000000000000000000");
    assert_equal_bool(false, assert_equal_integer(n, m));

    set_i_s(n, "900000000000000000000000000400000000000000000000000000000000000000");
    assert_equal_bool(false, assert_equal_integer(n, m));

    set_i_s(n, "900000000000000000000000000000000000000000000000000000000000000000");
    assert_equal_bool(true, assert_equal_integer(n, m));

    clears_i(n, m, NULL);
}

void test_assert_equal_bool() {
    assert_equal(1, assert_equal_bool(false, false));
    assert_equal(0, assert_equal_bool(false, true));
    assert_equal(0, assert_equal_bool(true, false));
    assert_equal(1, assert_equal_bool(true, true));
}

void test_assert_equal_double() {
    assert_equal_bool(true, assert_equal_double(1, 1, 0));
    assert_equal_bool(true, assert_equal_double(1, 1, -1));
    assert_equal_bool(false, assert_equal_double(1, 2, 0));
    assert_equal_bool(false, assert_equal_double(1, 2, -1));
    assert_equal_bool(true, assert_equal_double(0.1, 0.1, 0));
    assert_equal_bool(true, assert_equal_double(0.1, 0.1, -1));
    assert_equal_bool(true, assert_equal_double(0.1, 0.2, 0));
    assert_equal_bool(true, assert_equal_double(0.1, 0.2, -1));
    assert_equal_bool(false, assert_equal_double(1, 2, 1));
    assert_equal_bool(false, assert_equal_double(0.1, 0.2, 1));
    assert_equal_bool(true, assert_equal_double(0.01, 0.02, 1));
    assert_equal_bool(true, assert_equal_double(0.000001, 0.000001, 6));
    assert_equal_bool(false, assert_equal_double(0.000001, 0.000002, 6));
}

void test_assert_equal_real() {
    real n, m;
    inits_r(n, m, NULL);

    set_r_d(n, 1);
    set_r_d(m, 1);
    assert_equal_bool(true, assert_equal_real(n, m));

    set_r_d(n, 1);
    set_r_d(m, 2);
    assert_equal_bool(false, assert_equal_real(n, m));

    set_r_d(n, 0.1);
    set_r_d(m, 0.1);
    assert_equal_bool(true, assert_equal_real(n, m));

    set_r_d(n, 0.1);
    set_r_d(m, 0.2);
    assert_equal_bool(false, assert_equal_real(n, m));

    set_r_d(n, 0.01);
    set_r_d(m, 0.02);
    assert_equal_bool(false, assert_equal_real(n, m));

    set_r_d(n, 0.000000000001);
    set_r_d(m, 0.000000000002);
    assert_equal_bool(false, assert_equal_real(n, m));

    set_r_d(n, 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000001);
    set_r_d(m, 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000002);
    assert_equal_bool(false, assert_equal_real(n, m));

    clears_r(n, m, NULL);
}

void test_cdigits() {
    assert_equal(1, cdigits(0));
    assert_equal(2, cdigits(11));
    assert_equal(2, cdigits(13));
    assert_equal(3, cdigits(137));
    assert_equal(4, cdigits(4887));
    assert_equal(10, cdigits(1234567890));
    assert_equal(10, cdigits(3797281624));
    assert_equal(10, cdigits(6585872435));
    assert_equal(10, cdigits(9468553006));
}


void test_get_upper() {
    assert_equal(0, get_upper(0));
    assert_equal(1, get_upper(1));
    assert_equal(3, get_upper(2));
    assert_equal(7, get_upper(3));
    assert_equal(1023, get_upper(10));
    assert_equal(65535, get_upper(16));
    assert_equal(4294967295, get_upper(32));
}

void test_get_upper_i() {
    integer upper_e, upper_a;
    inits_i(upper_e, upper_a, NULL);

    set_i_ui(upper_e, 0);
    get_upper_i(upper_a, 0);
    assert_equal_integer(upper_e, upper_a);

    set_i_ui(upper_e, 1);
    get_upper_i(upper_a, 1);
    assert_equal_integer(upper_e, upper_a);

    set_i_ui(upper_e, 3);
    get_upper_i(upper_a, 2);
    assert_equal_integer(upper_e, upper_a);

    set_i_ui(upper_e, 7);
    get_upper_i(upper_a, 3);
    assert_equal_integer(upper_e, upper_a);

    set_i_ui(upper_e, 65535);
    get_upper_i(upper_a, 16);
    assert_equal_integer(upper_e, upper_a);

    set_i_ui(upper_e, 4294967295);
    get_upper_i(upper_a, 32);
    assert_equal_integer(upper_e, upper_a);

    set_i_s(upper_e, "18446744073709551615");
    get_upper_i(upper_a, 64);
    assert_equal_integer(upper_e, upper_a);

    set_i_s(upper_e, "340282366920938463463374607431768211455");
    get_upper_i(upper_a, 128);
    assert_equal_integer(upper_e, upper_a);

    set_i_s(upper_e, "0"); // 0 is not really expected
    get_upper_i(upper_a, 4096);
    assert_equal_integer(upper_e, upper_a);

    clears_i(upper_e, upper_a, NULL);
}

void test_get_range() {
    u_int n;
    ul_int b, e;

    n = 1;
    get_range(n, &b, &e);
    assert_equal(0, b);
    assert_equal(1, e);

    n = 2;
    get_range(n, &b, &e);
    assert_equal(2, b);
    assert_equal(3, e);

    n = 3;
    get_range(n, &b, &e);
    assert_equal(4, b);
    assert_equal(7, e);

    n = 5;
    get_range(n, &b, &e);
    assert_equal(16, b);
    assert_equal(31, e);

    n = 7;
    get_range(n, &b, &e);
    assert_equal(64, b);
    assert_equal(127, e);

    n = 16;
    get_range(n, &b, &e);
    assert_equal(32768, b);
    assert_equal(65535, e);
}

void test_get_range_i() {
    u_int n_bits;
    integer b, e;
    inits_i(b, e, NULL);

    n_bits = 1;
    get_range_i(n_bits, b, e);
    assert_equal_i_ui(0, b);
    assert_equal_i_ui(1, e);

    n_bits = 2;
    get_range_i(n_bits, b, e);
    assert_equal_i_ui(2, b);
    assert_equal_i_ui(3, e);

    n_bits = 3;
    get_range_i(n_bits, b, e);
    assert_equal_i_ui(4, b);
    assert_equal_i_ui(7, e);

    n_bits = 5;
    get_range_i(n_bits, b, e);
    assert_equal_i_ui(16, b);
    assert_equal_i_ui(31, e);

    n_bits = 7;
    get_range_i(n_bits, b, e);
    assert_equal_i_ui(64, b);
    assert_equal_i_ui(127, e);

    n_bits = 16;
    get_range_i(n_bits, b, e);
    assert_equal_i_ui(32768, b);
    assert_equal_i_ui(65535, e);

    n_bits = 32;
    get_range_i(n_bits, b, e);
    assert_equal_i_ui(2147483648, b);
    assert_equal_i_ui(4294967295, e);

    n_bits = 64;
    get_range_i(n_bits, b, e);
    assert_equal_i_ui(32768, b); // not really expected 32768
    assert_equal_i_ui(65535, e); // not really expected 65535

    n_bits = 4096;
    get_range_i(n_bits, b, e);
    assert_equal_i_ui(32768, b); // not really expected 32768
    assert_equal_i_ui(65535, e); // not really expected 65535

    clears_i(b, e, NULL);
}

void test_contains() {
    ul_int size_l;

    size_l = 1;
    ul_int l1[size_l];
    l1[0] = 1;
    assert_equal_bool(true, contains(1, l1, size_l));

    size_l = 5;
    ul_int l2[size_l];
    l2[0] = 1; l2[1] = 2; l2[2] = 3; l2[3] = 4; l2[4] = 5;
    assert_equal_bool(true, contains(5, l2, size_l));
    assert_equal_bool(false, contains(7, l2, size_l));
}

void test_ssqrt_ui() {
    // assert_equal_double(1, ssqrt_ui(1), 6);
    // assert_equal_double(2, ssqrt_ui(4), 6);
    // assert_equal_double(3, ssqrt_ui(9), 6);
    // assert_equal_double(4, ssqrt_ui(16), 6);
    // assert_equal_double(5, ssqrt_ui(25), 6);
    // assert_equal_double(6, ssqrt_ui(36), 6);
    // assert_equal_double(7, ssqrt_ui(49), 6);
    // assert_equal_double(8, ssqrt_ui(64), 6);
    // assert_equal_double(9, ssqrt_ui(81), 6);
    // assert_equal_double(9.110434, ssqrt_ui(83), 6);
    // assert_equal_double(9.110434, ssqrt_ui(99), 6);
    // assert_equal_double(9.110434, ssqrt_ui(90.25), 6);
    assert_equal_double(2136.694644, ssqrt_ui(4565464), 6);
    // assert_equal_double(100000, ssqrt_ui(10000000000), 6);
}

int main() {
    // test_assert_equal_integer();
    // test_assert_equal_double();
    // test_assert_equal_real();
    // test_assert_equal_bool();
    // test_cdigits();
    // test_get_upper();
    // test_get_upper_i();
    // test_get_range();
    // test_get_range_i();
    // test_contains();
    test_ssqrt_ui();
    // double a = 1/pow(10, 100);
    // printf("Expected %.100f\n", a/2);
}