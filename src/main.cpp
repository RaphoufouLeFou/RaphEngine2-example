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

    go.add_component(std::make_unique<component::MeshComponent>(MeshInfo("assets/models/cube.fbx")));
    go.greed();

    Camera camera {};

    std::cout << "test\n";

    Core::Run();
    return 0;
}
