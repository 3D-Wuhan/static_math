/*
 * Copyright (C) 2011-2012 Morwenn
 *
 * static_math is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * static_math is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _SMATH_RATIONAL_H
#define _SMATH_RATIONAL_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <static_math/utils/type_traits.h>
#include <static_math/cmath.h>


namespace smath
{

    /**
     * @brief Rational numbers
     */
    template<typename T>
    class rational
    {
        static_assert(std::is_integral<T>::value, "A rational can only contain integral values.");

        public:

            constexpr rational(T numerator, T denominator=1);

            constexpr T numerator() const;
            constexpr T denominator() const;

            constexpr operator long double() const;

        private:

            T _numerator;
            T _denominator;
    };

    ////////////////////////////////////////////////////////////
    // Operators
    ////////////////////////////////////////////////////////////

    template<typename T>
    constexpr rational<T> operator+(const rational<T>& lhs);
    template<typename T>
    constexpr rational<T> operator-(const rational<T>& lhs);

    template<typename T, typename U>
    constexpr bool operator==(const rational<T>& lhs, const rational<U>& rhs);
    template<typename T, typename U>
    constexpr bool operator!=(const rational<T>& lhs, const rational<U>& rhs);
    template<typename T, typename U>
    constexpr bool operator<(const rational<T>& lhs, const rational<U>& rhs);
    template<typename T, typename U>
    constexpr bool operator>(const rational<T>& lhs, const rational<U>& rhs);
    template<typename T, typename U>
    constexpr bool operator<=(const rational<T>& lhs, const rational<U>& rhs);
    template<typename T, typename U>
    constexpr bool operator>=(const rational<T>& lhs, const rational<U>& rhs);

    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, bool>::type
    operator==(const rational<T>& lhs, const U& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, bool>::type
    operator!=(const rational<T>& lhs, const U& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, bool>::type
    operator<(const rational<T>& lhs, const U& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, bool>::type
    operator>(const rational<T>& lhs, const U& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, bool>::type
    operator<=(const rational<T>& lhs, const U& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, bool>::type
    operator>=(const rational<T>& lhs, const U& rhs);

    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, bool>::type
    operator==(const U& lhs, const rational<T>& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, bool>::type
    operator!=(const U& lhs, const rational<T>& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, bool>::type
    operator<(const U& lhs, const rational<T>& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, bool>::type
    operator>(const U& lhs, const rational<T>& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, bool>::type
    operator<=(const U& lhs, const rational<T>& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, bool>::type
    operator>=(const U& lhs, const rational<T>& rhs);

    template<typename T, typename U>
    constexpr
    rational<typename greater_of<T, U>::type>
    operator+(const rational<T>& lhs, const rational<U>& rhs);
    template<typename T, typename U>
    constexpr
    rational<typename greater_of<T, U>::type>
    operator-(const rational<T>& lhs, const rational<U>& rhs);
    template<typename T, typename U>
    constexpr
    rational<typename greater_of<T, U>::type>
    operator*(const rational<T>& lhs, const rational<U>& rhs);
    template<typename T, typename U>
    constexpr
    rational<typename greater_of<T, U>::type>
    operator/(const rational<T>& lhs, const rational<U>& rhs);

    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
    operator+(const rational<T>& lhs, const U& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
    operator-(const rational<T>& lhs, const U& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
    operator*(const rational<T>& lhs, const U& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
    operator/(const rational<T>& lhs, const U& rhs);

    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
    operator+(const U& lhs, const rational<T> rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
    operator-(const U& lhs, const rational<T> rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
    operator*(const U& lhs, const rational<T> rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
    operator/(const U& lhs, const rational<T> rhs);

    ////////////////////////////////////////////////////////////
    // Mathematical functions
    ////////////////////////////////////////////////////////////

    template<typename T>
    constexpr rational<T> abs(const rational<T>& ratio);

    #include <static_math/rational.inl>

} // namespace smath

constexpr smath::rational<unsigned long long>
operator "" _static_r(unsigned long long n)
{
    return smath::rational<unsigned long long>(n);
}


#endif // _SMATH_RATIONAL_H
