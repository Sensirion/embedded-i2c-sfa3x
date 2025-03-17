/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * Generator:     sensirion-driver-generator 1.1.2
 * Product:       sfa3x
 * Model-Version: 1.0.0
 */

#include "sensirion_common.h"
#include "sensirion_i2c.h"
#include "sensirion_i2c_hal.h"
#include "sensirion_test_setup.h"
#include "sfa3x_i2c.h"
#include <inttypes.h>
#include <stdio.h>

#define sensirion_hal_sleep_us sensirion_i2c_hal_sleep_usec

TEST_GROUP (SFA3X_Tests) {
    void setup() {
        sfa3x_init(0x5D);
    }
};

TEST (SFA3X_Tests, test_get_device_marking1) {
    int16_t local_error = 0;
    int8_t device_marking[32] = {0};
    local_error = sfa3x_get_device_marking(device_marking, 32);
    CHECK_EQUAL_ZERO_TEXT(local_error, "get_device_marking");
    printf("device_marking: %s\n", device_marking);
}

TEST (SFA3X_Tests, test_device_reset1) {
    int16_t local_error = 0;
    local_error = sfa3x_device_reset();
    CHECK_EQUAL_ZERO_TEXT(local_error, "device_reset");
}

TEST (SFA3X_Tests, test_start_continuous_measurement1) {
    int16_t local_error = 0;
    int16_t hcho = 0;
    int16_t humidity = 0;
    int16_t temperature = 0;
    local_error = sfa3x_start_continuous_measurement();
    CHECK_EQUAL_ZERO_TEXT(local_error, "start_continuous_measurement");
    local_error =
        sfa3x_read_measured_values_as_integers(&hcho, &humidity, &temperature);
    CHECK_EQUAL_ZERO_TEXT(local_error, "read_measured_values_as_integers");
    printf("hcho: %i ", hcho);
    printf("humidity: %i ", humidity);
    printf("temperature: %i\n", temperature);
    local_error = sfa3x_stop_measurement();
    CHECK_EQUAL_ZERO_TEXT(local_error, "stop_measurement");
}
