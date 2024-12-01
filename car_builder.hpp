#pragma once

#include "car.hpp"
#include <bitset>
#include <stdexcept>
#include <algorithm>

class CarBuilder
{
public:
    CarBuilder &WithBrandName(const std::string &brand_name)
    {
        car_.brand_name_ = brand_name;
        mandatory_values_.set(MandatoryValues::kBrandName);

        return *this;
    }

    CarBuilder &WithModelName(const std::string &model_name)
    {
        car_.model_name_ = model_name;
        mandatory_values_.set(MandatoryValues::kModelName);

        return *this;
    }

    CarBuilder &WithProductionYear(unsigned production_year)
    {
        car_.production_year_ = production_year;
        mandatory_values_.set(MandatoryValues::kProductionYear);

        return *this;
    }

    CarBuilder &WithMileage(unsigned mileage)
    {
        car_.mileage_ = mileage;
        mandatory_values_.set(MandatoryValues::kMileage);

        return *this;
    }

    CarBuilder &WithMaxFuelLevel(unsigned max_fuel_level)
    {
        assert(max_fuel_level != 0 && "max_fuel_level_ must be bigger that zero");

        car_.max_fuel_level_ = max_fuel_level;
        mandatory_values_.set(MandatoryValues::kMaxFuelLevel);

        return *this;
    }

    CarBuilder &WithCurrentFuelLevel(unsigned current_fuel_level_)
    {
        car_.current_fuel_level_ = current_fuel_level_;
        return *this;
    }

    Car Build()
    {
        if (!mandatory_values_.all())
        {
            std::string mandatory_values_as_str = mandatory_values_.to_string();
            std::reverse(mandatory_values_as_str.begin(), mandatory_values_as_str.end());

            mandatory_values_.reset();

            throw std::runtime_error(
                "Not all mandatory values were set for car creation. Mandatory values are: " +
                mandatory_values_as_str);
        }

        mandatory_values_.reset();
        return car_;
    }

private:
    enum MandatoryValues
    {
        kBrandName = 0,
        kModelName,
        kProductionYear,
        kMileage,
        kMaxFuelLevel,

        Count
    };
    std::bitset<MandatoryValues::Count> mandatory_values_;

    Car car_;
};