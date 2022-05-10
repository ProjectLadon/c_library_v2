#pragma once
// MESSAGE WIND_DATA PACKING

#define MAVLINK_MSG_ID_WIND_DATA 44001


typedef struct __mavlink_wind_data_t {
 float speed; /*< [m/s] The speed of the wind, m/s*/
 float direction; /*< [deg] The direction of the wind, degrees clockwise from north*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t source_sail; /*<  If the wind instrument is mounted on wingsail, it's defined here*/
 uint8_t wind_type; /*<  Wind data type (apparent, true, or raw)*/
} mavlink_wind_data_t;

#define MAVLINK_MSG_ID_WIND_DATA_LEN 12
#define MAVLINK_MSG_ID_WIND_DATA_MIN_LEN 12
#define MAVLINK_MSG_ID_44001_LEN 12
#define MAVLINK_MSG_ID_44001_MIN_LEN 12

#define MAVLINK_MSG_ID_WIND_DATA_CRC 76
#define MAVLINK_MSG_ID_44001_CRC 76



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WIND_DATA { \
    44001, \
    "WIND_DATA", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wind_data_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wind_data_t, target_component) }, \
         { "source_sail", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_wind_data_t, source_sail) }, \
         { "wind_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_wind_data_t, wind_type) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wind_data_t, speed) }, \
         { "direction", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wind_data_t, direction) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WIND_DATA { \
    "WIND_DATA", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wind_data_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wind_data_t, target_component) }, \
         { "source_sail", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_wind_data_t, source_sail) }, \
         { "wind_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_wind_data_t, wind_type) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wind_data_t, speed) }, \
         { "direction", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wind_data_t, direction) }, \
         } \
}
#endif

/**
 * @brief Pack a wind_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param source_sail  If the wind instrument is mounted on wingsail, it's defined here
 * @param wind_type  Wind data type (apparent, true, or raw)
 * @param speed [m/s] The speed of the wind, m/s
 * @param direction [deg] The direction of the wind, degrees clockwise from north
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wind_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t source_sail, uint8_t wind_type, float speed, float direction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIND_DATA_LEN];
    _mav_put_float(buf, 0, speed);
    _mav_put_float(buf, 4, direction);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, source_sail);
    _mav_put_uint8_t(buf, 11, wind_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIND_DATA_LEN);
#else
    mavlink_wind_data_t packet;
    packet.speed = speed;
    packet.direction = direction;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.source_sail = source_sail;
    packet.wind_type = wind_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIND_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIND_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIND_DATA_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_LEN, MAVLINK_MSG_ID_WIND_DATA_CRC);
}

/**
 * @brief Pack a wind_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param source_sail  If the wind instrument is mounted on wingsail, it's defined here
 * @param wind_type  Wind data type (apparent, true, or raw)
 * @param speed [m/s] The speed of the wind, m/s
 * @param direction [deg] The direction of the wind, degrees clockwise from north
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wind_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t source_sail,uint8_t wind_type,float speed,float direction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIND_DATA_LEN];
    _mav_put_float(buf, 0, speed);
    _mav_put_float(buf, 4, direction);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, source_sail);
    _mav_put_uint8_t(buf, 11, wind_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIND_DATA_LEN);
#else
    mavlink_wind_data_t packet;
    packet.speed = speed;
    packet.direction = direction;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.source_sail = source_sail;
    packet.wind_type = wind_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIND_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIND_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIND_DATA_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_LEN, MAVLINK_MSG_ID_WIND_DATA_CRC);
}

/**
 * @brief Encode a wind_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wind_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wind_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wind_data_t* wind_data)
{
    return mavlink_msg_wind_data_pack(system_id, component_id, msg, wind_data->target_system, wind_data->target_component, wind_data->source_sail, wind_data->wind_type, wind_data->speed, wind_data->direction);
}

/**
 * @brief Encode a wind_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wind_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wind_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wind_data_t* wind_data)
{
    return mavlink_msg_wind_data_pack_chan(system_id, component_id, chan, msg, wind_data->target_system, wind_data->target_component, wind_data->source_sail, wind_data->wind_type, wind_data->speed, wind_data->direction);
}

/**
 * @brief Send a wind_data message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param source_sail  If the wind instrument is mounted on wingsail, it's defined here
 * @param wind_type  Wind data type (apparent, true, or raw)
 * @param speed [m/s] The speed of the wind, m/s
 * @param direction [deg] The direction of the wind, degrees clockwise from north
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wind_data_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t source_sail, uint8_t wind_type, float speed, float direction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIND_DATA_LEN];
    _mav_put_float(buf, 0, speed);
    _mav_put_float(buf, 4, direction);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, source_sail);
    _mav_put_uint8_t(buf, 11, wind_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND_DATA, buf, MAVLINK_MSG_ID_WIND_DATA_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_LEN, MAVLINK_MSG_ID_WIND_DATA_CRC);
#else
    mavlink_wind_data_t packet;
    packet.speed = speed;
    packet.direction = direction;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.source_sail = source_sail;
    packet.wind_type = wind_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND_DATA, (const char *)&packet, MAVLINK_MSG_ID_WIND_DATA_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_LEN, MAVLINK_MSG_ID_WIND_DATA_CRC);
#endif
}

/**
 * @brief Send a wind_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wind_data_send_struct(mavlink_channel_t chan, const mavlink_wind_data_t* wind_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wind_data_send(chan, wind_data->target_system, wind_data->target_component, wind_data->source_sail, wind_data->wind_type, wind_data->speed, wind_data->direction);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND_DATA, (const char *)wind_data, MAVLINK_MSG_ID_WIND_DATA_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_LEN, MAVLINK_MSG_ID_WIND_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_WIND_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wind_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t source_sail, uint8_t wind_type, float speed, float direction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, speed);
    _mav_put_float(buf, 4, direction);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, source_sail);
    _mav_put_uint8_t(buf, 11, wind_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND_DATA, buf, MAVLINK_MSG_ID_WIND_DATA_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_LEN, MAVLINK_MSG_ID_WIND_DATA_CRC);
#else
    mavlink_wind_data_t *packet = (mavlink_wind_data_t *)msgbuf;
    packet->speed = speed;
    packet->direction = direction;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->source_sail = source_sail;
    packet->wind_type = wind_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND_DATA, (const char *)packet, MAVLINK_MSG_ID_WIND_DATA_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_LEN, MAVLINK_MSG_ID_WIND_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE WIND_DATA UNPACKING


/**
 * @brief Get field target_system from wind_data message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_wind_data_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field target_component from wind_data message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_wind_data_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field source_sail from wind_data message
 *
 * @return  If the wind instrument is mounted on wingsail, it's defined here
 */
static inline uint8_t mavlink_msg_wind_data_get_source_sail(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field wind_type from wind_data message
 *
 * @return  Wind data type (apparent, true, or raw)
 */
static inline uint8_t mavlink_msg_wind_data_get_wind_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field speed from wind_data message
 *
 * @return [m/s] The speed of the wind, m/s
 */
static inline float mavlink_msg_wind_data_get_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field direction from wind_data message
 *
 * @return [deg] The direction of the wind, degrees clockwise from north
 */
static inline float mavlink_msg_wind_data_get_direction(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a wind_data message into a struct
 *
 * @param msg The message to decode
 * @param wind_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_wind_data_decode(const mavlink_message_t* msg, mavlink_wind_data_t* wind_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wind_data->speed = mavlink_msg_wind_data_get_speed(msg);
    wind_data->direction = mavlink_msg_wind_data_get_direction(msg);
    wind_data->target_system = mavlink_msg_wind_data_get_target_system(msg);
    wind_data->target_component = mavlink_msg_wind_data_get_target_component(msg);
    wind_data->source_sail = mavlink_msg_wind_data_get_source_sail(msg);
    wind_data->wind_type = mavlink_msg_wind_data_get_wind_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WIND_DATA_LEN? msg->len : MAVLINK_MSG_ID_WIND_DATA_LEN;
        memset(wind_data, 0, MAVLINK_MSG_ID_WIND_DATA_LEN);
    memcpy(wind_data, _MAV_PAYLOAD(msg), len);
#endif
}
