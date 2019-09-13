#include "../src/gnp.h"
#include "../src/util.h"

void test_gnp() {
    /**
     * 0 is not really expected in this block
     */
    assert_equal(0, gnp(0, 1));
    assert_equal(0, gnp(1, 1));
    assert_equal(0, gnp(2, 1));
    assert_equal(0, gnp(3, 1));
    assert_equal(0, gnp(4, 1));
    assert_equal(0, gnp(5, 1));
    assert_equal(0, gnp(16, 1));
}

int main() {
    test_gnp();
}