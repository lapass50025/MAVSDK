#include "global_include.h"
#include "control_impl.h"
#include "dronelink_impl.h"
#include <unistd.h>

namespace dronelink {

ControlImpl::ControlImpl(DeviceImpl *parent) :
    _parent(parent)
{

}

ControlImpl::~ControlImpl()
{

}

Result ControlImpl::arm() const
{
    return _parent->send_command_with_ack(MAV_CMD_COMPONENT_ARM_DISARM,
                                          {1.0f, NAN, NAN, NAN, NAN, NAN, NAN});
}

Result ControlImpl::disarm() const
{
    return _parent->send_command_with_ack(MAV_CMD_COMPONENT_ARM_DISARM,
                                          {0.0f, NAN, NAN, NAN, NAN, NAN, NAN});
}

Result ControlImpl::takeoff() const
{
    return _parent->send_command_with_ack(MAV_CMD_NAV_TAKEOFF,
                                          {NAN, NAN, NAN, NAN, NAN, NAN, NAN});
}

Result ControlImpl::land() const
{
    return _parent->send_command_with_ack(MAV_CMD_NAV_LAND,

                                          {NAN, NAN, NAN, NAN, NAN, NAN, NAN});
}

} // namespace dronelink