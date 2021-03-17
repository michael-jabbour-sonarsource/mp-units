// The MIT License (MIT)
//
// Copyright (c) 2018 Mateusz Pusz
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
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

#pragma once

#include <units/isq/dimensions/energy.h>
#include <units/isq/si/fps/force.h>
#include <units/isq/si/prefixes.h>
#include <units/quantity.h>

namespace units::isq::si::fps {

// https://en.wikipedia.org/wiki/Foot-poundal
struct foot_poundal : unit<foot_poundal> {};

struct dim_energy : isq::dim_energy<dim_energy, foot_poundal, dim_force, dim_length> {};

// https://en.wikipedia.org/wiki/Foot-pound_(energy)
struct foot_pound_force : noble_deduced_unit<foot_pound_force, dim_energy, pound_force, foot> {};



template<UnitOf<dim_energy> U, QuantityValue Rep = double>
using energy = quantity<dim_energy, U, Rep>;


inline namespace literals {

// foot poundal
constexpr auto operator"" _q_ft_pdl(unsigned long long l) { gsl_ExpectsAudit(std::in_range<std::int64_t>(l)); return energy<foot_poundal, std::int64_t>(static_cast<std::int64_t>(l)); }
constexpr auto operator"" _q_ft_pdl(long double l) { return energy<foot_poundal, long double>(l); }

// foot_pound force
constexpr auto operator"" _q_ft_lbf(unsigned long long l) { gsl_ExpectsAudit(std::in_range<std::int64_t>(l)); return energy<foot_pound_force, std::int64_t>(static_cast<std::int64_t>(l)); }
constexpr auto operator"" _q_ft_lbf(long double l) { return energy<foot_pound_force, long double>(l); }

}  // namespace literals

namespace unit_constants {

inline constexpr auto ft_pdl = reference<dim_energy, foot_poundal>{};
inline constexpr auto ft_lbf = reference<dim_energy, foot_pound_force>{};

}  // namespace unit_constants

}  // namespace units::isq::si::fps
