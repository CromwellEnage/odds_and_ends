// Copyright (C) 2025 Cromwell D. Enage

#include <odds_and_ends/static_introspection/concept/is_accumulator_feature.hpp>
#include <boost/accumulators/statistics.hpp>
#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::count
        >::value,
        "::boost::accumulators::tag::count is a Boost Accumulator Feature"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::covariate1
        >::value,
        "::boost::accumulators::tag::covariate1 is not a Boost Accumulator Feature"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::covariate2
        >::value,
        "::boost::accumulators::tag::covariate2 is not a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::covariance<double,::boost::accumulators::tag::covariate1>
        >::value,
        "::boost::accumulators::tag::covariance is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::covariance<double,::boost::accumulators::tag::covariate2>
        >::value,
        "::boost::accumulators::tag::covariance is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::density
        >::value,
        "::boost::accumulators::tag::density is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::extended_p_square
        >::value,
        "::boost::accumulators::tag::extended_p_square is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::extended_p_square_quantile
        >::value,
        "::boost::accumulators::tag::extended_p_square_quantile is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::extended_p_square_quantile_quadratic
        >::value,
        "extended_p_square_quantile_quadratic is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::weighted_extended_p_square_quantile
        >::value,
        "weighted_extended_p_square_quantile is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::weighted_extended_p_square_quantile_quadratic
        >::value,
        "weighted_extended_p_square_quantile_quadratic is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::kurtosis
        >::value,
        "::boost::accumulators::tag::kurtosis is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::max
        >::value,
        "::boost::accumulators::tag::max is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::min
        >::value,
        "::boost::accumulators::tag::min is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::mean
        >::value,
        "::boost::accumulators::tag::mean is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::immediate_mean
        >::value,
        "::boost::accumulators::tag::immediate_mean is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::mean_of_weights
        >::value,
        "::boost::accumulators::tag::mean_of_weights is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::immediate_mean_of_weights
        >::value,
        "::boost::accumulators::tag::immediate_mean_of_weights is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag
            ::mean_of_variates<double,::boost::accumulators::tag::covariate1>
        >::value,
        "::boost::accumulators::tag::mean_of_variates is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag
            ::mean_of_variates<double,::boost::accumulators::tag::covariate2>
        >::value,
        "::boost::accumulators::tag::mean_of_variates is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag
            ::immediate_mean_of_variates<double,::boost::accumulators::tag::covariate1>
        >::value,
        "::boost::accumulators::tag::immediate_mean_of_variates is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag
            ::immediate_mean_of_variates<double,::boost::accumulators::tag::covariate2>
        >::value,
        "::boost::accumulators::tag::immediate_mean_of_variates is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::median
        >::value,
        "::boost::accumulators::tag::median is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::with_density_median
        >::value,
        "::boost::accumulators::tag::with_density_median is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::with_p_square_cumulative_distribution_median
        >::value,
        "with_p_square_cumulative_distribution_median is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::moment<1>
        >::value,
        "::boost::accumulators::tag::moment is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::peaks_over_threshold< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::peaks_over_threshold is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::peaks_over_threshold< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::peaks_over_threshold is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::peaks_over_threshold_prob< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::peaks_over_threshold_prob is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::peaks_over_threshold_prob< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::peaks_over_threshold_prob is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::pot_tail_mean< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::pot_tail_mean is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::pot_tail_mean< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::pot_tail_mean is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::pot_tail_mean_prob< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::pot_tail_mean_prob is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::pot_tail_mean_prob< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::pot_tail_mean_prob is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::weighted_pot_tail_mean< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::weighted_pot_tail_mean is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::weighted_pot_tail_mean< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::weighted_pot_tail_mean is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::weighted_pot_tail_mean_prob< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::weighted_pot_tail_mean_prob is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::weighted_pot_tail_mean_prob< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::weighted_pot_tail_mean_prob is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::pot_quantile< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::pot_quantile is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::pot_quantile< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::pot_quantile is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::pot_quantile_prob< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::pot_quantile_prob is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::pot_quantile_prob< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::pot_quantile_prob is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::weighted_pot_quantile< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::weighted_pot_quantile is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::weighted_pot_quantile< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::weighted_pot_quantile is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::weighted_pot_quantile_prob< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::weighted_pot_quantile_prob is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::weighted_pot_quantile_prob< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::weighted_pot_quantile_prob is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::p_square_cumulative_distribution
        >::value,
        "p_square_cumulative_distribution is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::p_square_quantile
        >::value,
        "::boost::accumulators::tag::p_square_quantile is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::p_square_quantile_for_median
        >::value,
        "::boost::accumulators::tag::p_square_quantile_for_median is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::skewness
        >::value,
        "::boost::accumulators::tag::skewness is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::sum
        >::value,
        "::boost::accumulators::tag::sum is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::sum_of_weights
        >::value,
        "::boost::accumulators::tag::sum_of_weights is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag
            ::sum_of_variates<double,::boost::accumulators::tag::covariate1>
        >::value,
        "::boost::accumulators::tag::sum_of_variates is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag
            ::sum_of_variates<double,::boost::accumulators::tag::covariate2>
        >::value,
        "::boost::accumulators::tag::sum_of_variates is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::sum_kahan
        >::value,
        "::boost::accumulators::tag::sum_kahan is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::sum_of_weights_kahan
        >::value,
        "::boost::accumulators::tag::sum_of_weights_kahan is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag
            ::sum_of_variates_kahan<double,::boost::accumulators::tag::covariate1>
        >::value,
        "::boost::accumulators::tag::sum_of_variates_kahan is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag
            ::sum_of_variates_kahan<double,::boost::accumulators::tag::covariate2>
        >::value,
        "::boost::accumulators::tag::sum_of_variates_kahan is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::tail< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::tail is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::tail< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::tail is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::tail_quantile< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::tail_quantile is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::tail_quantile< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::tail_quantile is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::coherent_tail_mean< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::coherent_tail_mean is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::coherent_tail_mean< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::coherent_tail_mean is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::non_coherent_tail_mean< ::boost::accumulators::left>
        >::value,
        "::boost::accumulators::tag::non_coherent_tail_mean is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::non_coherent_tail_mean< ::boost::accumulators::right>
        >::value,
        "::boost::accumulators::tag::non_coherent_tail_mean is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::tail_variate<
                int,
                ::boost::accumulators::tag::covariate1,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::tag::tail_variate is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::tail_variate<
                int,
                ::boost::accumulators::tag::covariate1,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::tag::tail_variate is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::tail_variate<
                int,
                ::boost::accumulators::tag::covariate2,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::tag::tail_variate is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::tail_variate<
                int,
                ::boost::accumulators::tag::covariate2,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::tag::tail_variate is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::absolute_tail_variate_means<
                int,
                ::boost::accumulators::tag::covariate1,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::tag::absolute_tail_variate_means is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::absolute_tail_variate_means<
                int,
                ::boost::accumulators::tag::covariate1,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::tag::absolute_tail_variate_means is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::absolute_tail_variate_means<
                int,
                ::boost::accumulators::tag::covariate2,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::tag::absolute_tail_variate_means is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::absolute_tail_variate_means<
                int,
                ::boost::accumulators::tag::covariate2,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::tag::absolute_tail_variate_means is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::relative_tail_variate_means<
                int,
                ::boost::accumulators::tag::covariate1,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::tag::relative_tail_variate_means is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::relative_tail_variate_means<
                int,
                ::boost::accumulators::tag::covariate1,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::tag::relative_tail_variate_means is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::relative_tail_variate_means<
                int,
                ::boost::accumulators::tag::covariate2,
                ::boost::accumulators::left
            >
        >::value,
        "::boost::accumulators::tag::relative_tail_variate_means is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::relative_tail_variate_means<
                int,
                ::boost::accumulators::tag::covariate2,
                ::boost::accumulators::right
            >
        >::value,
        "::boost::accumulators::tag::relative_tail_variate_means is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::variance
        >::value,
        "::boost::accumulators::tag::variance is a Boost Accumulator Feature"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_accumulator_feature<
            ::boost::accumulators::tag::lazy_variance
        >::value,
        "::boost::accumulators::tag::lazy_variance is a Boost Accumulator Feature"
    );
    return ::boost::report_errors();
}
