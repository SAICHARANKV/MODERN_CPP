#include "Functionalities.hpp"

void CreateObjects(Container &data) {
  data.push(Reading(ReadingType::TEMPERATURE, 32.1f));
  data.push(Reading(ReadingType::TEMPERATURE, 32.7f));
  data.push(Reading(ReadingType::TYRE_PRESSURE, 36.0f));
  data.push(Reading(ReadingType::RPM, 3000.0f));
}

