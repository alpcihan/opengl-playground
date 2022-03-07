#pragma once

#include "core/shared.h"
#include "core/camera/Camera.h"

struct PerspectiveCameraProps
{
public:
    float fieldOfView;
    float aspectRatio;
    float nearClip;
    float farClip;

    PerspectiveCameraProps(float fieldOfView = 45.0, float aspectRatio = 1.0, float nearClip = 0.1, float farClip = 1000.0)
        : fieldOfView(fieldOfView), aspectRatio(aspectRatio), nearClip(nearClip), farClip(farClip) {}
};

class PerspectiveCamera : public Camera
{
public:
    PerspectiveCamera(const PerspectiveCameraProps &cameraProps = PerspectiveCameraProps());

    float getFieldOfView() const { return cameraProps.fieldOfView; }
    void setFieldOfView(float fieldOfView);
    float getAspectRatio() const { return cameraProps.aspectRatio; }
    void setAspectRatio(float aspectRatio);
    float getNearClip() const { return cameraProps.nearClip; }
    void setNearClip(float nearClip);
    float getFarClip() const { return cameraProps.farClip; }
    void setFarClip(float farClip);

private:
    PerspectiveCameraProps cameraProps;

private:
    void updateProjection();
};