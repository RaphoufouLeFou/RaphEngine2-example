#include <RaphEngine2/RaphEngine2.hpp>
#include <RaphEngine2/component/camera_component.hpp>
#include <RaphEngine2/component/collider_component.hpp>
#include <RaphEngine2/component/light_component.hpp>
#include <RaphEngine2/component/mesh_component.hpp>
#include <RaphEngine2/logger/logger.hpp>
#include <glm/glm.hpp>
#include <initializer_list>

#include "Camera/camera.hpp"

using namespace raphEngine;
using namespace raphEngine::objects;

int main()
{
    Core::Init("RaphEngine2-example");

    // create a simple GameObject
    GameObject go{ "Map" };

    // add a new MeshComponent to it, to give it a 3d model.
    // If a single MeshInfo is given, there will be no Lods for this model

    if (false)
    {
        go.add_component<component::MeshComponent>(
              MeshInfo("assets/models/Plane.fbx"))
            ->cast_shadows = false;
    }
    else
    {
        const auto* c = go.add_component<component::MeshComponent>(
            MeshInfo("assets/models/map.fbx"));

        go.add_component<component::ColliderComponent>(*c);
    }
    go.greed();
    GameObject* light = new GameObject{ "Directional light" };

    auto lc = light->add_component<component::LightComponent>();
    lc->set_direction(glm::vec3(1));

    /*
    light->add_component<component::MeshComponent>(
        MeshInfo("assets/models/Ball.fbx"));
    light->get_transform().get_scale() = glm::vec3(0.1);
*/
    for (size_t i = 0; i < 2; i++)
    {
        GameObject* p = new GameObject{};

        auto lods = {
            MeshInfo("assets/models/Cube.fbx"),
        };

        const auto* c = p->add_component<component::MeshComponent>(lods);

        p->add_component<component::ColliderComponent>(*c);

        p->get_transform().get_position() = glm::vec3(0, (float)i, 0);
        p->get_transform().get_scale() = glm::vec3(0.1f + i);
        p->get_first_component_of_type<component::MeshComponent>()
            ->cast_shadows = true;

        p->get_transform().set_parent(&go.get_transform());
    }

    Camera camera{};

    Logger::LogInfo("test");

    Core::Run();
    return 0;
}
