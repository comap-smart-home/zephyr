/**
 * @file pwm_stm32_ex.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef PWM_STM32_EX_H_
#define PWM_STM32_EX_H_

#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>

typedef void (*pwm_stm32_ex_update_callback_t)(const struct device *dev,
	void *user_data);

typedef void (*pwm_stm32_ex_configure_update_callback_t)(const struct device *dev,
			pwm_stm32_ex_update_callback_t cb, void *user_data);

__subsystem struct pwm_driver_stm32_ex_api {
	struct pwm_driver_api standard_api;
	pwm_stm32_ex_configure_update_callback_t configure_update_callback;
};

__syscall void pwm_stm32_ex_configure_update_callback(const struct device *dev,
		pwm_stm32_ex_update_callback_t cb,
		void *user_data);

static inline void z_impl_pwm_stm32_ex_configure_update_callback(
		const struct device *dev,
		pwm_stm32_ex_update_callback_t cb, void *user_data)
{
	const struct pwm_driver_stm32_ex_api *api = dev->api;
	
	api->configure_update_callback(dev, cb, user_data);
}

#include <syscalls/pwm_stm32_ex.h>

 #endif /*PWM_STM32_EX_H_*/