#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

S21Matrix create_from_arr(const int rows, const int cols, double *a) {
  S21Matrix m = S21Matrix(rows, cols);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      m(i, j) = a[i * cols + j];
    }
  delete[] a;
  return m;
}

TEST(constructor, basic_constructor) {
  S21Matrix m;
  EXPECT_EQ(m.getCols(), 3);
  EXPECT_EQ(m.getRows(), 3);
  for (int i = 0; i < m.getCols(); i++)
    for (int j = 0; j < m.getRows(); j++) EXPECT_EQ(m(i, j), 0);
  m.print();
}
TEST(constructor, parameterized_constructor) {
  S21Matrix m = S21Matrix(4, 3);
  EXPECT_EQ(m.getRows(), 4);
  EXPECT_EQ(m.getCols(), 3);
  for (int i = 0; i < m.getRows(); i++)
    for (int j = 0; j < m.getCols(); j++) EXPECT_EQ(m(i, j), 0);
  EXPECT_THROW({ S21Matrix m2 = S21Matrix(0, 1); }, std::invalid_argument);
  EXPECT_THROW({ S21Matrix m3 = S21Matrix(213, 0); }, std::invalid_argument);
  EXPECT_THROW({ S21Matrix m4 = S21Matrix(0, 0); }, std::invalid_argument);
  EXPECT_THROW({ S21Matrix m5 = S21Matrix(-5, 1); }, std::invalid_argument);
  EXPECT_THROW({ S21Matrix m6 = S21Matrix(34, -43); }, std::invalid_argument);
  EXPECT_THROW({ S21Matrix m7 = S21Matrix(-1, -3); }, std::invalid_argument);
}

TEST(EqMatrix, test1) {
  S21Matrix m1 = S21Matrix(4, 3);
  S21Matrix m_error1 = S21Matrix(2, 2);
  S21Matrix m_error2 = S21Matrix(2, 3);
  S21Matrix m_error3 = S21Matrix(4, 2);
  EXPECT_EQ(m1.EqMatrix(m_error1), false);
  EXPECT_EQ(m1.EqMatrix(m_error2), false);
  EXPECT_EQ(m1.EqMatrix(m_error3), false);
  S21Matrix m2 = S21Matrix(4, 3);
  EXPECT_EQ(m1.EqMatrix(m2), true);
  m2(1, 1) = 1;
  EXPECT_EQ(m1.EqMatrix(m2), false);
  S21Matrix m3 = S21Matrix(1, 1);
  S21Matrix m4 = S21Matrix(1, 1);
  m3(0, 0) = 5.34;
  m4(0, 0) = 5.34;
  EXPECT_EQ(m4.EqMatrix(m3), true);
  m4(0, 0) = 6.5;
  EXPECT_EQ(m4.EqMatrix(m3), false);
  S21Matrix m5 = S21Matrix(4, 3);
  S21Matrix m6 = S21Matrix(4, 3);
  m6(3, 2) = 1;
  EXPECT_EQ(m4.EqMatrix(m3), false);
}

TEST(copy_constructor, test1) {
  S21Matrix m1 = S21Matrix(1, 2);
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  S21Matrix m2 = S21Matrix(m1);
  EXPECT_EQ(m2.EqMatrix(m1), true);
}

TEST(move_constructor, test1) {
  S21Matrix m1 = S21Matrix(3, 3);
  m1(0, 0) = -1;
  S21Matrix m1_copy = S21Matrix(m1);
  S21Matrix m2 = std::move(m1);
  EXPECT_EQ(m1_copy.EqMatrix(m2), true);
  EXPECT_EQ(m1.getRows(), 0);
  EXPECT_EQ(m1.getCols(), 0);
  EXPECT_THROW({ m1(0, 0); }, std::out_of_range);
}

TEST(SumMatrix, test1) {
  S21Matrix a = create_from_arr(
      4, 3, new double[4 * 3]{1, 2, 3, 4, -1, -2, -3.5, -4.5, 0, -1, 5.55, 4});
  S21Matrix b = create_from_arr(
      4, 3,
      new double[4 * 3]{1, 1, 1, -1, -5.5, 0, 0.001, 0.001, 0.001, -1, -2, -3});
  S21Matrix c = create_from_arr(4, 3,
                                new double[4 * 3]{2, 3, 4, 3, -6.5, -2, -3.499,
                                                  -4.499, 0.001, -2, 3.55, 1});
  b.SumMatrix(a);
  EXPECT_EQ(b.EqMatrix(c), true);
  S21Matrix d;
  EXPECT_THROW({ d.SumMatrix(a); }, std::invalid_argument);
  EXPECT_THROW({ a.SumMatrix(d); }, std::invalid_argument);
  S21Matrix e = S21Matrix(2, 2);
  EXPECT_THROW({ e.SumMatrix(a); }, std::invalid_argument);
  EXPECT_THROW({ a.SumMatrix(e); }, std::invalid_argument);
  S21Matrix f = S21Matrix(2, 3);
  EXPECT_THROW({ f.SumMatrix(b); }, std::invalid_argument);
  EXPECT_THROW({ b.SumMatrix(f); }, std::invalid_argument);
}

TEST(SubMatrix, test1) {
  S21Matrix a = create_from_arr(
      4, 3, new double[4 * 3]{1, 2, 3, 4, -1, -2, -3.5, -4.5, 0, -1, 5.55, 4});
  S21Matrix b = create_from_arr(
      4, 3,
      new double[4 * 3]{1, 1, 1, -1, -5.5, 0, 0.001, 0.001, 0.001, -1, -2, -3});
  S21Matrix c = create_from_arr(4, 3,
                                new double[4 * 3]{0, 1, 2, 5, 4.5, -2, -3.501,
                                                  -4.501, -0.001, 0, 7.55, 7});
  a.SubMatrix(b);
  EXPECT_EQ(a.EqMatrix(c), true);
  S21Matrix d;
  EXPECT_THROW({ d.SubMatrix(a); }, std::invalid_argument);
  EXPECT_THROW({ a.SubMatrix(d); }, std::invalid_argument);
  S21Matrix e = S21Matrix(2, 2);
  EXPECT_THROW({ e.SubMatrix(a); }, std::invalid_argument);
  EXPECT_THROW({ a.SubMatrix(e); }, std::invalid_argument);
  S21Matrix f = S21Matrix(2, 3);
  EXPECT_THROW({ f.SubMatrix(b); }, std::invalid_argument);
  EXPECT_THROW({ b.SubMatrix(f); }, std::invalid_argument);
}

TEST(MulNumber, test1) {
  S21Matrix a = create_from_arr(3, 1, new double[3]{1, 2, 3});
  S21Matrix b = create_from_arr(3, 1, new double[3]{-2, -4, -6});
  a.MulNumber(-2);
  EXPECT_EQ(a.EqMatrix(b), true);
}

TEST(OperatorPlus, test1) {
  S21Matrix a = create_from_arr(3, 1, new double[3]{1, 2, 3});
  S21Matrix b = create_from_arr(3, 1, new double[3]{-2, -4, -6});
  S21Matrix c = create_from_arr(3, 1, new double[3]{-1, -2, -3});
  S21Matrix d = create_from_arr(2, 1, new double[3]{10, 11});
  EXPECT_EQ(c.EqMatrix(a + b), true);
  EXPECT_THROW({ a + d; }, std::invalid_argument);
}

TEST(OperatorMinus, test1) {
  S21Matrix a = create_from_arr(3, 1, new double[3]{1, 2, 3});
  S21Matrix b = create_from_arr(3, 1, new double[3]{-2, -4, -6});
  S21Matrix c = create_from_arr(3, 1, new double[3]{3, 6, 9});
  S21Matrix c2 = create_from_arr(3, 1, new double[3]{-3, -6, -9});
  S21Matrix d = create_from_arr(2, 1, new double[2]{10, 11});
  EXPECT_EQ(c.EqMatrix(a - b), true);
  EXPECT_EQ(c2.EqMatrix(b - a), true);
  EXPECT_THROW({ a - d; }, std::invalid_argument);
  EXPECT_THROW({ d - a; }, std::invalid_argument);
}

TEST(OperatorEqual, test1) {
  S21Matrix a = create_from_arr(3, 1, new double[3]{1, 2, 3});
  S21Matrix b = create_from_arr(3, 1, new double[3]{1, 2, 4});
  S21Matrix c = create_from_arr(3, 1, new double[3]{1, 2, 3});
  S21Matrix d = create_from_arr(1, 2, new double[2]{1, 2});
  S21Matrix e = create_from_arr(2, 1, new double[2]{1, 2});
  EXPECT_EQ(a == c, true);
  EXPECT_EQ(c == a, true);
  EXPECT_EQ(c == b, false);
  EXPECT_EQ(a == d, false);
  EXPECT_EQ(d == a, false);
  EXPECT_EQ(a == e, false);
  EXPECT_EQ(e == a, false);
}

TEST(OperatorAssignment, test1) {
  S21Matrix a = create_from_arr(3, 2, new double[6]{1, 2, 3, 4, 5, 6});
  S21Matrix b = create_from_arr(3, 1, new double[3]{1, 2, 3});
  b = a;
  EXPECT_EQ(b == a, true);
  a = b;
  EXPECT_EQ(b == a, true);
}

TEST(OperatorBrackets, test1) {
  S21Matrix a =
      create_from_arr(2, 3, new double[6]{-5, -5.1, 3.4, 5.6, 123.4, 44});
  EXPECT_EQ(a(0, 0), -5);
  EXPECT_EQ(a(0, 1), -5.1);
  EXPECT_EQ(a(0, 2), 3.4);
  EXPECT_EQ(a(1, 0), 5.6);
  EXPECT_EQ(a(1, 1), 123.4);
  EXPECT_EQ(a(1, 2), 44);
  EXPECT_THROW({ a(-1, 0); }, std::out_of_range);
  EXPECT_THROW({ a(0, -1); }, std::out_of_range);
  EXPECT_THROW({ a(3, 0); }, std::out_of_range);
  EXPECT_THROW({ a(3, 3); }, std::out_of_range);
  EXPECT_THROW({ a(0, 4); }, std::out_of_range);
  EXPECT_THROW({ a(1, 4); }, std::out_of_range);
  EXPECT_THROW({ a(6, 6); }, std::out_of_range);
  a(0, 0) = 3;
  EXPECT_EQ(a(0, 0), 3);
}

TEST(Operator_Plus_Assignment, test1) {
  S21Matrix a = create_from_arr(3, 1, new double[3]{1, 2, 3});
  S21Matrix b = create_from_arr(3, 1, new double[3]{-2, -3, -5});
  S21Matrix c = create_from_arr(3, 1, new double[3]{-1, -1, -2});
  a += b;
  EXPECT_EQ(a == c, true);
}
TEST(Operator_Minus_Assignment, test1) {
  S21Matrix a = create_from_arr(3, 1, new double[3]{1, 2, 3});
  S21Matrix b = create_from_arr(3, 1, new double[3]{2, 3, 5});
  S21Matrix c = create_from_arr(3, 1, new double[3]{-1, -1, -2});
  a -= b;
  EXPECT_EQ(a == c, true);
}

TEST(MulMatrix, test1) {
  //             1 4    1 -1  1    9 11 17
  // C = A × B = 2 5  × 2  3  4 = 12 13 22
  //             3 6              15 15 27
  S21Matrix a = create_from_arr(3, 2, new double[6]{1, 4, 2, 5, 3, 6});
  S21Matrix b = create_from_arr(2, 3, new double[6]{1, -1, 1, 2, 3, 4});
  S21Matrix c =
      create_from_arr(3, 3, new double[9]{9, 11, 17, 12, 13, 22, 15, 15, 27});
  S21Matrix d = create_from_arr(2, 2, new double[4]{0, 0, 0, 0});
  a.MulMatrix(b);
  // a.print();
  // std::cout << a.getRows() << ' ' << a.getCols() << '\n';
  EXPECT_THROW({ a.MulMatrix(d); }, std::invalid_argument);
  EXPECT_EQ(a == c, true);
}

TEST(OperatorMulAssignment, test1) {
  //             1 4    1 -1  1    9 11 17
  // C = A × B = 2 5  × 2  3  4 = 12 13 22
  //             3 6              15 15 27
  S21Matrix a = create_from_arr(3, 2, new double[6]{1, 4, 2, 5, 3, 6});
  S21Matrix b = create_from_arr(2, 3, new double[6]{1, -1, 1, 2, 3, 4});
  S21Matrix c =
      create_from_arr(3, 3, new double[9]{9, 11, 17, 12, 13, 22, 15, 15, 27});
  S21Matrix d = create_from_arr(3, 2, new double[6]{0, 0, 0, 0, 0, 0});
  EXPECT_THROW({ a *= d; }, std::invalid_argument);
  a *= b;
  EXPECT_EQ(a == c, true);
}

TEST(OperatorMul, test1) {
  //             1 4    1 -1  1    9 11 17
  // C = A × B = 2 5  × 2  3  4 = 12 13 22
  //             3 6              15 15 27
  S21Matrix a = create_from_arr(3, 2, new double[6]{1, 4, 2, 5, 3, 6});
  S21Matrix b = create_from_arr(2, 3, new double[6]{1, -1, 1, 2, 3, 4});
  S21Matrix c =
      create_from_arr(3, 3, new double[9]{9, 11, 17, 12, 13, 22, 15, 15, 27});
  S21Matrix d = create_from_arr(3, 2, new double[6]{0, 0, 0, 0, 0, 0});
  EXPECT_THROW({ a *d; }, std::invalid_argument);

  EXPECT_EQ(a * b == c, true);
}

TEST(Tranpose, test1) {
  // 1 2   1 3 5 7
  // 3 4   2 4 6 8
  // 5 6
  // 7 8
  S21Matrix a = create_from_arr(4, 2, new double[8]{1, 2, 3, 4, 5, 6, 7, 8});
  S21Matrix b = create_from_arr(2, 4, new double[8]{1, 3, 5, 7, 2, 4, 6, 8});

  EXPECT_EQ(a.Transpose() == b, true);
  EXPECT_EQ(b.Transpose() == a, true);

  S21Matrix c = create_from_arr(2, 2, new double[4]{1, 2, 3, 4});
  S21Matrix d = create_from_arr(2, 2, new double[4]{1, 3, 2, 4});

  EXPECT_EQ(c.Transpose() == d, true);
  EXPECT_EQ(d.Transpose() == c, true);
}

TEST(ResizeTest, test1) {
  S21Matrix m = create_from_arr(3, 2, new double[6]{1, 2, 3, 4, 5, 6});
  S21Matrix a =
      create_from_arr(3, 4, new double[12]{1, 2, 0, 0, 3, 4, 0, 0, 5, 6, 0, 0});
  S21Matrix b = create_from_arr(
      4, 4, new double[16]{1, 2, 0, 0, 3, 4, 0, 0, 5, 6, 0, 0, 0, 0, 0, 0});
  S21Matrix c = create_from_arr(2, 1, new double[2]{1, 3});
  m.setCols(4);
  EXPECT_EQ(m == a, true);
  m.setRows(4);
  EXPECT_EQ(m == b, true);
  m.setRows(2);
  m.setCols(1);
  // std::cout << m.getRows() << ' ' << m.getCols() << '\n';
  EXPECT_EQ(m == c, true);
}

TEST(ResizeTest, test2) {
  S21Matrix m = create_from_arr(3, 2, new double[6]{1, 2, 3, 4, 5, 6});
  EXPECT_THROW({ m.setCols(-1); }, std::invalid_argument);
  EXPECT_THROW({ m.setCols(0); }, std::invalid_argument);
  EXPECT_THROW({ m.setRows(-100); }, std::invalid_argument);
  EXPECT_THROW({ m.setRows(0); }, std::invalid_argument);
}

TEST(Determinant, test1) {
  S21Matrix m = create_from_arr(
      4, 4,
      new double[16]{100, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17});
  double d = m.Determinant();
  EXPECT_EQ(d, -396);
  S21Matrix a = create_from_arr(1, 1, new double[1]{-5.454});
  EXPECT_EQ(a.Determinant(), -5.454);
  S21Matrix b = create_from_arr(1, 2, new double[2]{-5.454, 2});
  EXPECT_THROW({ b.Determinant(); }, std::invalid_argument);
  S21Matrix c = create_from_arr(2, 2, new double[4]{1, 2, 3, 4});
  EXPECT_EQ(c.Determinant(), -2);
}

TEST(CalcComplements, test1) {
  S21Matrix a = create_from_arr(1, 2, new double[2]{-5.454, 2});
  EXPECT_THROW({ a.CalcComplements(); }, std::invalid_argument);
  S21Matrix b = create_from_arr(3, 3, new double[9]{1, 2, 3, 0, 4, 2, 5, 2, 1});
  S21Matrix res_b =
      create_from_arr(3, 3, new double[9]{0, 10, -20, 4, -14, 8, -8, -2, 4});
  EXPECT_EQ(b.CalcComplements() == res_b, true);
  S21Matrix c = create_from_arr(1, 1, new double[1]{1});
  EXPECT_THROW({ c.CalcComplements(); }, std::invalid_argument);
}

TEST(InverceMatrix, test1) {
  S21Matrix a =
      create_from_arr(3, 3, new double[9]{2., 5., 7., 6., 3., 4., 5., -2, -3.});
  S21Matrix res_a = create_from_arr(
      3, 3, new double[9]{1., -1., 1., -38., 41., -34., 27., -29., 24.});
  EXPECT_EQ(a.InverseMatrix() == res_a, true);
}

TEST(InverceMatrix, test2) {
  S21Matrix m_zero_det =
      create_from_arr(3, 3, new double[9]{1, 1, 3, 1, 1, 3, 2, -1, 4});
  EXPECT_THROW({ m_zero_det.InverseMatrix(); }, std::invalid_argument);
}

TEST(InverceMatrix, test3) {
  S21Matrix b = create_from_arr(1, 2, new double[2]{-5.454, 2});
  EXPECT_THROW({ b.InverseMatrix(); }, std::invalid_argument);
}

TEST(InverceMatrix, test4) {
  S21Matrix c = create_from_arr(1, 1, new double[1]{4});
  S21Matrix res_c = create_from_arr(1, 1, new double[1]{0.25});
  EXPECT_EQ(c.InverseMatrix() == res_c, true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}