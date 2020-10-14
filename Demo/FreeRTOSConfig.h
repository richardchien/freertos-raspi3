#pragma once

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION 1
#define configUSE_IDLE_HOOK  0
#define configUSE_TICK_HOOK  0
#define configCPU_CLOCK_HZ   ((unsigned long)24000000)
#define configTICK_RATE_HZ   ((portTickType)1000)

#define configMAX_PRIORITIES           (5)
#define configMINIMAL_STACK_SIZE       ((unsigned short)128)
#define configTOTAL_HEAP_SIZE          ((size_t)(4096))
#define configMAX_TASK_NAME_LEN        (16)
#define configUSE_TRACE_FACILITY       0
#define configUSE_16_BIT_TICKS         0
#define configIDLE_SHOULD_YIELD        1
#define configUSE_APPLICATION_TASK_TAG 1

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES           0
#define configMAX_CO_ROUTINE_PRIORITIES (2)

#define configSETUP_TICK_INTERRUPT() vSetupTickInterrupt()

//#define portBYTE_ALIGNMENT	1

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_vTaskPrioritySet          1
#define INCLUDE_uxTaskPriorityGet         1
#define INCLUDE_vTaskDelete               1
#define INCLUDE_vTaskCleanUpResources     0
#define INCLUDE_vTaskSuspend              1
#define INCLUDE_vTaskDelayUntil           1
#define INCLUDE_vTaskDelay                1
#define INCLUDE_xTaskGetCurrentTaskHandle 1
