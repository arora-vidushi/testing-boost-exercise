#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"
using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    test = MatrixXd(3, 3);
    test << 1, 1, 0,
        3, 1, 0,
        0, 2, 1;
  }

  MatrixXd test;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture)

BOOST_AUTO_TEST_CASE(openDataTest)
{
  matrixIO::saveData("../data/temp.csv", test);

  MatrixXd output = matrixIO::openData("../data/temp.csv", 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      BOOST_TEST(test(i, j) == output(i, j));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()