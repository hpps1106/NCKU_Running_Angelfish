/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "detection_responder.h"
#include "model_settings.h"
#include "hx_drv_tflm.h"

namespace {
uint8_t score_output[kCategoryCount];
}
void RespondToDetection(tflite::ErrorReporter* error_reporter, int8_t* output) {

  hx_drv_uart_initial(UART_BR_115200);//initialize UART

  //TF_LITE_REPORT_ERROR(error_reporter, "Lane detection start!\n");
  for (int i = 0; i < kCategoryCount; i++) 
  {
    score_output[i] = output[i] + 128;
  }
  TF_LITE_REPORT_ERROR(error_reporter, "Lane detection score = %d" , score_output[0]);

  if(score_output[0] > score_output[1])
  {
    TF_LITE_REPORT_ERROR(error_reporter, "Detect Lane");
    hx_drv_led_on(HX_DRV_LED_GREEN);
    hx_drv_led_off(HX_DRV_LED_RED);
  }
  else
  {
    TF_LITE_REPORT_ERROR(error_reporter, "Lane Departure");
    hx_drv_led_on(HX_DRV_LED_RED);
    hx_drv_led_off(HX_DRV_LED_GREEN);
  }
  
  //send result data out through SPI
  hx_drv_spim_send((uint32_t)score_output, sizeof(int8_t) * kCategoryCount,
                   SPI_TYPE_META_DATA);
}
