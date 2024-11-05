
#ifndef SET_7_COL_FACT_H
#define SET_7_COL_FACT_H

#include "checking_policy.h"

template<typename Checking_policy = Std_exception_on_error_policy>
class ColorFactory {
public:
    Color returnColor(const std::string& color) {
        if (color == "green" || color == "zielony") {
            return Checking_policy::perform();
        } else {
           return Checking_policy::perform();
        }
    }
};

#endif //SET_7_COL_FACT_H
