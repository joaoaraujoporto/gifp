#include "miller_rabin.h"
#include "util.h"

void test_get_rd() {
    int n, r, d;

    n = -1;
    assert_equal_bool(false, get_rd(n, &r, &d));

    n = 0;
    assert_equal_bool(false, get_rd(n, &r, &d));

    n = 1;
    assert_equal_bool(false, get_rd(n, &r, &d));

    n = 2;
    assert_equal_bool(true, get_rd(n, &r, &d));
    assert_equal(r, 0);
    assert_equal(d, 1);

    n = 3;
    assert_equal_bool(true, get_rd(n, &r, &d));
    assert_equal(r, 1);
    assert_equal(d, 1);

    n = 5;
    assert_equal_bool(true, get_rd(n, &r, &d));
    assert_equal(r, 2);
    assert_equal(d, 1);

    n = 7;
    assert_equal_bool(true, get_rd(n, &r, &d));
    assert_equal(r, 1);
    assert_equal(d, 3);
}

void test_is_prime() {
    assert_equal_bool(false, is_prime(4, 1));
    assert_equal_bool(false, is_prime(6, 1));
    assert_equal_bool(false, is_prime(8, 1));
    assert_equal_bool(false, is_prime(9, 1));
    assert_equal_bool(false, is_prime(15, 1));
    assert_equal_bool(false, is_prime(21, 1));
    assert_equal_bool(false, is_prime(87, 100));

    assert_equal_bool(true, is_prime(5, 1));
    assert_equal_bool(true, is_prime(7, 1));
    assert_equal_bool(true, is_prime(11, 1));
    assert_equal_bool(true, is_prime(13, 1));
    assert_equal_bool(true, is_prime(17, 1));
    assert_equal_bool(true, is_prime(17, 1));
    assert_equal_bool(true, is_prime(97, 1));
}

int main() {
    // test_get_rd();
    test_is_prime();
}