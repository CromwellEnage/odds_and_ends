// Copyright (C) 2025-2026 Cromwell D. Enage

#include <odds_and_ends/static_introspection/concept/is_accumulator.hpp>
#include <boost/accumulators/statistics.hpp>
#include <boost/mpl/int.hpp>
#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::count_impl
        >::value,
        "::boost::accumulators::impl::count_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::covariance_impl<
                double,
                double,
                ::boost::accumulators::tag::covariate1
            >
        >::value,
        "::boost::accumulators::impl::covariance_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::covariance_impl<
                double,
                double,
                ::boost::accumulators::tag::covariate2
            >
        >::value,
        "::boost::accumulators::impl::covariance_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::density_impl<double>
        >::value,
        "::boost::accumulators::impl::density_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::extended_p_square_impl<double>
        >::value,
        "::boost::accumulators::impl::extended_p_square_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::extended_p_square_quantile_impl<
                double,
                ::boost::accumulators::unweighted,
                ::boost::accumulators::linear
            >
        >::value,
        "::boost::accumulators::impl::extended_p_square_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::extended_p_square_quantile_impl<
                double,
                ::boost::accumulators::unweighted,
                ::boost::accumulators::quadratic
            >
        >::value,
        "::boost::accumulators::impl::extended_p_square_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::extended_p_square_quantile_impl<
                double,
                ::boost::accumulators::weighted,
                ::boost::accumulators::linear
            >
        >::value,
        "::boost::accumulators::impl::extended_p_square_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::extended_p_square_quantile_impl<
                double,
                ::boost::accumulators::weighted,
                ::boost::accumulators::quadratic
            >
        >::value,
        "::boost::accumulators::impl::extended_p_square_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::kurtosis_impl<double>
        >::value,
        "::boost::accumulators::impl::kurtosis_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::max_impl<double>
        >::value,
        "::boost::accumulators::impl::max_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::min_impl<double>
        >::value,
        "::boost::accumulators::impl::min_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::mean_impl<double,::boost::accumulators::tag::sum>
        >::value,
        "::boost::accumulators::impl::mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl
            ::mean_impl<double,::boost::accumulators::tag::sum_of_weights>
        >::value,
        "::boost::accumulators::impl::mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::mean_impl<
                double,
                ::boost::accumulators::tag
                ::sum_of_variates<double,::boost::accumulators::tag::covariate1>
            >
        >::value,
        "::boost::accumulators::impl::mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::mean_impl<
                double,
                ::boost::accumulators::tag
                ::sum_of_variates<double,::boost::accumulators::tag::covariate2>
            >
        >::value,
        "::boost::accumulators::impl::mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl
            ::immediate_mean_impl<double,::boost::accumulators::tag::sum>
        >::value,
        "::boost::accumulators::impl::immediate_mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl
            ::immediate_mean_impl<double,::boost::accumulators::tag::sum_of_weights>
        >::value,
        "::boost::accumulators::impl::immediate_mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::immediate_mean_impl<
                double,
                ::boost::accumulators::tag
                ::sum_of_variates<double,::boost::accumulators::tag::covariate1>
            >
        >::value,
        "::boost::accumulators::impl::immediate_mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::immediate_mean_impl<
                double,
                ::boost::accumulators::tag
                ::sum_of_variates<double,::boost::accumulators::tag::covariate2>
            >
        >::value,
        "::boost::accumulators::impl::immediate_mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::median_impl<double>
        >::value,
        "::boost::accumulators::impl::median_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::with_density_median_impl<double>
        >::value,
        "::boost::accumulators::impl::with_density_median_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::with_p_square_cumulative_distribution_median_impl<double>
        >::value,
        "with_p_square_cumulative_distribution_median_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::moment_impl< ::boost::mpl::int_<1>,double>
        >::value,
        "::boost::accumulators::impl::moment_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::peaks_over_threshold_impl<
                double,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::impl::peaks_over_threshold_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::peaks_over_threshold_impl<
                double,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::impl::peaks_over_threshold_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::pot_tail_mean_impl<
                double,
                ::boost::accumulators::unweighted,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::impl::pot_tail_mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::pot_tail_mean_impl<
                double,
                ::boost::accumulators::unweighted,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::impl::pot_tail_mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::pot_tail_mean_impl<
                double,
                ::boost::accumulators::weighted,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::impl::pot_tail_mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::pot_tail_mean_impl<
                double,
                ::boost::accumulators::weighted,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::impl::pot_tail_mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::pot_quantile_impl<
                double,
                ::boost::accumulators::unweighted,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::impl::pot_quantile_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::pot_quantile_impl<
                double,
                ::boost::accumulators::unweighted,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::impl::pot_quantile_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::pot_quantile_impl<
                double,
                ::boost::accumulators::weighted,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::impl::pot_quantile_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::pot_quantile_impl<
                double,
                ::boost::accumulators::weighted,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::impl::pot_quantile_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::p_square_cumulative_distribution_impl<double>
        >::value,
        "::boost::accumulators::impl::p_square_cumulative_distribution_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::p_square_quantile_impl<
                double,
                ::boost::accumulators::regular
            >
        >::value,
        "::boost::accumulators::impl::p_square_cumulative_distribution_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl
            ::p_square_quantile_impl<double,::boost::accumulators::for_median>
        >::value,
        "::boost::accumulators::impl::p_square_quantile_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::skewness_impl<double>
        >::value,
        "::boost::accumulators::impl::skewness_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::sum_impl<double,::boost::accumulators::tag::sample>
        >::value,
        "::boost::accumulators::impl::sum_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::sum_impl<double,::boost::accumulators::tag::weight>
        >::value,
        "::boost::accumulators::impl::sum_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::sum_impl<
                double,
                ::boost::accumulators::tag
                ::sum_of_variates<double,::boost::accumulators::tag::covariate1>
            >
        >::value,
        "::boost::accumulators::impl::sum_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::sum_impl<
                double,
                ::boost::accumulators::tag
                ::sum_of_variates<double,::boost::accumulators::tag::covariate2>
            >
        >::value,
        "::boost::accumulators::impl::sum_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::sum_kahan_impl<double,::boost::accumulators::tag::sample>
        >::value,
        "::boost::accumulators::impl::sum_kahan_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::sum_kahan_impl<double,::boost::accumulators::tag::weight>
        >::value,
        "::boost::accumulators::impl::sum_kahan_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::sum_kahan_impl<
                double,
                ::boost::accumulators::tag
                ::sum_of_variates<double,::boost::accumulators::tag::covariate1>
            >
        >::value,
        "::boost::accumulators::impl::sum_kahan_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::sum_kahan_impl<
                double,
                ::boost::accumulators::tag
                ::sum_of_variates<double,::boost::accumulators::tag::covariate2>
            >
        >::value,
        "::boost::accumulators::impl::sum_kahan_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_impl<double,::boost::accumulators::left>
        >::value,
        "::boost::accumulators::impl::tail_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_impl<double,::boost::accumulators::right>
        >::value,
        "::boost::accumulators::impl::tail_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_quantile_impl<double,::boost::accumulators::left>
        >::value,
        "::boost::accumulators::impl::tail_quantile_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_quantile_impl<double,::boost::accumulators::right>
        >::value,
        "::boost::accumulators::impl::tail_quantile_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl
            ::coherent_tail_mean_impl<double,::boost::accumulators::left>
        >::value,
        "::boost::accumulators::impl::coherent_tail_mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl
            ::coherent_tail_mean_impl<double,::boost::accumulators::right>
        >::value,
        "::boost::accumulators::impl::coherent_tail_mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl
            ::non_coherent_tail_mean_impl<double,::boost::accumulators::left>
        >::value,
        "::boost::accumulators::impl::non_coherent_tail_mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl
            ::non_coherent_tail_mean_impl<double,::boost::accumulators::right>
        >::value,
        "::boost::accumulators::impl::non_coherent_tail_mean_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_variate_impl<
                int,
                ::boost::accumulators::tag::covariate1,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::impl::tail_variate_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_variate_impl<
                int,
                ::boost::accumulators::tag::covariate1,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::impl::tail_variate_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_variate_impl<
                int,
                ::boost::accumulators::tag::covariate2,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::impl::tail_variate_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_variate_impl<
                int,
                ::boost::accumulators::tag::covariate2,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::impl::tail_variate_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_variate_means_impl<
                int,
                ::boost::accumulators::absolute,
                ::boost::accumulators::tag::covariate1,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::impl::tail_variate_means_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_variate_means_impl<
                int,
                ::boost::accumulators::absolute,
                ::boost::accumulators::tag::covariate1,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::impl::tail_variate_means_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_variate_means_impl<
                int,
                ::boost::accumulators::absolute,
                ::boost::accumulators::tag::covariate2,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::impl::tail_variate_means_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_variate_means_impl<
                int,
                ::boost::accumulators::absolute,
                ::boost::accumulators::tag::covariate2,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::impl::tail_variate_means_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_variate_means_impl<
                int,
                ::boost::accumulators::relative,
                ::boost::accumulators::tag::covariate1,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::impl::tail_variate_means_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_variate_means_impl<
                int,
                ::boost::accumulators::relative,
                ::boost::accumulators::tag::covariate1,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::impl::tail_variate_means_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_variate_means_impl<
                int,
                ::boost::accumulators::relative,
                ::boost::accumulators::tag::covariate2,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::impl:: is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::tail_variate_means_impl<
                int,
                ::boost::accumulators::relative,
                ::boost::accumulators::tag::covariate2,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::impl::tail_variate_means_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::variance_impl<
                double,
                ::boost::accumulators::tag::mean,
                ::boost::accumulators::tag::sample
            >
        >::value,
        "::boost::accumulators::impl::variance_impl is a Boost Accumulator"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator<
            ::boost::accumulators::impl::lazy_variance_impl<
                double,
                ::boost::accumulators::tag::mean
            >
        >::value,
        "::boost::accumulators::impl::lazy_variance_impl is a Boost Accumulator"
    );
    return ::boost::report_errors();
}
