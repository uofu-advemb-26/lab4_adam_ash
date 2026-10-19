#include "signaling.h"
#include <stdio.h>

void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data) {
  printf("(!) signal_handle_calculation\n");
  xSemaphoreTake(request, portMAX_DELAY);
  printf("calculating...\n");
  data->output = data->input + 5;
  vTaskDelay(10);
  printf("giving back semaphore\n");
  xSemaphoreGive(response);
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data) {
  printf("(!) signal_request_calculate\n");
  printf("giving back semaphore\n");
  xSemaphoreGive(request);
  printf("waiting...\n");
  BaseType_t res = xSemaphoreTake(response, 100);
  printf("res received\n");
  return res;
}
