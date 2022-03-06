#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(const PerspectiveCameraProps &cameraProps)
    : cameraProps(cameraProps)
{
    updateProjection();
}

void PerspectiveCamera::setFieldOfView(float fieldOfView)
{
    cameraProps.fieldOfView = fieldOfView;
    updateProjection();
}

void PerspectiveCamera::setAspectRatio(float aspectRatio)
{
    cameraProps.aspectRatio = aspectRatio;
    updateProjection();
}

void PerspectiveCamera::setNearClip(float nearClip)
{
    cameraProps.nearClip = nearClip;
    updateProjection();
}

void PerspectiveCamera::setFarClip(float farClip)
{
     cameraProps.farClip = farClip; 
     updateProjection();
}

void PerspectiveCamera::updateProjection()
{
    projection = glm::perspective(
        cameraProps.fieldOfView,
        cameraProps.aspectRatio,
        cameraProps.nearClip,
        cameraProps.farClip);
}