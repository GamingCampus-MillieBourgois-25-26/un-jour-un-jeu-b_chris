#include "Engine.h"
#include "SceneModule.h"

#include "Clicker/ClickerLevel.h"
#include "BulletHell/BulletHellLevel.h"

int main(const int _argc, const char** _argv)
{
    Engine* const engine = Engine::GetInstance();

    engine->Init(_argc, _argv);

    engine->GetModuleManager()->GetModule<SceneModule>()->SetScene<BulletHell::BulletHellLevel>();

    engine->Run();

    return 0;
}
