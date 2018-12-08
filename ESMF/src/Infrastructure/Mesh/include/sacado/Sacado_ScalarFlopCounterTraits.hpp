// $Id: Sacado_ScalarFlopCounterTraits.hpp,v 1.1.5.1 2013-01-11 20:23:44 mathomp4 Exp $ 
// $Source: /cvsroot/baselibs/Baselibs/src/esmf/src/Infrastructure/Mesh/include/sacado/Sacado_ScalarFlopCounterTraits.hpp,v $ 
// @HEADER
// ***********************************************************************
// 
//                           Sacado Package
//                 Copyright (2006) Sandia Corporation
// 
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
// 
// This library is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2.1 of the
// License, or (at your option) any later version.
//  
// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//  
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA
// Questions? Contact David M. Gay (dmgay@sandia.gov) or Eric T. Phipps
// (etphipp@sandia.gov).
// 
// ***********************************************************************
//
// The forward-mode AD classes in Sacado are a derivative work of the
// expression template classes in the Fad package by Nicolas Di Cesare.  
// The following banner is included in the original Fad source code:
//
// ************ DO NOT REMOVE THIS BANNER ****************
//
//  Nicolas Di Cesare <Nicolas.Dicesare@ann.jussieu.fr>
//  http://www.ann.jussieu.fr/~dicesare
//
//            CEMRACS 98 : C++ courses, 
//         templates : new C++ techniques 
//            for scientific computing 
// 
//********************************************************
//
//  NumericalTraits class to illustrate TRAITS
//
//********************************************************
// @HEADER

#ifndef SACADO_SCALARFLOPCOUNTERTRAITS_HPP
#define SACADO_SCALARFLOPCOUNTERTRAITS_HPP

#include "Sacado_Traits.hpp"

// Forward declarations
namespace Sacado {
  namespace FlopCounterPack {
    template <typename T> class ScalarFlopCounter;
  }
}

namespace Sacado {

  //! Specialization of %Promote to ScalarFlopCounter types
  template <typename ScalarT>
  struct Promote< FlopCounterPack::ScalarFlopCounter<ScalarT>, 
		  FlopCounterPack::ScalarFlopCounter<ScalarT> > {
    typedef FlopCounterPack::ScalarFlopCounter<ScalarT> type;
  };

  //! Specialization of %Promote to ScalarFlopCounter types
  template <typename ScalarT, typename R>
  struct Promote< FlopCounterPack::ScalarFlopCounter<ScalarT>, R > {
    typedef typename ValueType< FlopCounterPack::ScalarFlopCounter<ScalarT> >::type value_type_l;
    typedef typename ValueType<R>::type value_type_r;
    typedef typename Promote<value_type_l,value_type_r>::type value_type;

    typedef FlopCounterPack::ScalarFlopCounter<value_type> type;
  };

  //! Specialization of %Promote to ScalarFlopCounter types
  template <typename L, typename ScalarT>
  struct Promote< L, FlopCounterPack::ScalarFlopCounter<ScalarT> > {
  public:

    typedef typename ValueType<L>::type value_type_l;
    typedef typename ValueType< FlopCounterPack::ScalarFlopCounter<ScalarT> >::type value_type_r;
    typedef typename Promote<value_type_l,value_type_r>::type value_type;

    typedef FlopCounterPack::ScalarFlopCounter<value_type> type;
  };

  //! Specialization of %ScalarType to ScalarFlopCounter types
  template <typename ScalarT>
  struct ScalarType< FlopCounterPack::ScalarFlopCounter<ScalarT> > {
    typedef ScalarT type;
  };

  //! Specialization of %ValueType to ScalarFlopCounter types
  template <typename ScalarT>
  struct ValueType< FlopCounterPack::ScalarFlopCounter<ScalarT> > {
    typedef ScalarT type;
  };

   //! Specialization of %ScalarValueType to ScalarFlopCounter types
  template <typename ScalarT>
  struct ScalarValueType< FlopCounterPack::ScalarFlopCounter<ScalarT> > {
    typedef typename ScalarValueType<ScalarT>::type type;
  };

  //! Specialization of %IsADType to ScalarFlopCounter types
  template <typename ScalarT>
  struct IsADType< FlopCounterPack::ScalarFlopCounter<ScalarT> > {
    static const bool value = true;
  };

  //! Specialization of %IsADType to ScalarFlopCounter types
  template <typename ScalarT>
  struct IsScalarType< FlopCounterPack::ScalarFlopCounter<ScalarT> > {
    static const bool value = false;
  };

  //! Specialization of %Value to ScalarFlopCounter types
  template <typename ScalarT>
  struct Value< FlopCounterPack::ScalarFlopCounter<ScalarT> > {
    typedef typename ValueType< FlopCounterPack::ScalarFlopCounter<ScalarT> >::type value_type;
    static const value_type& eval(const FlopCounterPack::ScalarFlopCounter<ScalarT>& x) { 
      return x.val(); }
  };

} // namespace Sacado

#endif // SACADO_SCALARFLOPCOUNTERTRAITS_HPP
