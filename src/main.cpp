#include <RaphEngine2/RaphEngine2.hpp>

#include <RaphEngine2/component/mesh_component.hpp>
#include <RaphEngine2/component/camera_component.hpp>
#include <initializer_list>
#include <iostream>
#include <memory>

#include "Camera/camera.hpp"

using namespace raphEngine;
using namespace raphEngine::objects;

int main()
{
    Core::Init();
    GameObject go{};

    go.add_component(std::make_unique<component::MeshComponent>(MeshInfo("assets/models/map.fbx")));
    go.get_transform().get_scale() = glm::vec3(10);

    go.greed();

    for (size_t i = 0; i < 10; i++)
    {
        GameObject* p = new GameObject{};
        p->add_component(std::make_unique<component::MeshComponent>(MeshInfo("assets/models/Cube.fbx")));
        p->get_transform().get_position() = glm::vec3(0, i * 5, 0);
    }
    

    Camera camera {};

    std::cout << "test\n";

    Core::Run();
    return 0;
}
