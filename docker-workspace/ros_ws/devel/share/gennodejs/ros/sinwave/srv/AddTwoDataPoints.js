// Auto-generated. Do not edit!

// (in-package sinwave.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let TimeSeriesPoint = require('../msg/TimeSeriesPoint.js');

//-----------------------------------------------------------


//-----------------------------------------------------------

class AddTwoDataPointsRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.a = null;
      this.b = null;
    }
    else {
      if (initObj.hasOwnProperty('a')) {
        this.a = initObj.a
      }
      else {
        this.a = new TimeSeriesPoint();
      }
      if (initObj.hasOwnProperty('b')) {
        this.b = initObj.b
      }
      else {
        this.b = new TimeSeriesPoint();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type AddTwoDataPointsRequest
    // Serialize message field [a]
    bufferOffset = TimeSeriesPoint.serialize(obj.a, buffer, bufferOffset);
    // Serialize message field [b]
    bufferOffset = TimeSeriesPoint.serialize(obj.b, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type AddTwoDataPointsRequest
    let len;
    let data = new AddTwoDataPointsRequest(null);
    // Deserialize message field [a]
    data.a = TimeSeriesPoint.deserialize(buffer, bufferOffset);
    // Deserialize message field [b]
    data.b = TimeSeriesPoint.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 32;
  }

  static datatype() {
    // Returns string type for a service object
    return 'sinwave/AddTwoDataPointsRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3c4eee4645daadd95e3d676865ad4520';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    TimeSeriesPoint a
    TimeSeriesPoint b
    
    ================================================================================
    MSG: sinwave/TimeSeriesPoint
    float64 value
    float64 timestamp
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new AddTwoDataPointsRequest(null);
    if (msg.a !== undefined) {
      resolved.a = TimeSeriesPoint.Resolve(msg.a)
    }
    else {
      resolved.a = new TimeSeriesPoint()
    }

    if (msg.b !== undefined) {
      resolved.b = TimeSeriesPoint.Resolve(msg.b)
    }
    else {
      resolved.b = new TimeSeriesPoint()
    }

    return resolved;
    }
};

class AddTwoDataPointsResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.sum = null;
    }
    else {
      if (initObj.hasOwnProperty('sum')) {
        this.sum = initObj.sum
      }
      else {
        this.sum = new TimeSeriesPoint();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type AddTwoDataPointsResponse
    // Serialize message field [sum]
    bufferOffset = TimeSeriesPoint.serialize(obj.sum, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type AddTwoDataPointsResponse
    let len;
    let data = new AddTwoDataPointsResponse(null);
    // Deserialize message field [sum]
    data.sum = TimeSeriesPoint.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a service object
    return 'sinwave/AddTwoDataPointsResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd71e72c52ec1917c6d171c3a0e0a3f1e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    TimeSeriesPoint sum
    
    
    ================================================================================
    MSG: sinwave/TimeSeriesPoint
    float64 value
    float64 timestamp
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new AddTwoDataPointsResponse(null);
    if (msg.sum !== undefined) {
      resolved.sum = TimeSeriesPoint.Resolve(msg.sum)
    }
    else {
      resolved.sum = new TimeSeriesPoint()
    }

    return resolved;
    }
};

module.exports = {
  Request: AddTwoDataPointsRequest,
  Response: AddTwoDataPointsResponse,
  md5sum() { return '90646d2d2f45747163c2b98b43301e86'; },
  datatype() { return 'sinwave/AddTwoDataPoints'; }
};
