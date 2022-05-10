/** @file
 *    @brief MAVLink comm protocol testsuite generated from ladon_robotics.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef LADON_ROBOTICS_TESTSUITE_H
#define LADON_ROBOTICS_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_development(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_ardupilotmega(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_ladon_robotics(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_development(system_id, component_id, last_msg);
    mavlink_test_ardupilotmega(system_id, component_id, last_msg);
    mavlink_test_ladon_robotics(system_id, component_id, last_msg);
}
#endif

#include "../development/testsuite.h"
#include "../ardupilotmega/testsuite.h"


static void mavlink_test_wingsail_actuator(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WINGSAIL_ACTUATOR >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wingsail_actuator_t packet_in = {
        17.0,{ 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0 },113,180,247,58,125
    };
    mavlink_wingsail_actuator_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.sail_angle = packet_in.sail_angle;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.target_sail = packet_in.target_sail;
        packet1.sail_angle_type = packet_in.sail_angle_type;
        packet1.flap_active = packet_in.flap_active;
        
        mav_array_memcpy(packet1.flap_angle, packet_in.flap_angle, sizeof(float)*8);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wingsail_actuator_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wingsail_actuator_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wingsail_actuator_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.target_sail , packet1.sail_angle_type , packet1.sail_angle , packet1.flap_active , packet1.flap_angle );
    mavlink_msg_wingsail_actuator_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wingsail_actuator_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.target_sail , packet1.sail_angle_type , packet1.sail_angle , packet1.flap_active , packet1.flap_angle );
    mavlink_msg_wingsail_actuator_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wingsail_actuator_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wingsail_actuator_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.target_sail , packet1.sail_angle_type , packet1.sail_angle , packet1.flap_active , packet1.flap_angle );
    mavlink_msg_wingsail_actuator_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("WINGSAIL_ACTUATOR") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_WINGSAIL_ACTUATOR) != NULL);
#endif
}

static void mavlink_test_wind_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WIND_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wind_data_t packet_in = {
        17.0,45.0,29,96,163,230
    };
    mavlink_wind_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.speed = packet_in.speed;
        packet1.direction = packet_in.direction;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.source_sail = packet_in.source_sail;
        packet1.wind_type = packet_in.wind_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WIND_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WIND_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wind_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wind_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wind_data_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.source_sail , packet1.wind_type , packet1.speed , packet1.direction );
    mavlink_msg_wind_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wind_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.source_sail , packet1.wind_type , packet1.speed , packet1.direction );
    mavlink_msg_wind_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wind_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wind_data_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.source_sail , packet1.wind_type , packet1.speed , packet1.direction );
    mavlink_msg_wind_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("WIND_DATA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_WIND_DATA) != NULL);
#endif
}

static void mavlink_test_ladon_robotics(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_wingsail_actuator(system_id, component_id, last_msg);
    mavlink_test_wind_data(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // LADON_ROBOTICS_TESTSUITE_H
