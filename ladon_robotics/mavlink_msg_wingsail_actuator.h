#pragma once
// MESSAGE WINGSAIL_ACTUATOR PACKING

#define MAVLINK_MSG_ID_WINGSAIL_ACTUATOR 44000


typedef struct __mavlink_wingsail_actuator_t {
 float sail_angle; /*< [deg] Angle of the sail*/
 float flap_angle[8]; /*<  Flap position/command values. Unused fields are set to zero*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t target_sail; /*<  Position of the target sail*/
 uint8_t sail_angle_type; /*<  Type of angle specified*/
 uint8_t flap_active; /*<  Bitmask of active flap values*/
} mavlink_wingsail_actuator_t;

#define MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN 41
#define MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_MIN_LEN 41
#define MAVLINK_MSG_ID_44000_LEN 41
#define MAVLINK_MSG_ID_44000_MIN_LEN 41

#define MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_CRC 94
#define MAVLINK_MSG_ID_44000_CRC 94

#define MAVLINK_MSG_WINGSAIL_ACTUATOR_FIELD_FLAP_ANGLE_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WINGSAIL_ACTUATOR { \
    44000, \
    "WINGSAIL_ACTUATOR", \
    7, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_wingsail_actuator_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_wingsail_actuator_t, target_component) }, \
         { "target_sail", NULL, MAVLINK_TYPE_UINT8_T, 0, 38, offsetof(mavlink_wingsail_actuator_t, target_sail) }, \
         { "sail_angle_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 39, offsetof(mavlink_wingsail_actuator_t, sail_angle_type) }, \
         { "sail_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wingsail_actuator_t, sail_angle) }, \
         { "flap_active", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_wingsail_actuator_t, flap_active) }, \
         { "flap_angle", NULL, MAVLINK_TYPE_FLOAT, 8, 4, offsetof(mavlink_wingsail_actuator_t, flap_angle) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WINGSAIL_ACTUATOR { \
    "WINGSAIL_ACTUATOR", \
    7, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_wingsail_actuator_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_wingsail_actuator_t, target_component) }, \
         { "target_sail", NULL, MAVLINK_TYPE_UINT8_T, 0, 38, offsetof(mavlink_wingsail_actuator_t, target_sail) }, \
         { "sail_angle_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 39, offsetof(mavlink_wingsail_actuator_t, sail_angle_type) }, \
         { "sail_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wingsail_actuator_t, sail_angle) }, \
         { "flap_active", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_wingsail_actuator_t, flap_active) }, \
         { "flap_angle", NULL, MAVLINK_TYPE_FLOAT, 8, 4, offsetof(mavlink_wingsail_actuator_t, flap_angle) }, \
         } \
}
#endif

/**
 * @brief Pack a wingsail_actuator message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param target_sail  Position of the target sail
 * @param sail_angle_type  Type of angle specified
 * @param sail_angle [deg] Angle of the sail
 * @param flap_active  Bitmask of active flap values
 * @param flap_angle  Flap position/command values. Unused fields are set to zero
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wingsail_actuator_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t target_sail, uint8_t sail_angle_type, float sail_angle, uint8_t flap_active, const float *flap_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN];
    _mav_put_float(buf, 0, sail_angle);
    _mav_put_uint8_t(buf, 36, target_system);
    _mav_put_uint8_t(buf, 37, target_component);
    _mav_put_uint8_t(buf, 38, target_sail);
    _mav_put_uint8_t(buf, 39, sail_angle_type);
    _mav_put_uint8_t(buf, 40, flap_active);
    _mav_put_float_array(buf, 4, flap_angle, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN);
#else
    mavlink_wingsail_actuator_t packet;
    packet.sail_angle = sail_angle;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.target_sail = target_sail;
    packet.sail_angle_type = sail_angle_type;
    packet.flap_active = flap_active;
    mav_array_memcpy(packet.flap_angle, flap_angle, sizeof(float)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WINGSAIL_ACTUATOR;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_MIN_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_CRC);
}

/**
 * @brief Pack a wingsail_actuator message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param target_sail  Position of the target sail
 * @param sail_angle_type  Type of angle specified
 * @param sail_angle [deg] Angle of the sail
 * @param flap_active  Bitmask of active flap values
 * @param flap_angle  Flap position/command values. Unused fields are set to zero
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wingsail_actuator_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t target_sail,uint8_t sail_angle_type,float sail_angle,uint8_t flap_active,const float *flap_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN];
    _mav_put_float(buf, 0, sail_angle);
    _mav_put_uint8_t(buf, 36, target_system);
    _mav_put_uint8_t(buf, 37, target_component);
    _mav_put_uint8_t(buf, 38, target_sail);
    _mav_put_uint8_t(buf, 39, sail_angle_type);
    _mav_put_uint8_t(buf, 40, flap_active);
    _mav_put_float_array(buf, 4, flap_angle, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN);
#else
    mavlink_wingsail_actuator_t packet;
    packet.sail_angle = sail_angle;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.target_sail = target_sail;
    packet.sail_angle_type = sail_angle_type;
    packet.flap_active = flap_active;
    mav_array_memcpy(packet.flap_angle, flap_angle, sizeof(float)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WINGSAIL_ACTUATOR;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_MIN_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_CRC);
}

/**
 * @brief Encode a wingsail_actuator struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wingsail_actuator C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wingsail_actuator_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wingsail_actuator_t* wingsail_actuator)
{
    return mavlink_msg_wingsail_actuator_pack(system_id, component_id, msg, wingsail_actuator->target_system, wingsail_actuator->target_component, wingsail_actuator->target_sail, wingsail_actuator->sail_angle_type, wingsail_actuator->sail_angle, wingsail_actuator->flap_active, wingsail_actuator->flap_angle);
}

/**
 * @brief Encode a wingsail_actuator struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wingsail_actuator C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wingsail_actuator_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wingsail_actuator_t* wingsail_actuator)
{
    return mavlink_msg_wingsail_actuator_pack_chan(system_id, component_id, chan, msg, wingsail_actuator->target_system, wingsail_actuator->target_component, wingsail_actuator->target_sail, wingsail_actuator->sail_angle_type, wingsail_actuator->sail_angle, wingsail_actuator->flap_active, wingsail_actuator->flap_angle);
}

/**
 * @brief Send a wingsail_actuator message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param target_sail  Position of the target sail
 * @param sail_angle_type  Type of angle specified
 * @param sail_angle [deg] Angle of the sail
 * @param flap_active  Bitmask of active flap values
 * @param flap_angle  Flap position/command values. Unused fields are set to zero
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wingsail_actuator_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t target_sail, uint8_t sail_angle_type, float sail_angle, uint8_t flap_active, const float *flap_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN];
    _mav_put_float(buf, 0, sail_angle);
    _mav_put_uint8_t(buf, 36, target_system);
    _mav_put_uint8_t(buf, 37, target_component);
    _mav_put_uint8_t(buf, 38, target_sail);
    _mav_put_uint8_t(buf, 39, sail_angle_type);
    _mav_put_uint8_t(buf, 40, flap_active);
    _mav_put_float_array(buf, 4, flap_angle, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR, buf, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_MIN_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_CRC);
#else
    mavlink_wingsail_actuator_t packet;
    packet.sail_angle = sail_angle;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.target_sail = target_sail;
    packet.sail_angle_type = sail_angle_type;
    packet.flap_active = flap_active;
    mav_array_memcpy(packet.flap_angle, flap_angle, sizeof(float)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR, (const char *)&packet, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_MIN_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_CRC);
#endif
}

/**
 * @brief Send a wingsail_actuator message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wingsail_actuator_send_struct(mavlink_channel_t chan, const mavlink_wingsail_actuator_t* wingsail_actuator)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wingsail_actuator_send(chan, wingsail_actuator->target_system, wingsail_actuator->target_component, wingsail_actuator->target_sail, wingsail_actuator->sail_angle_type, wingsail_actuator->sail_angle, wingsail_actuator->flap_active, wingsail_actuator->flap_angle);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR, (const char *)wingsail_actuator, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_MIN_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_CRC);
#endif
}

#if MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wingsail_actuator_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t target_sail, uint8_t sail_angle_type, float sail_angle, uint8_t flap_active, const float *flap_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, sail_angle);
    _mav_put_uint8_t(buf, 36, target_system);
    _mav_put_uint8_t(buf, 37, target_component);
    _mav_put_uint8_t(buf, 38, target_sail);
    _mav_put_uint8_t(buf, 39, sail_angle_type);
    _mav_put_uint8_t(buf, 40, flap_active);
    _mav_put_float_array(buf, 4, flap_angle, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR, buf, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_MIN_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_CRC);
#else
    mavlink_wingsail_actuator_t *packet = (mavlink_wingsail_actuator_t *)msgbuf;
    packet->sail_angle = sail_angle;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->target_sail = target_sail;
    packet->sail_angle_type = sail_angle_type;
    packet->flap_active = flap_active;
    mav_array_memcpy(packet->flap_angle, flap_angle, sizeof(float)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR, (const char *)packet, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_MIN_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_CRC);
#endif
}
#endif

#endif

// MESSAGE WINGSAIL_ACTUATOR UNPACKING


/**
 * @brief Get field target_system from wingsail_actuator message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_wingsail_actuator_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field target_component from wingsail_actuator message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_wingsail_actuator_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  37);
}

/**
 * @brief Get field target_sail from wingsail_actuator message
 *
 * @return  Position of the target sail
 */
static inline uint8_t mavlink_msg_wingsail_actuator_get_target_sail(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  38);
}

/**
 * @brief Get field sail_angle_type from wingsail_actuator message
 *
 * @return  Type of angle specified
 */
static inline uint8_t mavlink_msg_wingsail_actuator_get_sail_angle_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  39);
}

/**
 * @brief Get field sail_angle from wingsail_actuator message
 *
 * @return [deg] Angle of the sail
 */
static inline float mavlink_msg_wingsail_actuator_get_sail_angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field flap_active from wingsail_actuator message
 *
 * @return  Bitmask of active flap values
 */
static inline uint8_t mavlink_msg_wingsail_actuator_get_flap_active(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Get field flap_angle from wingsail_actuator message
 *
 * @return  Flap position/command values. Unused fields are set to zero
 */
static inline uint16_t mavlink_msg_wingsail_actuator_get_flap_angle(const mavlink_message_t* msg, float *flap_angle)
{
    return _MAV_RETURN_float_array(msg, flap_angle, 8,  4);
}

/**
 * @brief Decode a wingsail_actuator message into a struct
 *
 * @param msg The message to decode
 * @param wingsail_actuator C-struct to decode the message contents into
 */
static inline void mavlink_msg_wingsail_actuator_decode(const mavlink_message_t* msg, mavlink_wingsail_actuator_t* wingsail_actuator)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wingsail_actuator->sail_angle = mavlink_msg_wingsail_actuator_get_sail_angle(msg);
    mavlink_msg_wingsail_actuator_get_flap_angle(msg, wingsail_actuator->flap_angle);
    wingsail_actuator->target_system = mavlink_msg_wingsail_actuator_get_target_system(msg);
    wingsail_actuator->target_component = mavlink_msg_wingsail_actuator_get_target_component(msg);
    wingsail_actuator->target_sail = mavlink_msg_wingsail_actuator_get_target_sail(msg);
    wingsail_actuator->sail_angle_type = mavlink_msg_wingsail_actuator_get_sail_angle_type(msg);
    wingsail_actuator->flap_active = mavlink_msg_wingsail_actuator_get_flap_active(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN? msg->len : MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN;
        memset(wingsail_actuator, 0, MAVLINK_MSG_ID_WINGSAIL_ACTUATOR_LEN);
    memcpy(wingsail_actuator, _MAV_PAYLOAD(msg), len);
#endif
}
