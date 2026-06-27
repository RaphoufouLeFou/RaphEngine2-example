#include <RaphEngine2/RaphEngine2.hpp>
#include <RaphEngine2/component/camera_component.hpp>
#include <RaphEngine2/component/mesh_component.hpp>
#include <RaphEngine2/logger/logger.hpp>
#include <initializer_list>
#include <iostream>
#include <memory>

#include "Camera/camera.hpp"

using namespace raphEngine;
using namespace raphEngine::objects;

int main()
{
    Core::Init("RaphEngine2-example");

    // create a simple GameObject
    GameObject go{};

    // add a new MeshComponent to it, to give it a 3d model.
    // If a single MeshInfo is given, there will be no Lods for this model

    if (0)
    {
        go.add_component<component::MeshComponent>(
            MeshInfo("assets/models/Plane.fbx"));
        go.get_first_component_of_type<component::MeshComponent>()
            ->cast_shadows = false;
    }
    else
    {
        go.add_component<component::MeshComponent>(
            MeshInfo("assets/models/map.fbx"));
    }
    go.greed();
    GameObject* light = new GameObject{};

    /*
        light->add_component<component::MeshComponent>(
            MeshInfo("assets/models/Ball.fbx", false));
    */
    light->get_transform().get_position() = glm::vec3(1 * 10, 1 * 10, 1 * 10);
    light->get_transform().get_scale() = glm::vec3(0.1);

    for (size_t i = 0; i < 10; i++)
    {
        GameObject* p = new GameObject{};

        auto lods = {
            MeshInfo("assets/models/Cube.fbx"),
        };

        p->add_component<component::MeshComponent>(lods);

        p->get_transform().get_position() = glm::vec3(0, (float)i / 10.0, 1);
        p->get_transform().get_scale() = glm::vec3(0.01);
        p->get_first_component_of_type<component::MeshComponent>()
            ->cast_shadows = true;
    }

    Camera camera{};

    Logger::LogInfo("test");

    Core::Run();
    return 0;
}
