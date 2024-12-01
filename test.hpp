#pragma once

#include "car.hpp"
#include "car_builder.hpp"

#include <iostream>
#include <cassert>

/**
 * TEST PLAN
 * correct car creation all values set
 * correct car creation only mandatory values set
 *
 * wrong car creation all mandatory values missed
 * wrong car creation brand name mandatory value missed
 * wrong car creation model name mandatory value missed
 * wrong car creation production year mandatory value missed
 * wrong car creation mileage mandatory value missed
 * wrong car creation max fuel level mandatory value missed
 */

void CheckCorrectCarCreationAllValuesSet()
{
    const auto car = CarBuilder()
                         .WithBrandName("Zaz")
                         .WithModelName("Tavria")
                         .WithProductionYear(1999)
                         .WithMileage(100)
                         .WithMaxFuelLevel(39)
                         .WithCurrentFuelLevel(39)
                         .Build();

    assert(car.GetBrandName() == "Zaz");
    assert(car.GetModelName() == "Tavria");
    assert(car.GetProductionYear() == 1999);
    assert(car.GetMileage() == 100);
    assert(car.GetMaxFuelLevel() == 39);
    assert(car.GetCurrentFuelLevel() == 39);
}

void CheckCorrectCarCreationOnlyMandatoryValuesSet()
{
    const auto car = CarBuilder()
                         .WithBrandName("Zaz")
                         .WithModelName("Tavria")
                         .WithProductionYear(1999)
                         .WithMileage(100)
                         .WithMaxFuelLevel(39)
                         // skip setting not mandatory value
                         //  .WithCurrentFuelLevel(39)
                         .Build();

    assert(car.GetBrandName() == "Zaz");
    assert(car.GetModelName() == "Tavria");
    assert(car.GetProductionYear() == 1999);
    assert(car.GetMileage() == 100);
    assert(car.GetMaxFuelLevel() == 39);
    assert(car.GetCurrentFuelLevel() == 0);
}

void CheckWrongCarCreationAllMandatoryValuesMissed()
{
    try
    {
        const auto car = CarBuilder()
                             // skip setting mandatory values
                             //  .WithBrandName("Zaz")
                             //  .WithModelName("Tavria")
                             //  .WithProductionYear(1999)
                             //  .WithMileage(100)
                             //  .WithMaxFuelLevel(39)
                             .WithCurrentFuelLevel(39)
                             .Build();
    }
    catch (const std::runtime_error &e)
    {
        assert(
            std::string(e.what()) ==
            "Not all mandatory values were set for car creation. Mandatory values are: 00000");
    }
}

void CheckWrongCarCreationBrandNameMandatoryValueMissed()
{
    try
    {
        const auto car = CarBuilder()
                             // skip setting mandatory value
                             //  .WithBrandName("Zaz")
                             .WithModelName("Tavria")
                             .WithProductionYear(1999)
                             .WithMileage(100)
                             .WithMaxFuelLevel(39)
                             .WithCurrentFuelLevel(39)
                             .Build();
    }
    catch (const std::runtime_error &e)
    {
        assert(
            std::string(e.what()) ==
            "Not all mandatory values were set for car creation. Mandatory values are: 01111");
    }
}

void CheckWrongCarCreationModelNameMandatoryValueMissed()
{
    try
    {
        const auto car = CarBuilder()
                             .WithBrandName("Zaz")
                             // skip setting mandatory value
                             //  .WithModelName("Tavria")
                             .WithProductionYear(1999)
                             .WithMileage(100)
                             .WithMaxFuelLevel(39)
                             .WithCurrentFuelLevel(39)
                             .Build();
    }
    catch (const std::runtime_error &e)
    {
        assert(
            std::string(e.what()) ==
            "Not all mandatory values were set for car creation. Mandatory values are: 10111");
    }
}

void CheckWrongCarCreationProductionYearMandatoryValueMissed()
{
    try
    {
        const auto car = CarBuilder()
                             .WithBrandName("Zaz")
                             .WithModelName("Tavria")
                             // skip setting mandatory value
                             //  .WithProductionYear(1999)
                             .WithMileage(100)
                             .WithMaxFuelLevel(39)
                             .WithCurrentFuelLevel(39)
                             .Build();
    }
    catch (const std::runtime_error &e)
    {
        assert(
            std::string(e.what()) ==
            "Not all mandatory values were set for car creation. Mandatory values are: 11011");
    }
}

void CheckWrongCarCreationMileageMandatoryValueMissed()
{
    try
    {
        const auto car = CarBuilder()
                             .WithBrandName("Zaz")
                             .WithModelName("Tavria")
                             .WithProductionYear(1999)
                             // skip setting mandatory value
                             //  .WithMileage(100)
                             .WithMaxFuelLevel(39)
                             .WithCurrentFuelLevel(39)
                             .Build();
    }
    catch (const std::runtime_error &e)
    {
        assert(
            std::string(e.what()) ==
            "Not all mandatory values were set for car creation. Mandatory values are: 11101");
    }
}

void CheckWrongCarCreationMaxFuelLevelMandatoryValueMissed()
{
    try
    {
        const auto car = CarBuilder()
                             .WithBrandName("Zaz")
                             .WithModelName("Tavria")
                             .WithProductionYear(1999)
                             .WithMileage(100)
                             // skip setting mandatory value
                             //  .WithMaxFuelLevel(39)
                             .WithCurrentFuelLevel(39)
                             .Build();
    }
    catch (const std::runtime_error &e)
    {
        assert(
            std::string(e.what()) ==
            "Not all mandatory values were set for car creation. Mandatory values are: 11110");
    }
}

void PerformAllChecks()
{
    CheckCorrectCarCreationAllValuesSet();
    CheckCorrectCarCreationOnlyMandatoryValuesSet();

    CheckWrongCarCreationAllMandatoryValuesMissed();
    CheckWrongCarCreationBrandNameMandatoryValueMissed();
    CheckWrongCarCreationModelNameMandatoryValueMissed();
    CheckWrongCarCreationProductionYearMandatoryValueMissed();
    CheckWrongCarCreationMileageMandatoryValueMissed();
    CheckWrongCarCreationMaxFuelLevelMandatoryValueMissed();

    std::cout << "ALL TESTS PASSED" << '\n';
}