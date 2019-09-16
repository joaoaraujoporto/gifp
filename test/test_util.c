#include "../src/util.h"

void test_assert_equal_integer() {
    integer n, m;
    inits_i(n, m, NULL);

    set_i_ui(n, 1);
    set_i_ui(m, 1);
    assert_equal(true, assert_equal_integer(n, m));

    set_i_ui(m, 2);
    assert_equal(false, assert_equal_integer(n, m));

    set_i_s(m, "900000000000000000000000000000000000000000000000000000000000000000", 0);
    assert_equal(false, assert_equal_integer(n, m));

    set_i_s(n, "900000000000000000000000000400000000000000000000000000000000000000", 0);
    assert_equal(false, assert_equal_integer(n, m));

    set_i_s(n, "900000000000000000000000000000000000000000000000000000000000000000", 0);
    assert_equal(true, assert_equal_integer(n, m));

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
    assert_equal(65535, get_upper(16)); // limit for now
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

int main() {
    test_assert_equal_integer();
    // test_assert_equal_double();
    // test_assert_equal_real();
    // test_assert_equal_bool();
    // test_cdigits();
    // test_get_upper();
    // test_get_range();
    // test_contains();
}