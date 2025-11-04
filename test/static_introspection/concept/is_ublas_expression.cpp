// Copyright (C) 2025 Cromwell D. Enage

#include <complex>
#include <boost/numeric/ublas/vector_expression.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/numeric/ublas/hermitian.hpp>
#include <boost/numeric/ublas/banded.hpp>
#include <boost/mpl/bool.hpp>
#include <odds_and_ends/static_introspection/concept/is_ublas_vector_minimal_expression.hpp>

void test_ublas_vector_minimal_expression()
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::vector<double>
        >::value,
        "::boost::numeric::ublas::vector is a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::mapped_vector<double>
        >::value,
        "::boost::numeric::ublas::mapped_vector is a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::compressed_vector<double>
        >::value,
        "::boost::numeric::ublas::compressed_vector is a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::coordinate_vector<double>
        >::value,
        "::boost::numeric::ublas::coordinate_vector is a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::unit_vector<>
        >::value,
        "::boost::numeric::ublas::unit_vector is a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::zero_vector<>
        >::value,
        "::boost::numeric::ublas::zero_vector is a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::scalar_vector<>
        >::value,
        "::boost::numeric::ublas::scalar_vector is a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::matrix<double>
        >::value,
        "::boost::numeric::ublas::matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::mapped_matrix<double>
        >::value,
        "::boost::numeric::ublas::mapped_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas
            ::triangular_matrix<double,::boost::numeric::ublas::strict_lower>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::unit_lower>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas
            ::triangular_matrix<double,::boost::numeric::ublas::strict_upper>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::unit_upper>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::symmetric_matrix<double,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::symmetric_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::symmetric_matrix<double,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::symmetric_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas
            ::hermitian_matrix< ::std::complex<double>,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::symmetric_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas
            ::hermitian_matrix< ::std::complex<double>,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::hermitian_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::banded_matrix<double>
        >::value,
        "::boost::numeric::ublas::banded_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas
            ::banded_adaptor< ::boost::numeric::ublas::matrix<double> >
        >::value,
        "::boost::numeric::ublas::banded_adaptor is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::scalar_matrix<>
        >::value,
        "::boost::numeric::ublas::scalar_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::identity_matrix<>
        >::value,
        "::boost::numeric::ublas::identity_matrix is not a Boost uBlas Vector Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_minimal_expression<
            ::boost::numeric::ublas::zero_matrix<>
        >::value,
        "::boost::numeric::ublas::zero_matrix is not a Boost uBlas Vector Minimal Expression."
    );
}

#include <odds_and_ends/static_introspection/concept/is_ublas_vector_expression.hpp>

void test_ublas_vector_expression()
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::vector<double>
        >::value,
        "::boost::numeric::ublas::vector is a Boost uBlas Vector Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::mapped_vector<double>
        >::value,
        "::boost::numeric::ublas::mapped_vector is a Boost uBlas Vector Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::compressed_vector<double>
        >::value,
        "::boost::numeric::ublas::compressed_vector is a Boost uBlas Vector Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::coordinate_vector<double>
        >::value,
        "::boost::numeric::ublas::coordinate_vector is a Boost uBlas Vector Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::nested_type::has_reverse_iterator<
            ::boost::numeric::ublas::unit_vector<>
        >::value,
        "::boost::numeric::ublas::unit_vector has a reverse_iterator."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::unit_vector<>
        >::value,
        "::boost::numeric::ublas::unit_vector is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::zero_vector<>
        >::value,
        "::boost::numeric::ublas::zero_vector is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::scalar_vector<>
        >::value,
        "::boost::numeric::ublas::scalar_vector is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::matrix<double>
        >::value,
        "::boost::numeric::ublas::matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::mapped_matrix<double>
        >::value,
        "::boost::numeric::ublas::mapped_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::triangular_matrix<
                double,
                ::boost::numeric::ublas::strict_lower
            >
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::unit_lower>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::triangular_matrix<
                double,
                ::boost::numeric::ublas::strict_upper
            >
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::unit_upper>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::symmetric_matrix<double,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::symmetric_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::symmetric_matrix<double,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::symmetric_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas
            ::hermitian_matrix< ::std::complex<double>,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::hermitian_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas
            ::hermitian_matrix< ::std::complex<double>,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::hermitian_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::banded_matrix<double>
        >::value,
        "::boost::numeric::ublas::banded_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas
            ::banded_adaptor< ::boost::numeric::ublas::matrix<double> >
        >::value,
        "::boost::numeric::ublas::banded_adaptor is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::scalar_matrix<>
        >::value,
        "::boost::numeric::ublas::scalar_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::identity_matrix<>
        >::value,
        "::boost::numeric::ublas::identity_matrix is not a Boost uBlas Vector Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector_expression<
            ::boost::numeric::ublas::zero_matrix<>
        >::value,
        "::boost::numeric::ublas::zero_matrix is not a Boost uBlas Vector Expression."
    );
}

#include <odds_and_ends/static_introspection/concept/is_ublas_vector.hpp>

void test_ublas_vector()
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::vector<double>
        >::value,
        "::boost::numeric::ublas::vector is a Boost uBlas Vector."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::mapped_vector<double>
        >::value,
        "::boost::numeric::ublas::mapped_vector is a Boost uBlas Vector."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::compressed_vector<double>
        >::value,
        "::boost::numeric::ublas::compressed_vector is a Boost uBlas Vector."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::coordinate_vector<double>
        >::value,
        "::boost::numeric::ublas::coordinate_vector is a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::unit_vector<>
        >::value,
        "::boost::numeric::ublas::unit_vector is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::zero_vector<>
        >::value,
        "::boost::numeric::ublas::zero_vector is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::scalar_vector<>
        >::value,
        "::boost::numeric::ublas::scalar_vector is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::matrix<double>
        >::value,
        "::boost::numeric::ublas::matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::mapped_matrix<double>
        >::value,
        "::boost::numeric::ublas::mapped_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::triangular_matrix<
                double,
                ::boost::numeric::ublas::strict_lower
            >
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::unit_lower>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::triangular_matrix<
                double,
                ::boost::numeric::ublas::strict_upper
            >
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::unit_upper>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::symmetric_matrix<double,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::symmetric_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::symmetric_matrix<double,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::symmetric_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas
            ::hermitian_matrix< ::std::complex<double>,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::hermitian_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas
            ::hermitian_matrix< ::std::complex<double>,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::hermitian_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::banded_matrix<double>
        >::value,
        "::boost::numeric::ublas::banded_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas
            ::banded_adaptor< ::boost::numeric::ublas::matrix<double> >
        >::value,
        "::boost::numeric::ublas::banded_adaptor is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::scalar_matrix<>
        >::value,
        "::boost::numeric::ublas::scalar_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::identity_matrix<>
        >::value,
        "::boost::numeric::ublas::identity_matrix is not a Boost uBlas Vector."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_vector<
            ::boost::numeric::ublas::zero_matrix<>
        >::value,
        "::boost::numeric::ublas::zero_matrix is not a Boost uBlas Vector."
    );
}

#include <odds_and_ends/static_introspection/concept/is_ublas_matrix_minimal_expression.hpp>

void test_ublas_matrix_minimal_expression()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::vector<double>
        >::value,
        "::boost::numeric::ublas::vector is not a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::mapped_vector<double>
        >::value,
        "::boost::numeric::ublas::mapped_vector is not a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::compressed_vector<double>
        >::value,
        "::boost::numeric::ublas::compressed_vector is not a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::coordinate_vector<double>
        >::value,
        "::boost::numeric::ublas::coordinate_vector is not a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::unit_vector<>
        >::value,
        "::boost::numeric::ublas::unit_vector is not a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::zero_vector<>
        >::value,
        "::boost::numeric::ublas::zero_vector is not a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::scalar_vector<>
        >::value,
        "::boost::numeric::ublas::scalar_vector is not a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::matrix<double>
        >::value,
        "::boost::numeric::ublas::matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::mapped_matrix<double>
        >::value,
        "::boost::numeric::ublas::mapped_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas
            ::triangular_matrix<double,::boost::numeric::ublas::strict_lower>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::unit_lower>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas
            ::triangular_matrix<double,::boost::numeric::ublas::strict_upper>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::unit_upper>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::symmetric_matrix<double,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::symmetric_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::symmetric_matrix<double,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::symmetric_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas
            ::hermitian_matrix< ::std::complex<double>,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::hermitian_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas
            ::hermitian_matrix< ::std::complex<double>,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::hermitian_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::banded_matrix<double>
        >::value,
        "::boost::numeric::ublas::banded_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas
            ::banded_adaptor< ::boost::numeric::ublas::matrix<double> >
        >::value,
        "::boost::numeric::ublas::banded_adaptor is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::scalar_matrix<>
        >::value,
        "::boost::numeric::ublas::scalar_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::identity_matrix<>
        >::value,
        "::boost::numeric::ublas::identity_matrix is a Boost uBlas Matrix Minimal Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_minimal_expression<
            ::boost::numeric::ublas::zero_matrix<>
        >::value,
        "::boost::numeric::ublas::zero_matrix is a Boost uBlas Matrix Minimal Expression."
    );
}

#include <odds_and_ends/static_introspection/concept/is_ublas_matrix_expression.hpp>

void test_ublas_matrix_expression()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::vector<double>
        >::value,
        "::boost::numeric::ublas::vector is not a Boost uBlas Matrix Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::mapped_vector<double>
        >::value,
        "::boost::numeric::ublas::mapped_vector is not a Boost uBlas Matrix Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::compressed_vector<double>
        >::value,
        "::boost::numeric::ublas::compressed_vector is not a Boost uBlas Matrix Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::coordinate_vector<double>
        >::value,
        "::boost::numeric::ublas::coordinate_vector is not a Boost uBlas Matrix Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::unit_vector<>
        >::value,
        "::boost::numeric::ublas::unit_vector is not a Boost uBlas Matrix Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::zero_vector<>
        >::value,
        "::boost::numeric::ublas::zero_vector is not a Boost uBlas Matrix Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::scalar_vector<>
        >::value,
        "::boost::numeric::ublas::scalar_vector is not a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::matrix<double>
        >::value,
        "::boost::numeric::ublas::matrix is a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::mapped_matrix<double>
        >::value,
        "::boost::numeric::ublas::mapped_matrix is a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas
            ::triangular_matrix<double,::boost::numeric::ublas::strict_lower>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::unit_lower>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas
            ::triangular_matrix<double,::boost::numeric::ublas::strict_upper>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::unit_upper>
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::symmetric_matrix<double,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::symmetric_matrix is a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::symmetric_matrix<double,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::symmetric_matrix is a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas
            ::hermitian_matrix< ::std::complex<double>,::boost::numeric::ublas::lower>
        >::value,
        "::boost::numeric::ublas::hermitian_matrix is a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas
            ::hermitian_matrix< ::std::complex<double>,::boost::numeric::ublas::upper>
        >::value,
        "::boost::numeric::ublas::hermitian_matrix is a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::banded_matrix<double>
        >::value,
        "::boost::numeric::ublas::banded_matrix is a Boost uBlas Matrix Expression."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas
            ::banded_adaptor< ::boost::numeric::ublas::matrix<double> >
        >::value,
        "::boost::numeric::ublas::banded_adaptor is a Boost uBlas Matrix Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::scalar_matrix<>
        >::value,
        "::boost::numeric::ublas::scalar_matrix is not a Boost uBlas Matrix Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::identity_matrix<>
        >::value,
        "::boost::numeric::ublas::identity_matrix is not a Boost uBlas Matrix Expression."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix_expression<
            ::boost::numeric::ublas::zero_matrix<>
        >::value,
        "::boost::numeric::ublas::zero_matrix is not a Boost uBlas Matrix Expression."
    );
}

#include <odds_and_ends/static_introspection/concept/is_ublas_matrix.hpp>

void test_ublas_matrix()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::vector<double>
        >::value,
        "::boost::numeric::ublas::vector is not a Boost uBlas Matrix."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::mapped_vector<double>
        >::value,
        "::boost::numeric::ublas::mapped_vector is not a Boost uBlas Matrix."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::compressed_vector<double>
        >::value,
        "::boost::numeric::ublas::compressed_vector is not a Boost uBlas Matrix."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::coordinate_vector<double>
        >::value,
        "::boost::numeric::ublas::coordinate_vector is not a Boost uBlas Matrix."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::unit_vector<>
        >::value,
        "::boost::numeric::ublas::unit_vector is not a Boost uBlas Matrix."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::zero_vector<>
        >::value,
        "::boost::numeric::ublas::zero_vector is not a Boost uBlas Matrix."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::scalar_vector<>
        >::value,
        "::boost::numeric::ublas::scalar_vector is not a Boost uBlas Matrix."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::matrix<double>,
            ::boost::mpl::true_
        >::value,
        "::boost::numeric::ublas::matrix is a Boost uBlas Matrix with data() as Storage."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::mapped_matrix<double>
        >::value,
        "::boost::numeric::ublas::mapped_matrix is a Boost uBlas Matrix."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::lower>,
            ::boost::mpl::true_
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix with data() as Storage."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::triangular_matrix<
                double,
                ::boost::numeric::ublas::strict_lower
            >,
            ::boost::mpl::true_
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix with data() as Storage."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas
            ::triangular_matrix<double,::boost::numeric::ublas::unit_lower>,
            ::boost::mpl::true_
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix with data() as Storage."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::triangular_matrix<double,::boost::numeric::ublas::upper>,
            ::boost::mpl::true_
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix with data() as Storage."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::triangular_matrix<
                double,
                ::boost::numeric::ublas::strict_upper
            >,
            ::boost::mpl::true_
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix with data() as Storage."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas
            ::triangular_matrix<double,::boost::numeric::ublas::unit_upper>,
            ::boost::mpl::true_
        >::value,
        "::boost::numeric::ublas::triangular_matrix is a Boost uBlas Matrix with data() as Storage."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::symmetric_matrix<double,::boost::numeric::ublas::lower>,
            ::boost::mpl::true_
        >::value,
        "::boost::numeric::ublas::symmetric_matrix is a Boost uBlas Matrix with data() as Storage."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::symmetric_matrix<double,::boost::numeric::ublas::upper>,
            ::boost::mpl::true_
        >::value,
        "::boost::numeric::ublas::symmetric_matrix is a Boost uBlas Matrix with data() as Storage."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas
            ::hermitian_matrix< ::std::complex<double>,::boost::numeric::ublas::lower>,
            ::boost::mpl::true_
        >::value,
        "::boost::numeric::ublas::hermitian_matrix is a Boost uBlas Matrix with data() as Storage."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas
            ::hermitian_matrix< ::std::complex<double>,::boost::numeric::ublas::upper>,
            ::boost::mpl::true_
        >::value,
        "::boost::numeric::ublas::hermitian_matrix is a Boost uBlas Matrix with data() as Storage."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::banded_matrix<double>,
            ::boost::mpl::true_
        >::value,
        "::boost::numeric::ublas::banded_matrix is a Boost uBlas Matrix with data() as Storage."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas
            ::banded_adaptor< ::boost::numeric::ublas::matrix<double> >
        >::value,
        "::boost::numeric::ublas::banded_adaptor is a Boost uBlas Matrix with data() as Storage."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::scalar_matrix<>
        >::value,
        "::boost::numeric::ublas::scalar_matrix is not a Boost uBlas Matrix."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::identity_matrix<>
        >::value,
        "::boost::numeric::ublas::identity_matrix is not a Boost uBlas Matrix."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_ublas_matrix<
            ::boost::numeric::ublas::zero_matrix<>
        >::value,
        "::boost::numeric::ublas::zero_matrix is not a Boost uBlas Matrix."
    );
}

#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    test_ublas_vector_minimal_expression();
    test_ublas_vector_expression();
    test_ublas_vector();
    test_ublas_matrix_minimal_expression();
    test_ublas_matrix_expression();
    test_ublas_matrix();
    return ::boost::report_errors();
}
