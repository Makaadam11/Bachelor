//
// Created by Mikołaj on 24/05/2022.
// https://wazniak.mimuw.edu.pl/index.php?title=Zaawansowane_CPP/Wyk%C5%82ad_9:_Szablony_wyra%C5%BCe%C5%84
// https://onedrive.live.com/view.aspx?cid=2301eb34d0eafe6b&page=view&resid=2301EB34D0EAFE6B!4272&parId=2301EB34D0EAFE6B!1993&authkey=!AClQInI_iOdOmN8&app=Word
//

#include <iostream>
#include "functors.h"

int main2() {

    Variable x;
    std::cout << integrate(x,0,1,0.001) << std::endl;
    std::cout << integrate(Constant(1.0),0,1,0.001) << std::endl;

    return 0;
}
