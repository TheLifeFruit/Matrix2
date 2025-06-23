#include <iostream>
#include <vector>

std::vector<std::vector<int>> a;
std::vector<std::vector<int>> b;
std::vector<std::vector<int>> c;

/*void drawmatrixequation(std::vector<std::vector<int>> v1,std::vector<std::vector<int>> v2) {
    std::string row = "";
    int cols1;
    if ((v1.empty()))
        cols1 = 0;
    else
        cols1 = v1[0].size();


    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < cols1; j++) {
            row  = row + "|" + std::to_string(v1.at(i).at(j)) + "|";
        }
        if (i != v1.size() - 1) {
            row = row + " ";
        }else {
           row = row + "x";
        }

        for (int j = 0; j < cols2; j++) {
            row  = row + "|" + std::to_string(v2.at(i).at(j)) + "|";
        }

        std::cout << row <<std::endl;
        row = "";
    }
}*/


int getElement(const std::vector<std::vector<int>>& v, size_t row, size_t col) {
    if (row < v.size() && col < v[row].size()) {
        return v[row][col];
    } else {
        return 0; // Gibt 0 zurück, falls das Element nicht existiert
    }
}

void drawmatrix(std::vector<std::vector<int>> v, int h, int w) {
    int cols;
    if ((v.empty()))
        cols = 0;
    else
        cols = v[0].size();

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < cols; j++) {
            if (i == h && w == j) {
                std::cout << "|X";
            }else {
                std::cout << "|" << v.at(i).at(j);
            }

        }
        std::cout << "|" << std::endl ;
    }
}

std::vector<std::vector<int>> setmatrixelement(std::vector<std::vector<int>> v, int value, int h, int w) {
    v[h][w] = value;
    return v;
}

std::vector<std::vector<int>> userfillvector(std::vector<std::vector<int>> v, int height, int width) {
    std::string input = "";
    int value = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            drawmatrix(v, i, j);
            std::cout << "Input value: " <<std::endl;
            std::cin >> input;
            /*try {
                int number = std::stoi(input);
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input" << std::endl;
                return v;
            } catch (const std::out_of_range& e)
            {
                std::cout << "Invalid input" << std::endl;
                return v;
            }*/

            value = std::stoi(input);
            v = setmatrixelement(v, value, i, j);

        }
    }
    return v;



}


std::vector<std::vector<int>> fillnullmatrix(std::vector<std::vector<int>> v, int height, int width) {
    // push size times rows of 0s
    for (int i = 0; i < height; i++) {
            v.push_back(std::vector<int>(width, 0));
    }

    return v;
}

std::vector<std::vector<int>> MatrixMultiplication(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b, int a_h, int a_w, int b_w) {


    if (a[0].size() != b.size()) {
        std::cout << "Error: Dimension of a x b does not allow Matrix Multiplication! A Spalten: " << a[0].size()  << ", B Reihen: " << b.size();
        exit(0);
    }

    for (int i = 0; i < a_h; i++) {
        for (int j = 0; j < b_w; j++) {
            for (int h = 0; h < a_w; h++) {
                c[i][j] = getElement(c, i, j) + getElement(a, i, h) * getElement(b, h, j);
            }
        }
    }
    return c;

}

int main() {

    int a_h = 3;
    int a_w = 3;
    int b_h = 3;
    int b_w = 3;



    std::cout << "Matrix Multiplaction: A x B" << std::endl;
    std::cout << "Input Matrix A's height (rows): " << std::endl;
    std::cin >> a_h;
    std::cout << "Input Matrix A's width (columns): " << std::endl;
    std::cin >> a_w;
    std::cout << "Matrix B's height (rows) set to = " << a_w<< std::endl;
    b_h = a_w;
    std::cout << "Input Matrix B's width (columns): " << std::endl;
    std::cin >> b_w;



    a = fillnullmatrix(a, a_h, a_w);
    b = fillnullmatrix(b, b_h, b_w);
    c = fillnullmatrix(c, a_h,b_w);

    a = userfillvector(a,  a_h, a_w);
    b = userfillvector(b,  b_h, b_w);


    drawmatrix(a, -1, -1);
    std::cout << "x" << std::endl;
    drawmatrix(b, -1, -1);
    std::cout << "=" << std::endl;

    c = MatrixMultiplication(a, b, a_h, a_w, b_w);
    drawmatrix(c, -1, -1);

    return 0;
}