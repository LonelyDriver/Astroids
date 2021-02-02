#include "block_game.h"
#include "block_exeption.h"
#include "logging_manager.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main() {
    Logger logger = LogManager::GetLogger("MAIN");
    try{
        block::Game game(Vector(300, 200), Vector(1080, 720));
        game.InitializeTextures();
        game.InitializeEntities();
        game.Run();
    }catch(const block::BlockException& e) {
        logger->Error(e.what());
    }

    return 0;
}