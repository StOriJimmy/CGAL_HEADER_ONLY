// Copyright (c) 2015 GeometryFactory (France), All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 3 of the License,
// or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
// Author(s)     : Simon Giraudot

#ifndef CGAL_DEFAULT_DIAGONALIZE_TRAITS_H
#define CGAL_DEFAULT_DIAGONALIZE_TRAITS_H

#ifdef CGAL_EIGEN3_ENABLED
#include <CGAL/Eigen_diagonalize_traits.h>
#else
#include <CGAL/Diagonalize_traits.h>
#endif


namespace CGAL {


  // Wrapper class designed to automatically use
  // Eigen_diagonalize_traits if Eigen is available and otherwise use
  // the fallback Diagonalize_traits class.
  
template <typename FT, unsigned int dim = 3>
class Default_diagonalize_traits{

#ifdef CGAL_EIGEN3_ENABLED
  typedef Eigen_diagonalize_traits<FT, dim> Base;
#else
  typedef Diagonalize_traits<FT, dim> Base;
#endif

public:

  typedef cpp11::array<FT, dim> Vector;
  typedef cpp11::array<FT, dim*dim> Matrix;
  typedef cpp11::array<FT, (dim * (dim+1) / 2)> Covariance_matrix;
  
  static bool
  diagonalize_selfadjoint_covariance_matrix(
    const Covariance_matrix& cov,
    Vector& eigenvalues)
  {
    return Base::diagonalize_selfadjoint_covariance_matrix (cov, eigenvalues);
  }

  static bool
  diagonalize_selfadjoint_covariance_matrix(
    const Covariance_matrix& cov,
    Vector& eigenvalues,
    Matrix& eigenvectors)
  {
    return Base::diagonalize_selfadjoint_covariance_matrix (cov, eigenvalues, eigenvectors);
  }

  // Extract the eigenvector associated to the largest eigenvalue
  static bool
  extract_largest_eigenvector_of_covariance_matrix (
    const Covariance_matrix& cov,
    Vector& normal)
  {
    return Base::extract_largest_eigenvector_of_covariance_matrix (cov, normal);
  }
};


} // namespace CGAL

#endif // CGAL_DEFAULT_DIAGONALIZE_TRAITS_H
