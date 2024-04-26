#include "s21_matrix_oop.h"

//Геттеры сеттеры
int S21Matrix::getRows() { return rows_; }
int S21Matrix::getCols() { return cols_; }
void S21Matrix::setRows(int rows) {
  if (rows <= 0) throw std::invalid_argument("Недопустимое количество строк");
  double** new_matrix = new double*[rows]();
  for (int i = 0; i < rows; i++) {
    new_matrix[i] = new double[cols_]();
    if (i >= rows_) continue;
    for (int j = 0; j < cols_; j++) {
      new_matrix[i][j] = matrix_[i][j];
    }
  }
  this->~S21Matrix();
  rows_ = rows;
  matrix_ = new_matrix;
}
void S21Matrix::setCols(int cols) {
  if (cols <= 0)
    throw std::invalid_argument("Недопустимое количество столбцов");

  double** new_matrix = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    new_matrix[i] = new double[cols]();
    for (int j = 0; j < std::min(cols, cols_); j++) {
      new_matrix[i][j] = matrix_[i][j];
    }
  }
  this->~S21Matrix();
  cols_ = cols;
  matrix_ = new_matrix;
}

//функции
S21Matrix::S21Matrix() : rows_(3), cols_(3) {
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) matrix_[i] = new double[cols_]();
}
S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0)
    throw std::invalid_argument("Недопустимый размер матрицы");
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) matrix_[i] = new double[cols_]();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = other.matrix_[i][j];
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool res = true;
  if (cols_ != other.cols_ || rows_ != other.rows_)
    res = false;
  else {
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++)
        if (std::abs(matrix_[i][j] - other.matrix_[i][j]) >=
            1e-7) {  //Сравнение до 7ого знака
          res = false;
          break;
        }
  }
  return res;
}

S21Matrix::S21Matrix(S21Matrix&& other) : rows_(0), cols_(0), matrix_(nullptr) {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) delete[] matrix_[i];
    delete[] matrix_;
  }
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ ||
      cols_ != other.cols_)  //Несоответствие размеров матрицы
    throw std::invalid_argument("Несоответствие размеров матрицы");
  else
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++) matrix_[i][j] += other.matrix_[i][j];
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ ||
      cols_ != other.cols_)  //Несоответствие размеров матрицы
    throw std::invalid_argument("Несоответствие размеров матрицы");
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] -= other.matrix_[i][j];
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] *= num;
}

void S21Matrix::print() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << matrix_[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix res(*this);
  res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix res(*this);
  res.SubMatrix(other);
  return res;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

void S21Matrix::operator=(const S21Matrix& other) {
  this->~S21Matrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double*[other.rows_]();
  for (int i = 0; i < rows_; i++) matrix_[i] = new double[other.cols_]();
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = other.matrix_[i][j];
}

double& S21Matrix::operator()(int i, int j) {
  if (i >= rows_ || j >= cols_ || i < 0 || j < 0)
    throw std::out_of_range("Incorrect input, index is out of range");
  return matrix_[i][j];
}

void S21Matrix::operator+=(const S21Matrix& other) { SumMatrix(other); }
void S21Matrix::operator-=(const S21Matrix& other) { SubMatrix(other); }

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::invalid_argument(
        "число столбцов первой матрицы не равно числу строк второй матрицы");
  S21Matrix res = S21Matrix(rows_, other.cols_);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < other.cols_; j++)
      // i,j элемент = суммпроизв i-ую строку this на j-й столбец other.
      for (int k = 0; k < cols_; k++)
        res.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
  *this = res;
}

void S21Matrix::operator*=(const S21Matrix& other) { MulMatrix(other); }

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix res = S21Matrix(cols_, rows_);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) res.matrix_[j][i] = matrix_[i][j];
  return res;
}

void S21Matrix::remove_row_and_culumn(int row, int column, S21Matrix& res) {
  for (int i = 0; i < res.rows_; i++)
    for (int j = 0; j < res.cols_; j++)
      res.matrix_[i][j] =
          matrix_[i >= row ? i + 1 : i][j >= column ? j + 1 : j];
}

double S21Matrix::Determinant() {
  double res = 0;
  if (cols_ != rows_)
    throw std::invalid_argument("Матрица не является квадратной");
  else if (rows_ == 1)
    res = matrix_[0][0];
  else {
    double sum = 0;
    for (int i = 0; i < cols_;
         i++) {  //Сумма произведений значений строки (берём первую) на
                 //алгеброические дополнения
      //Удаляем 0 строку и i-й столбец
      S21Matrix smaller(rows_ - 1, cols_ - 1);
      remove_row_and_culumn(0, i, smaller);
      sum += (i % 2 ? -1 : 1) * smaller.Determinant() * matrix_[0][i];
    }
    res = sum;
  }
  return res;
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_)
    throw std::invalid_argument("Матрица не является квадратной");
  S21Matrix res = S21Matrix(rows_, cols_);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) {
      S21Matrix smaller(rows_ - 1, cols_ - 1);
      remove_row_and_culumn(i, j, smaller);
      res.matrix_[i][j] = ((i + j) % 2 ? -1 : 1) * smaller.Determinant();
    }
  return res;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (det == 0)  //Отделяeм этот случай, так как нельзя посчитать
    throw std::invalid_argument("Определитель матрицы равен 0");
  S21Matrix res = S21Matrix(rows_, cols_);
  if (rows_ == 1)
    res.matrix_[0][0] = 1. / matrix_[0][0];
  else {
    res = CalcComplements().Transpose();
    res.MulNumber(1 / det);
  }
  return res;
}