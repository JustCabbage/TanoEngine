#include "TestGame.hpp"

int main(int argc, char* argv[])
{
    Tano::TestGame Instance({1280, 720}, "Tano: Test Game");
    return Instance.Start(argc, argv);
}