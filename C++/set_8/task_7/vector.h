//
// Created by Mikołaj on 24/05/2022.
// https://wazniak.mimuw.edu.pl/index.php?title=Zaawansowane_CPP/Wyk%C5%82ad_9:_Szablony_wyra%C5%BCe%C5%84
// https://onedrive.live.com/view.aspx?cid=2301eb34d0eafe6b&page=view&resid=2301EB34D0EAFE6B!4272&parId=2301EB34D0EAFE6B!1993&authkey=!AClQInI_iOdOmN8&app=Word
//

#ifndef _vector_
#define _vector_

#include <utility>
#include <vector>
#include <iostream>

template<typename T>
class Vector {
    std::vector<T> values;

    explicit Vector(std::vector<T> elems) {
        values = std::move(elems);
    }
public:
    explicit Vector(int len, T value) {
        for (int i = 0; i < len; ++i) {
            values.push_back(value);
        }
    };

    Vector operator+(const Vector& second) const {
        std::vector<T> newVector;
        for (int i = 0; i < second.values.size(); ++i) {
            newVector.push_back(values[i] + second.values[i]);
        }
        return Vector(newVector);
    }

    Vector operator*(const Vector& second) const {
        std::vector<T> newVector;
        for (int i = 0; i < second.values.size(); ++i) {
            newVector.push_back(values[i] * second.values[i]);
        }
        return Vector(newVector);
    }

    Vector operator*(double val) const {
        std::vector<T> newVector;
        for (T value : values) {
            newVector.push_back(double (value * val));
        }
        return Vector(newVector);
    }

    void print() {
        for (T value : values) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
};

#endif
