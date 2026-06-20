#include <RaphEngine2/RaphEngine2.hpp>

#include <RaphEngine2/component/mesh_component.hpp>
#include <RaphEngine2/objects/mesh_info.hpp>
#include <initializer_list>
#include <iostream>
#include <memory>

int main()
{
    raphEngine::Core::Init();
    raphEngine::objects::GameObject go{};



    go.add_component(std::make_unique<raphEngine::component::MeshComponent>(raphEngine::objects::MeshInfo("assets/models/cube.fbx")));
    go.greed();

    std::cout << "test\n";

    raphEngine::Core::Run();
    return 0;
}
