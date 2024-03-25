/*
 * Copyright (c) 2017 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__


#ifdef CONFIG_NET_IPV6
#define SERVER_ADDR		"::1"
#else
#define SERVER_ADDR		"127.0.0.1"
#endif

#define SERVER_PORT		1883

#define APP_CONNECT_TIMEOUT_MS	2000
#define APP_SLEEP_MSECS		500

#define APP_CONNECT_TRIES	10

#define APP_MQTT_BUFFER_SIZE	128

#define MQTT_CLIENTID		"pub_id_0"

/* Set the following to 1 to enable the Bluemix topic format */
#define APP_BLUEMIX_TOPIC	0

#endif
