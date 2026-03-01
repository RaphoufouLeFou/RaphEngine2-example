#include <RaphEngine2/RaphEngine2.hpp>

#include <iostream>

int main()
{
    raphEngine::Core::Init();
    raphEngine::GameObject go{};
    go.greed();

    std::cout << "test\n";
    return 0;
}
