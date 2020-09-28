/*! \file gauss_legendre_integ_main.cpp
    \brief Gauss-Legendre積分法により、関数を数値積分する
    Copyright © 2020 @dc1394 All Rights Reserved.

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your option)
    any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
    more details.

    You should have received a copy of the GNU General Public License along
    with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "gausslegendre/gausslegendre.h"
#include "myfunctional/functional.h"
#include <cmath>                    // for std::sqrt
#include <chrono>                   // for std::chrono
#include <iomanip>					// for std::setiosflags, std::setprecision
#include <iostream>                 // for std::cerr, std::cout

static auto constexpr INTEGTABLENUM = 10000;

int main()
{
    using namespace std::chrono;
    auto const start = system_clock::now();

    auto const func = myfunctional::make_functional([](double x) { return 0.5 * (1.0 / std::sqrt(x)); });
    gausslegendre::Gauss_Legendre gl(INTEGTABLENUM);
    auto const result = gl.qgauss(func, 1.0, 4.0); 

    auto const end = system_clock::now();

	std::cout << std::setiosflags(std::ios::fixed);
	std::cout << std::setprecision(14);
    std::cout << "積分結果 = " << result << "\n";
    std::cout << std::setprecision(6);
    std::cout << "計算時間 = " << duration_cast< duration<double> >(end - start).count() << "（秒）" << std::endl;
}
