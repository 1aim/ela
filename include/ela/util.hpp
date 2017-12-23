// Copyright (c) 2017 1aim GmbH
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do
// so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _ELA_UTIL_H
#define _ELA_UTIL_H

#include <iostream>
#include <ela/ela.hpp>

template <typename Expr>
typename std::enable_if<ela::is_expr<Expr>::value, std::ostream>::type&
operator << (std::ostream& out, Expr const& me) {
	for (size_t row = 0; row < ela::expression::traits<Expr>::rows; row++) {
		for (size_t column = 0; column < ela::expression::traits<Expr>::columns; column++) {
			out << me(row, column);

			if (column + 1 != ela::expression::traits<Expr>::columns) {
				out << "\t";
			}
		}

		if (row + 1 != ela::expression::traits<Expr>::rows) {
			out << std::endl;
		}
	}

	return out;
}

#endif
