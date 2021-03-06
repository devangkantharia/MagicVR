#ifndef MAGICVR_MAGICTRICKS_HPP
#define MAGICVR_MAGICTRICKS_HPP

#include <vector>
#include <iostream>

#include <OpenSG/OSGVector.h>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <rxcpp/rx.hpp>
#include <magicvr/model.hpp>
#include <boost/geometry/extensions/strategies/cartesian/distance_info.hpp>
#include <trajecmp/gesture/circle.hpp>

#include "point.hpp"


namespace magicvr {
    struct circle_comparison_data {
        model::trajectory_2d preprocessed_input_trajectory;
        model::trajectory_2d preprocessed_pattern_trajectory;
        boost::geometry::distance_info_result<model::point_2d> distance;
        trajecmp::gesture::circle_segment_info<float, model::point_2d> circle_segment_info;
    };

    class MagicTricks {
    public:
        using Trajectory = std::vector<OSG::Vec3f>;
        rxcpp::observable<double> input_matches_pattern_water_stream;
        rxcpp::observable<double> input_matches_pattern_wind_stream;
        rxcpp::observable<double> input_matches_pattern_lightning_stream;
        rxcpp::observable<double> input_matches_pattern_fire_stream;
        rxcpp::observable<double> input_matches_pattern_quaterCircleFromAbove_stream;
        rxcpp::observable<double> input_matches_pattern_circle_stream;
        rxcpp::observable<double> input_matches_pattern_circle2_stream;

        rxcpp::observable<Trajectory> preprocessed_pattern_circle_trajectory_stream;
        rxcpp::observable<Trajectory> preprocessed_pattern_circle2_trajectory_stream;
        rxcpp::observable<Trajectory> preprocessed_pattern_lightning_trajectory_stream;
        rxcpp::observable<Trajectory> preprocessedWithoutRotation_input_trajectory_stream;
        rxcpp::observable<Trajectory> left_preprocessed_input_trajectory_stream;
        rxcpp::observable<Trajectory> right_preprocessed_input_trajectory_stream;

        rxcpp::observable<circle_comparison_data> left_circle_comparison_data_stream;
        rxcpp::observable<circle_comparison_data> right_circle_comparison_data_stream;
        rxcpp::observable<circle_comparison_data> circle_comparison_data_stream;

        MagicTricks();

        void emit(Trajectory &&trajectory) const;

    private:
        rxcpp::rxsub::subject<Trajectory> input_trajectory_subject;
    };
}

#endif //MAGICVR_MAGICTRICKS_HPP
