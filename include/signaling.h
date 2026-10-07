#pragma once
#include <FreeRTOS.h>
#include <semphr.h>

struct signal_data {
  int32_t input;
  int32_t output;
};

// should wait indefinitely until request semaphore is available and then take it
// take data and add 5
// save the result to data struct and give the response semaphore
void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data);

// Both sempahores should start as taken. When data arrives, request_calculate() is called (the data is passed in) and it should give the request semaphore
// should attempt to take response semaphore (but time out) and return whether the response semaphore is successfully taken

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data);
