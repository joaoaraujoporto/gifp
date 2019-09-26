#include "../src/miller_rabin.h"
#include "../src/util.h"

void test_get_rd() {
    ul_int n, r, d;

    n = 0;
    assert_equal_bool(false, get_rd(n, &r, &d));

    n = 1;
    assert_equal_bool(false, get_rd(n, &r, &d));

    n = 2;
    assert_equal_bool(true, get_rd(n, &r, &d));
    assert_equal(0, r);
    assert_equal(1, d);

    n = 3;
    assert_equal_bool(true, get_rd(n, &r, &d));
    assert_equal(1, r);
    assert_equal(1, d);

    n = 5;
    assert_equal_bool(true, get_rd(n, &r, &d));
    assert_equal(2, r);
    assert_equal(1, d);

    n = 7;
    assert_equal_bool(true, get_rd(n, &r, &d));
    assert_equal(1, r);
    assert_equal(3, d);

    n = 4097;
    assert_equal_bool(true, get_rd(n, &r, &d));
    assert_equal(12, r);
    assert_equal(1, d);

    n = 36545;
    assert_equal_bool(true, get_rd(n, &r, &d));
    assert_equal(6, r);
    assert_equal(571, d);
}

void test_get_rd_i() {
    integer n, r, d;
    inits_i(n, r, d, NULL);

    set_i_ui(n, 0);
    assert_equal_bool(false, get_rd_i(n, r, d));

    set_i_ui(n, 1);
    assert_equal_bool(false, get_rd_i(n, r, d));

    set_i_ui(n, 2);
    assert_equal_bool(true, get_rd_i(n, r, d));
    assert_equal_i_ui(0, r);
    assert_equal_i_ui(1, d);

    set_i_ui(n, 3);
    assert_equal_bool(true, get_rd_i(n, r, d));
    assert_equal_i_ui(1, r);
    assert_equal_i_ui(1, d);

    set_i_ui(n, 5);
    assert_equal_bool(true, get_rd_i(n, r, d));
    assert_equal_i_ui(2, r);
    assert_equal_i_ui(1, d);

    set_i_ui(n, 7);
    assert_equal_bool(true, get_rd_i(n, r, d));
    assert_equal_i_ui(1, r);
    assert_equal_i_ui(3, d);

    set_i_ui(n, 4097);
    assert_equal_bool(true, get_rd_i(n, r, d));
    assert_equal_i_ui(12, r);
    assert_equal_i_ui(1, d);

    set_i_ui(n, 36545);
    assert_equal_bool(true, get_rd_i(n, r, d));
    assert_equal_i_ui(6, r);
    assert_equal_i_ui(571, d);

    set_i_s(n, "99999999999999999999999999999999999999999999999999999999999999999999998999999999998");
    assert_equal_bool(true, get_rd_i(n, r, d));
    assert_equal_i_ui(0, r);
    assert_equal_i_ui(571, d); // not really expected 571

    clears_i(n, r, d, NULL);
}


void test_is_prime() {
    assert_equal_bool(false, is_prime(4, 1));
    assert_equal_bool(false, is_prime(6, 1));
    assert_equal_bool(false, is_prime(8, 1));
    assert_equal_bool(false, is_prime(9, 1));
    assert_equal_bool(false, is_prime(15, 1));
    assert_equal_bool(false, is_prime(21, 1));
    assert_equal_bool(false, is_prime(87, 100));
    
    assert_equal_bool(false, is_prime(36545, 3));
    assert_equal_bool(false, is_prime(4097, 3));
    assert_equal_bool(true, is_prime(40961, 3));

    assert_equal_bool(true, is_prime(97, 1));
    assert_equal_bool(true, is_prime(5, 1));
    assert_equal_bool(true, is_prime(7, 1));
    assert_equal_bool(true, is_prime(11, 1));
    assert_equal_bool(true, is_prime(13, 1));
    assert_equal_bool(true, is_prime(17, 1));
    assert_equal_bool(true, is_prime(17, 1));
    assert_equal_bool(true, is_prime(97, 1));
    
    // assert_equal_bool(true, is_prime(1000000000000066600000000000001, 1));
}

int main() {
    // test_get_rd();
    test_get_rd_i();
    // test_is_prime();
}