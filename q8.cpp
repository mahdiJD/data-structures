#include <iostream>
#include <vector>

using namespace std;

// ساختار برای نمایش یک عنصر ماتریس اسپارس
struct SparseElement {
    int value;
    int row;
    int col;
};

// تابع برای جمع دو ماتریس اسپارس
vector<SparseElement> addSparseMatrices(const vector<SparseElement>& mat1, const vector<SparseElement>& mat2, int rows, int cols) {
    vector<SparseElement> result;

    int i = 0, j = 0;
    while (i < mat1.size() && j < mat2.size()) {
        if (mat1[i].row == mat2[j].row && mat1[i].col == mat2[j].col) {
            // اگر عنصر در همان موقعیت باشد، جمع مقادیر
            int sum = mat1[i].value + mat2[j].value;
            if (sum != 0) { // فقط عناصر غیر صفر را ذخیره کن
                result.push_back({sum, mat1[i].row, mat1[i].col});
            }
            i++;
            j++;
        } else if (mat1[i].row < mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            // اضافه کردن عناصر ماتریس اول که جلوتر است
            result.push_back(mat1[i]);
            i++;
        } else {
            // اضافه کردن عناصر ماتریس دوم که جلوتر است
            result.push_back(mat2[j]);
            j++;
        }
    }

    // اضافه کردن باقی‌مانده عناصر ماتریس‌ها
    while (i < mat1.size()) {
        result.push_back(mat1[i]);
        i++;
    }

    while (j < mat2.size()) {
        result.push_back(mat2[j]);
        j++;
    }

    return result;
}

int main() {
    // اطلاعات ماتریس اول
    int rows1, cols1, nonZero1;
    cout << "Enter rows, cols, and non-zero elements for matrix 1: ";
    cin >> rows1 >> cols1 >> nonZero1;

    vector<SparseElement> mat1(nonZero1);
    cout << "Enter non-zero elements (value, row, col):\n";
    for (int i = 0; i < nonZero1; i++) {
        cin >> mat1[i].value >> mat1[i].row >> mat1[i].col;
    }

    // اطلاعات ماتریس دوم
    int rows2, cols2, nonZero2;
    cout << "Enter rows, cols, and non-zero elements for matrix 2: ";
    cin >> rows2 >> cols2 >> nonZero2;

    vector<SparseElement> mat2(nonZero2);
    cout << "Enter non-zero elements (value, row, col):\n";
    for (int i = 0; i < nonZero2; i++) {
        cin >> mat2[i].value >> mat2[i].row >> mat2[i].col;
    }

    // بررسی ابعاد ماتریس‌ها
    if (rows1 != rows2 || cols1 != cols2) {
        cout << "Error: Matrices dimensions do not match for addition.\n";
        return 1;
    }

    // جمع دو ماتریس
    vector<SparseElement> result = addSparseMatrices(mat1, mat2, rows1, cols1);

    // چاپ نتیجه
    cout << rows1 << " " << cols1 << " " << result.size() << "\n";
    for (const auto& elem : result) {
        cout << elem.value << " " << elem.row << " " << elem.col << "\n";
    }

    return 0;
}
